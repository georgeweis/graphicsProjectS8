//line class funciton definitions

#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>

#include "line.h"
#include "point.h"


// Parameterized constructor
line::line(const point& p0In, const point& nIn, const double& lIn )
  : p0{p0In}, n{nIn.make_normal()}, l{lIn} {}


// Destructor
line::~line(){} 



// Funcitons without arguments
point line::get_p0() const {return p0;}
point line::get_n() const {return n;}
double line::get_l() const {return l;}

point line::end_point() const
{
  return p0 + n*l;
}
point line::midpoint() const {return p0 + n*(l/2.0);}

void line::print() const
{
  std::cout<<"p0 ";
  p0.print();
  std::cout<<"n ";
  n.print();
  std::cout<<"l = "<<l<<std::endl;
}

double line::change_in_x() const {return (n*l).get_x();}
double line::change_in_y() const {return (n*l).get_y();}
double line::change_in_z() const {return (n*l).get_z();}






// Functions with arguments

bool line::is_parallel(const line& other_line) const
{
  return n.is_equal_within_tolerance(other_line.get_n());
}

bool line::includes_point(const point& p) const
{
  if (p0.is_equal_within_tolerance(p))
  {
    return true; // no need for further calc if p0=p
  }


  point v = p0.vector_to(p); //vector from p0 to point p
  point v_norm = v.make_normal();
  if (n.is_equal_within_tolerance(v_norm) 
      && v.magnitude()<=l)
  {
    //only enter if v is parallel to line normal and if
    //magnitude is smaller than length of the line
    return true;
  }
  return false;
}

  bool line::intersects_plane(const plane& plane_)
  {
    //checks if normals are the same
    return n.is_equal_within_tolerance(plane_.get_normal());
  }

  point line::point_of_intersection(const plane& plane_)
  {
    point n_l = n;
    point n_p = plane_.get_normal();
    point p_f = plane_.get_point_on_plane();

    double lam = (p_f - p0).dot_product(n_p);

    point p_intersection = n_l*lam +p0;
    return p_intersection;
  }
