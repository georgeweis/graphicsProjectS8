// square based pyramid . h

#ifndef SQUARE_BASED_PYRAMID_H
#define SQUARE_BASED_PYRAMID_H
#include "point.h"
#include "triangle.h"


#include <iostream>
#include <cmath>

class  square_based_pyramid {

    private:

    point base[4];
    point apex;
    std::vector<triangle> faces;
    
    public:

    square_based_pyramid(const point& b1, const point& b2, const point& b3, const point& b4, const point& top);

    std::vector<point> get_base_points() const;

    point get_apex_point() const;

    std::vector<triangle> split_base() const; 

    ~square_based_pyramid(); 

    double surface_area() const;
};

#endif