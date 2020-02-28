#include "./lib/tinyxml2/tinyxml2.h"
#include "./lib/tinyxml2/tinyxml2.cpp"
#include "./include/paramset.h"
#include <string.h>

using namespace tinyxml2;

int main()
{

    {
        /* Testing the paramset */
        std::cout << "TESTING PARAMSET" << std::endl;

        ParamSet<std::string, std::string> ps;
        ps.add("motor", "400");
        ps.add("v_max", "300");
        ps.add("v_min", "50");
        ps.print();
        auto v = ps.find<int>("motor", 200);
        //std::cout << typeid(v).name() << std::endl;
        //ps.print();

        return 0;
    }

    {
        /* Testing the read of XML file */
        
        XMLDocument doc;
        doc.LoadFile("test.xml");

        // Verificando se ocorreu algum erro ao abrir.
        if(!doc.ErrorID()){

            
            XMLElement* attr = doc.FirstChildElement()->FirstChildElement();
            //attr = attr->FirstChildElement();
            
            // Interar sobre os componentes.
            for(XMLElement* e = attr->FirstChildElement(); e != NULL; e = e->NextSiblingElement()){
                const char * tag = e->Value();
                
                // Compara cada tipo possível
                if(strcmp(tag,"camera") == 0){

                    ParamSet<std::string, std::string> ps;
                    // Read each attribs from XML
                    for( auto att = e->FirstAttribute(); att != NULL; att = att->Next()){
                        printf("%s = %s\n", att->Name(), att->Value());
                        ps.add(att->Name(), att->Value());                        
                    }

                    //API::camera(ps);

                    ps.print();

                }
            }
        
            return doc.ErrorID();
        } else{
            printf("Erro!\n");
        }

    }
    
}