// plane header
#ifndef PLANE_H
#define PLANE_H

#include "point.h"
#include <vector>
#include <iostream>

class plane
{
private:

    point normal;  
    point point_on_plane;

public:
 
    plane() = default;
    plane(const point& normal, const point& point_on_plane);

    ~plane();

    point get_normal() const;

    point get_point_on_plane() const;

    double distance_to_point(const point& p) const;  

    void print_equation() const;

     bool point_lies_on_plane(const point& p, double tolerance = 1e-6) const;


};

#endif

