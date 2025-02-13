#include <iostream>
#include <cmath>

#include "triangle.h"


triangle::triangle(const point& pt0, const point& pt1, const point& pt2)
  : p0(pt0), p1(pt1), p2(pt2) {}


triangle::~triangle()
{
  // std::cout<<"Destroying triangle"<<std::endl;
} 

void triangle::print() const
{
  std::cout << "Triangle vertices:\n";
  p0.print();
  p1.print();
  p2.print();
}

point triangle::centroid()
{
  double x_cent = (p0.coords()[0] + p1.coords()[0] + p2.coords()[0])/3;
  double y_cent = (p0.coords()[1] + p1.coords()[1] + p2.coords()[1])/3;
  double z_cent = (p0.coords()[2] + p1.coords()[2] + p2.coords()[2])/3;

  point pCentroid = point(x_cent, y_cent, z_cent);

  return pCentroid;
}

double triangle::area()
{
  double a = p0.distance_to(p1);
  double b = p0.distance_to(p2);
  double c = p1.distance_to(p2);

  double s = (a+b+c)/2;

  double area = std::sqrt(s*(s-a)*(s-b)*(s-c));

  return area;

}

std::vector<double> normal()
{
  
}

