// 

#ifndef SOLID_H
#define SOLID_H
#include "point.h"
#include "triangle.h"

class solid
{


public:

    solid() = default ;

    solid(std::vector<triangle>);

};

#endif