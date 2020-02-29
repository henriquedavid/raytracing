#include "./lib/tinyxml2/tinyxml2.h"
#include "./lib/tinyxml2/tinyxml2.cpp"
#include "./include/paramset.h"
#include <string.h>
#include <memory>
#include <algorithm>

using namespace tinyxml2;

int main()
{
    /*
    {
        // Testing the paramset
        std::cout << "TESTING PARAMSET" << std::endl;

        ParamSet ps;
        int valor [1] = {200};
        std::string nome = "motor";
        size_t size_ = 1;
        
        std::cout << "ERR1\n";
        auto valor11 = std::unique_ptr<int []>(valor);
        std::cout << "ERR2\n";
        auto v = ps.add<int>(nome, std::move(valor11), size_);
        std::cout << "ERR3\n";
        std::cout << v << std::endl;


        std::cout << "END\n";

        return 0;
    }
*/
    {
        /* Testing the read of XML file */

        XMLDocument doc;
        doc.LoadFile("test.xml");

        // Verificando se ocorreu algum erro ao abrir.
        if (!doc.ErrorID())
        {

            XMLElement *attr = doc.FirstChildElement();
            //attr = attr->FirstChildElement();

            // Interar sobre os componentes.
            for (XMLElement *e = attr->FirstChildElement(); e != NULL; e = e->NextSiblingElement())
            {
                const char *tag = e->Value();

                std::cout << tag << std::endl;

                // Compara cada tipo possível
                if (strcmp(tag, "camera") == 0)
                {
                    ParamSet ps;
                    // Read each attribs from XML
                    for (auto att = e->FirstAttribute(); att != NULL; att = att->Next())
                    {


                        // Get the value of the attribute that are being interated
                        /*std::string v_ = att->Value();
                         
                        // Inform the number of elements that it's going to be in the array.
                        int size_element = 1;

                        // Create the vector
                        auto item_insert = make_unique<std::string []>(1);
                        // Copy item to the vector                         
                        item_insert[1] = v_;

                        // Get the key of attribute
                        string key_ = att->Name();
                        
                        //Add element to the ParamSet
                        //auto a_ = ps.add<std::string>(key_, std::move(item_insert), 0);
                        std::cout<< "E3\n"; */
                    }

                    //API::camera(ps);

                    //ps.print();
                }
                else if (strcmp(tag, "film") == 0)
                {
                    for (auto att = e->FirstAttribute(); att != NULL; att = att->Next())
                    {

                        std::cout << " -- " << att->Name() << " = " << att->Value() << std::endl;
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