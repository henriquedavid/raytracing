#include "../../lib/tinyxml2/tinyxml2.h"
#include "../../lib/tinyxml2/tinyxml2.cpp"
#include "../paramset/paramset.h"
#include "../RTH/rth.h"
#include "../vec3/vec3.h"
#include "../vec3/vec4.h"
#include "../support.cpp"
#include <string.h>
#include <tuple>
#include <memory>
#include <algorithm>

using namespace tinyxml2;
using namespace std;
using Point = vec3f;

Camera createCamera(const ParamSet &ps, const ParamSet &lookat)
{

    string type = ps.find_one<string>("type", "orthographic");

    vec3f look_from(lookat.find_one<string>("look_from", "0 0 0"));
    vec3f look_at(lookat.find_one<string>("look_at", "0 0 0"));
    vec3f up(lookat.find_one<string>("up", "0 0 0"));

    vec3f gaze = look_at - look_from;

    vec3f w = normalize(gaze); // left-hand orientation

    //vec3f up_v = up * w;
    vec3f u = normalize(cross(up,w));

    //vec3f w_u = w * u;
    vec3f v = normalize(cross(w,u));
    Point e = look_from;

    string screen_window = ps.find_one<string>("screen_window", "-5.3 5.3 -4 4");

    if (type != "perspective")
    {

        OrthographicCamera c;
        c.screen_window = screen_window;
        c.type = type;
        c.w = w;
        c.u = u;
        c.v = v;
        c.e = e;

        return c;
    }
    else
    {
        float fovy = ps.find_one<float>("fovy", 30.0);

        PerspectiveCamera c_perspective{fovy};
        c_perspective.type = type;
        c_perspective.w = w;
        c_perspective.u = u;
        c_perspective.v = v;
        c_perspective.e = e;

        return c_perspective;
    }
}

Film createFilm(const ParamSet &ps)
{
    string type = ps.find_one<string>("type", "image");
    int x_res = ps.find_one<int>("x_res", 500);
    int y_res = ps.find_one<int>("y_res", 500);
    string filename = ps.find_one<string>("filename", "out.ppm");
    string img_type = ps.find_one<string>("img_type", "ppm");
    string crop_window = ps.find_one<string>("crop_window", "0 1 0 1");
    string gamma_corrected = ps.find_one<string>("gamma_corrected", "yes");

    Film film(type, x_res, y_res, filename, img_type, crop_window, gamma_corrected);
    return film;
}

Background createBackground(const ParamSet &ps)
{

    string type = ps.find_one<string>("type", "colors");
    string mapping = ps.find_one<string>("mapping", "scree");
    string filename = ps.find_one<string>("filename", "none");
    string color = ps.find_one<string>("color", "0 0 0");
    string bl = ps.find_one<string>("bl", "0 0 0");
    string br = ps.find_one<string>("br", "0 0 0");
    string tl = ps.find_one<string>("tl", "0 0 0");
    string tr = ps.find_one<string>("tr", "0 0 0");
    auto image = getPNGImage(ps.find_one<string>("filename", "play.png"));

    vector<vector<vec3>> image_new;
    int cont = 0;

    for (int i = 0; i < get<2>(image); i++)
    {
        vector<vec3> img_y;
        for (int j = 0; j < get<1>(image); j++)
        {
            img_y.push_back(vec3(to_string(int(get<0>(image)[cont])) + " " + to_string(int(get<0>(image)[cont + 1])) + " " + to_string(int(get<0>(image)[cont + 2]))));
            cont += 4;
        }
        image_new.push_back(img_y);
    }

    Background bg(type, vec3(color), vec3(bl), vec3(br), vec3(tl), vec3(tr), image_new, get<1>(image), get<2>(image));
    return bg;
}

void parse(RTH &rth, char *input_file)
{
    XMLDocument doc;
    doc.LoadFile(input_file);

    ParamSet lookat;

    // Verift if there isn't no mistake in open file.
    if (!doc.ErrorID())
    {

        XMLElement *attr = doc.FirstChildElement();

        // Interate over all components/tags.
        for (XMLElement *e = attr->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
        {
            const char *tag = e->Value();

            // Compare all tags

            // The lookat tag needs to come before the camera's tag
            if (strcmp(tag, "lookat") == 0)
            {
                // Read each attribs from XML
                for (auto att = e->FirstAttribute(); att != NULL; att = att->Next())
                {

                    // Note that all of the 3 attributes use the same form, so it does't need condiction
                    // Get the key of attribute
                    std::string key_ = att->Name();

                    // Inform the number of elements that it's going to be in the array.
                    // This variable is not being used in the essence of the code.
                    int size_elements = 1;

                    // Get the value of the attribute that are being interated
                    std::string v_ = att->Value();
                    // Create the vector
                    auto item_insert = make_unique<std::string[]>(size_elements);

                    // Copy item to the vector
                    item_insert[0] = v_;

                    //Add element to the ParamSet
                    lookat.add<std::string>(key_, std::move(item_insert), 0);
                }
            }
            else if (strcmp(tag, "camera") == 0)
            {
                ParamSet ps;
                // Read each attribs from XML
                for (auto att = e->FirstAttribute(); att != NULL; att = att->Next())
                {
                    // Get the key of attribute
                    std::string key_ = att->Name();

                    // Inform the number of elements that it's going to be in the array.
                    int size_elements = 1;

                    if (key_ == "fovy")
                    {
                        // Get the value of the attribute that are being interated
                        int v_ = att->IntValue();

                        // Create the vector
                        auto item_insert = make_unique<int[]>(size_elements);

                        // Copy item to the vector
                        item_insert[0] = v_;

                        //Add element to the ParamSet
                        ps.add<int>(key_, std::move(item_insert), 0);
                    }
                    else
                    {
                        // Get the value of the attribute that are being interated
                        std::string v_ = att->Value();
                        // Create the vector
                        auto item_insert = make_unique<std::string[]>(size_elements);

                        // Copy item to the vector
                        item_insert[0] = v_;

                        //Add element to the ParamSet
                        ps.add<std::string>(key_, std::move(item_insert), 0);
                    }
                }

                rth.configureCamera(createCamera(ps, lookat));
            }
            else if (strcmp(tag, "film") == 0)
            {
                ParamSet ps;
                for (auto att = e->FirstAttribute(); att != NULL; att = att->Next())
                {
                    // Get the key of attribute
                    std::string key_ = att->Name();

                    // Inform the number of elements that it's going to be in the array.
                    int size_elements = 1;

                    if (key_ == "x_res" || key_ == "y_res")
                    {
                        // Get the value of the attribute that are being interated
                        int v_ = att->IntValue();

                        // Create the vector
                        auto item_insert = make_unique<int[]>(size_elements);

                        // Copy item to the vector
                        item_insert[0] = v_;

                        //Add element to the ParamSet
                        ps.add<int>(key_, std::move(item_insert), 0);
                    }
                    else
                    {
                        // Get the value of the attribute that are being interated
                        std::string v_ = att->Value();
                        // Create the vector
                        auto item_insert = make_unique<std::string[]>(size_elements);

                        // Copy item to the vector
                        item_insert[0] = v_;

                        //Add element to the ParamSet
                        ps.add<std::string>(key_, std::move(item_insert), 0);
                    }
                }

                rth.configureFilm(createFilm(ps));
            }
            else if (strcmp(tag, "world_begin") == 0)
            {
                //
                /*
                     *   -> GENERATE WORLD
                     * 
                     *   Realizando esse laço faz com que caso o cliente queira mudar algumas configurações 
                     *   após a criação ele pode depois que criar o mundo.
                     */
                for (auto attr_world = e; strcmp(tag, "world_end") != 0; attr_world = attr_world->NextSiblingElement())
                {
                    tag = attr_world->Value();

                    // Evitar inconsistência de dados.
                    e = attr_world;

                    if (strcmp(tag, "background") == 0)
                    {
                        ParamSet ps;
                        for (auto att = e->FirstAttribute(); att != NULL; att = att->Next())
                        {
                            // Get the key of attribute
                            std::string key_ = att->Name();

                            // Inform the number of elements that it's going to be in the array.
                            int size_elements = 1;

                            // Get the value of the attribute that are being interated
                            std::string v_ = att->Value();
                            // Create the vector
                            auto item_insert = make_unique<std::string[]>(size_elements);

                            // Copy item to the vector
                            item_insert[0] = v_;

                            //Add element to the ParamSet
                            ps.add<std::string>(key_, std::move(item_insert), 0);
                        }

                        rth.configureBackground(createBackground(ps));
                    }
                }
            }
        }
    }
    else
    {
        printf("Erro!\n");
    }
}