#include "./lib/tinyxml2/tinyxml2.h"
#include "./lib/tinyxml2/tinyxml2.cpp"
#include "./include/paramset.h"
#include <string.h>

using namespace tinyxml2;

int main()
{

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

                    ParamSet<std::string, std::string> ps("Camera");
                    // Read each attribs from XML
                    for( auto att = e->FirstAttribute(); att != NULL; att = att->Next()){
                        printf("%s = %s\n", att->Name(), att->Value());
                        ps.add(att->Name(), att->Value());                        
                    }

                    ps.print();


                    //printf("%s = %s\n", e->FirstAttribute()->Name(),e->FirstAttribute()->Value());

                    
                    //printf("Atributo = %s\n", e->FirstAttribute()->Next()->Value());
                    //ps.add()

                    printf("É uma camera\n");
                }
            }
        
            return doc.ErrorID();
        } else{
            printf("Erro!\n");
        }

    }

    {
        /* Testing the paramset */
        std::cout << "TESTING PARAMSET" << std::endl;

        ParamSet<std::string, std::string> ps("Carro");
        ps.add("motor", "200");
        ps.add("v_max", "300");
        ps.add("v_min", "50");
        ps.print();
    }
    
}