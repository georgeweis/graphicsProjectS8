#include <iostream>
#include <cmath>

#include "triangle.h"

// Constructor
triangle::triangle(const point& pt0, const point& pt1, const point& pt2)
  : p0(pt0), p1(pt1), p2(pt2) {}


// Desrtuctor
triangle::~triangle(){} 



//functions without arguments
point triangle::get_p0() const {return p0;} 
point triangle::get_p1() const {return p1;} 
point triangle::get_p2() const {return p2;} 


void triangle::print() const
{
  std::cout << "Triangle vertices:\n";
  p0.print();
  p1.print();
  p2.print();
}

point triangle::centroid() const
{
  double x_cent = (p0.components()[0] + p1.components()[0] + p2.components()[0])/3;
  double y_cent = (p0.components()[1] + p1.components()[1] + p2.components()[1])/3;
  double z_cent = (p0.components()[2] + p1.components()[2] + p2.components()[2])/3;

  point pCentroid = point(x_cent, y_cent, z_cent);

  return pCentroid;
}

double triangle::area() const
{
  double a = p0.distance_to(p1);
  double b = p0.distance_to(p2);
  double c = p1.distance_to(p2);

  double s = (a+b+c)/2;

  double area = std::sqrt(s*(s-a)*(s-b)*(s-c));

  return area;
}

point triangle::normal() const
{
  point a = p0.vector_to(p1);
  point b = p0.vector_to(p2);
  point cross = a.cross_product(b);
  cross.normalise();
  return cross;
}


bool triangle::is_valid() const {return area()>1e-10;}

bool triangle::does_intersect(const line& l) const
{
  // getting plane of the triangle
  plane tri_plane = plane(normal() , p0); // create a plane

  // checking if line and plane intersect
  if (l.does_intersect(tri_plane) == false) {return false;}

  //finding point of intersection with plane
  point intersection = l.intersect(tri_plane);

  // computing barycentric coordinates
  point A = p0;
  point B = p1;
  point C = p2;

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








// Functions with arguments



