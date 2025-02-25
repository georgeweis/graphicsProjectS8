//line class funciton definitions

#include <iostream>
#include <cmath>
#include <vector>

#include "line.h"
#include "point.h"
#include "plane.h"
#include "triangle.h"


// Parameterized constructor
line::line(const point& p0In, const point& nIn)
  : p0{p0In}, n_l{nIn.make_normal()} {}


// Destructor
line::~line(){} 



// Funcitons without arguments
point line::get_p0() const {return p0;}
point line::get_n_l() const {return n_l;}



void line::print() const
{
  std::cout<<"p0 ";
  p0.print();
  std::cout<<"n_l ";
  n_l.print();
}




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
  return n_l.is_equal_within_tolerance(v_norm);
}

  bool line::does_intersect(const plane& plane_0) const
  {
    double nl_dot_np = n_l.dot_product(plane_0.get_normal()) ;
    return std::fabs(nl_dot_np)>1e-6; // intersects if dot prod!=0
  }

  point line::intersect(const plane& plane_0) const
  {
    point p_p = plane_0.get_point_on_plane(); //the "anchor" point of the plane
    point n_p = plane_0.get_normal(); // normal of plane
    double denom = (p_p - p0).dot_product(n_p); 
    double numerator = n_l.dot_product(n_p);
    double length_at_intersec = denom/numerator;
    point point_of_intersec = p0+(n_l*length_at_intersec);
    return point_of_intersec;
  }


bool line::does_intersect(const triangle& tri) const
{
  // getting plane of the triangle
  point tri_normal = tri.normal();
  plane tri_plane = plane(tri_normal , tri.get_p0()); // create a plane

  // checking if line and plane intersect
  if (does_intersect(tri_plane) == false) {return false;}

  //finding point of intersection with plane
  point intersection = intersect(tri_plane);

  // computing barycentric coordinates
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

  //checking if the point is inside the triangle
  double epsilon = -1e-10;
  if ((u >= epsilon && u <= 1) && (v >= epsilon && v <= 1) && (w >= epsilon && w <= 1))
    {
    return true;
  }
  return false;

}
