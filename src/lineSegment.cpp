//
// Created by George Weis on 27/02/2025.
//

#include <limits>

#include "point.h"
#include "line.h"
#include "lineSegment.h"



// Constructor initializes the base class (line) and sets p1
lineSegment::lineSegment(const point& p0In, const point& n_lIn, const double& lengthIn)
    : line(p0In, n_lIn), length(lengthIn) {} // Compute direction

// Destructor
lineSegment::~lineSegment() {}

double lineSegment::get_length() const {return length;}

point lineSegment::end_point() const{return p0 + n_l*length;}
point lineSegment::midpoint() const {return p0 + n_l*(length/2.0);}

void lineSegment::print() const
{
    std::cout<<"p0 ";
    p0.print();
    std::cout<<"n_l ";
    n_l.print();
    std::cout<<"length = "<<length<<std::endl;
}

double lineSegment::change_in_x() const {return (n_l*length).get_x();}
double lineSegment::change_in_y() const {return (n_l*length).get_y();}
double lineSegment::change_in_z() const {return (n_l*length).get_z();}


// Functions with arguments

double lineSegment::calc_intersect_param(const plane& plane_0) const {
    /*calculates the intersection parameter of a line segment intersect a plane.
       ie. P_intersect = P0 + n*l ---> returns l
     If it doesn't intersect, returns max possible double value as inf*/

    double nl_dot_np = n_l.dot_product(plane_0.get_normal()) ;

    if (std::fabs(nl_dot_np)<1e-6) {
        // intersects if dot prod!=0
        return std::numeric_limits<double>::max();
    }


    point p_p = plane_0.get_point_on_plane(); //the "anchor" point of the plane
    point n_p = plane_0.get_normal(); // normal of plane
    double num = (p_p - p0).dot_product(n_p);
    double den = nl_dot_np;
    double length_at_intersect = num/den;

    if (std::signbit(length) != std::signbit(length_at_intersect)
        || length<length_at_intersect) {
        //returns max double value if line points in the wrong direction to intersect or
        //if it is not long enough to intersect plane
        return std::numeric_limits<double>::max();
    }

    return length_at_intersect;

}

point lineSegment::intersect(const plane& plane_0) const
{
    double length_at_intersect = calc_intersect_param(plane_0);
    point point_of_intersect = p0+(n_l*length_at_intersect);

    return point_of_intersect;
}

bool lineSegment::does_intersect(const plane& plane_0) const
{
    double intersect_param = calc_intersect_param(plane_0);
    return (intersect_param != std::numeric_limits<double>::max());

}

bool lineSegment::does_intersect(const triangle& tri) const
{
    // Getting the normal of the triangle and creating the plane of the triangle
    point tri_normal = tri.normal();
    plane tri_plane = plane(tri_normal, tri.get_p0());  // Create the plane

    // Checking if the line segment intersects with the plane of the triangle
    if (does_intersect(tri_plane) == false) {
        return false;  // If it doesn't intersect with the plane, return false
    }

    // Finding the point of intersection with the plane
    point intersection = intersect(tri_plane);

    // Computing the barycentric coordinates
    point A = tri.get_p0();
    point B = tri.get_p1();
    point C = tri.get_p2();

    point v0 = C - A;
    point v1 = B - A;
    point v2 = intersection - A;

    double d00 = v0.dot_product(v0);
    double d01 = v0.dot_product(v1);
    double d11 = v1.dot_product(v1);
    double d20 = v2.dot_product(v0);
    double d21 = v2.dot_product(v1);

    double denom = d00 * d11 - d01 * d01;
    double u = (d11 * d20 - d01 * d21) / denom;
    double v = (d00 * d21 - d01 * d20) / denom;
    double w = 1.0 - u - v;

    // Checking if the point is inside the triangle (barycentric coordinates in the range [0, 1])
    double epsilon = -1e-10;  // Small tolerance to avoid floating point issues
    if ((u >= epsilon && u <= 1) && (v >= epsilon && v <= 1) && (w >= epsilon && w <= 1))
    {
        // The intersection point lies inside the triangle
        return true;
    }

    // The intersection point is outside the triangle
    return false;
}




