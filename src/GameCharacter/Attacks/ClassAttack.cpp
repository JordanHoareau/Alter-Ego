#include "GameCharacter/Attacks/ClassAttack.h"
#include <fstream>
#include <string>
#include <JSonParser/json-forwards.h>
#include <JSonParser/json.h>

ClassAttack::ClassAttack(int classID)
{
    Json::Value root;
    Json::Reader reader;

    std::ifstream classattack_file("data\\Attacks\\ClassAttack.json", std::ifstream::binary);

    bool parsingSuccessful = reader.parse( classattack_file, root );
    if ( !parsingSuccessful )
    {
        std::cout  << "Failed to parse configuration\n"
                   << reader.getFormattedErrorMessages();
        return;
    }

    const Json::Value classattack_node = root["attacks"];
    for(int i = 0; i < classattack_node.size() ; ++i ){
          if(classattack_node[i]["m_classID"].asInt() == classID) std::cout << classattack_node[i];
    }


}

ClassAttack::~ClassAttack()
{
}
