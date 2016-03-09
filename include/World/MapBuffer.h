#ifndef MAPBUFFER_H
#define MAPBUFFER_H

#include "Map.h"
#include <vector>
using namespace std;

class MapBuffer
{
    public:
        MapBuffer();
    protected:
    private:
        vector<Map> myMaps;
};

#endif // MAPBUFFER_H
