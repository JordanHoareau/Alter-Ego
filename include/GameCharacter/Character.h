#ifndef CHARACTER_H
#define CHARACTER_H

#include <iostream>

using namespace std;

class Character
{
    public:
        Character();
        Character(string);
        virtual ~Character();

    protected:

    private:
        string m_name;
};

#endif // CHARACTER_H
