#include "./lib/tinyxml2/tinyxml2.h"
#include "./lib/tinyxml2/tinyxml2.cpp"
#include "./include/paramset.h"
#include <string.h>
#include <memory>
#include <algorithm>

using namespace tinyxml2;

int main()
{
    {
        /* Testing the read of XML file */

        XMLDocument doc;
        doc.LoadFile("test.xml");

        // Verift if there isn't no mistake in open file.
        if (!doc.ErrorID())
        {

            XMLElement *attr = doc.FirstChildElement();
            //attr = attr->FirstChildElement();

            // Interate over all components/tags.
            for (XMLElement *e = attr->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
            {
                const char *tag = e->Value();

                // Compare each possible type
                if (strcmp(tag, "camera") == 0)
                {
                    ParamSet ps;
                    // Read each attribs from XML
                    for (auto att = e->FirstAttribute(); att != NULL; att = att->Next())
                    {
                        // Get the value of the attribute that are being interated
                        std::string v_ = att->Value();
                        // Get the key of attribute
                        std::string key_ = att->Name();
                         
                        // Inform the number of elements that it's going to be in the array.
                        int size_elements = 1;

                        // Create the vector
                        auto item_insert = make_unique<std::string []>(size_elements);
                        
                        // Copy item to the vector
                        item_insert[0] = v_;
                        
                        //Add element to the ParamSet
                        ps.add<std::string>(key_, std::move(item_insert), 0);

                        std::string retorno = ps.find_one<std::string>(key_, "ort");
                        std::cout << retorno << std::endl;
                    }

                    //API::camera(ps);

                    //ps.print();
                }
                else if (strcmp(tag, "film") == 0)
                {
                    for (auto att = e->FirstAttribute(); att != NULL; att = att->Next())
                    {

                    }
                } else if(strcmp(tag, "world_begin") == 0){
                    // 
                    /*
                     *   -> GENERATE WORLD
                     * 
                     *   Realizando esse laço faz com que caso o cliente queira mudar algumas configurações 
                     *   após a criação ele pode depois que criar o mundo.
                     */
                    for (auto attr_world = e; strcmp(tag, "world_end") != 0; attr_world = attr_world->NextSiblingElement()){
                        tag = attr_world->Value();

                        // Evitar inconsistência de dados.
                        e = attr_world;

                    }
                }
            }

            return doc.ErrorID();
        }
        else
        {
            printf("Erro!\n");
        }
    }
}