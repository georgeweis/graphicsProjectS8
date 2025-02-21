//line class funciton definitions

#include <iostream>
#include <cmath>
#include <vector>

#include "line.h"
#include "point.h"
#include "plane.h"


// Parameterized constructor
line::line(const point& p0In, const point& nIn, const double& lIn )
  : p0{p0In}, n_l{nIn.make_normal()}, length{lIn} {}


// Destructor
line::~line(){} 



// Funcitons without arguments
point line::get_p0() const {return p0;}
point line::get_n_l() const {return n_l;}
double line::get_length() const {return length;}

point line::end_point() const
{
  return p0 + n_l*length;
}
point line::midpoint() const {return p0 + n_l*(length/2.0);}

void line::print() const
{
  std::cout<<"p0 ";
  p0.print();
  std::cout<<"n_l ";
  n_l.print();
  std::cout<<"length = "<<length<<std::endl;
}

double line::change_in_x() const {return (n_l*length).get_x();}
double line::change_in_y() const {return (n_l*length).get_y();}
double line::change_in_z() const {return (n_l*length).get_z();}






// Functions with arguments

bool line::is_parallel(const line& other_line) const
{
  return n_l.is_equal_within_tolerance(other_line.get_n_l());
}

bool line::includes_point(const point& p) const
{
  if (p0.is_equal_within_tolerance(p))
  {
    return true; // no need for further calc if p0=p
  }


  point v = p0.vector_to(p); //vector from p0 to point p
  point v_norm = v.make_normal();
  if (n_l.is_equal_within_tolerance(v_norm) 
      && v.magnitude()<=length)
  {
    //only enter if v is parallel to line normal and if
    //magnitude is smaller than length of the line
    return true;
  }
  return false;
}

  bool line::intersects_plane(const plane& plane_0) const
  {
    double nl_dot_np = n_l.dot_product(plane_0.get_normal()) ;
    return std::fabs(nl_dot_np)>1e-6; // intersects if dot prod!=0
  }

  point line::point_of_intersection_with_plane(const plane& plane_0) const
  {
    point p_p = plane_0.get_point_on_plane(); //the "anchor" point of the plane
    point n_p = plane_0.get_normal(); // normal of plane
    double denom = (p_p - p0).dot_product(n_p); 
    double numerator = n_l.dot_product(n_p);
    double length_at_intersec = denom/numerator;
    point point_of_intersec = p0+(n_l*length_at_intersec);
    return point_of_intersec;
  }
