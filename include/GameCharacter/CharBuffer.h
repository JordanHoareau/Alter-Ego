#ifndef CHARBUFFER_H
#define CHARBUFFER_H

#include "Character.h"
#include <vector>
using namespace std;

class CharBuffer
{
    public:
        CharBuffer();
    protected:
    private:
        vector<Character> m_chars;
};

#endif // CHARBUFFER_H
