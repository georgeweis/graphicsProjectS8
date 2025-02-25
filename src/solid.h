// 

#ifndef SOLID_H
#define SOLID_H
#include "point.h"
#include "triangle.h"

class point;

class solid
{

private:
    std::vector<triangle> triangles;  

public:

    solid() = default ;

    solid(std::vector<triangle>);

    void print_triangles() const;
    // TODO
    // bool is_inside(const point& p) const;

};

#endif