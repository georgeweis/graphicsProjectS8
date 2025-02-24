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


// Functions with arguments



