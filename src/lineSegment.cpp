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






