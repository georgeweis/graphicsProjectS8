// point.cpp

#include <iostream>
#include <cmath>
#include <tuple>
#include "point.h"
#include <vector>


// Parameterized constructor:
point::point(const double& xIn, const double& yIn, const double& zIn)
  : x{xIn}, y{yIn}, z{zIn} {}


// Destructor:
point::~point()
{
  // std::cout<<"Destroying point"<<std::endl;
} 


// Functions without arguments:
void point::print () const
{
  std::cout.precision(3); // 2 significant figures
  std::cout<<"Coordinates: [x,y,z] = ["<<x<<","<< y<<","<<z<<"]"<<std::endl;
  return;
}

double point::distance_to_origin()
{
  double magnitude_squared = x*x + y*y + z*z;
    double distance_to_origin = std::sqrt(magnitude_squared);
  return distance_to_origin;
}

std::tuple<double, double, double> point::cartesian_to_spherical() const {
    double r = std::sqrt(x * x + y * y + z * z);
    double theta = (r != 0) ? std::acos(z / r) : 0; // Avoid division by zero
    double phi = std::atan2(y, x);

    return std::make_tuple(r, theta, phi);
}

std::vector<double> point::coords() const {
    return {this->x, this->y, this->z};  // Accessing member variables directly
}





// Functions with arguments
double point::distance_to(const point& other) const {
  double dx = x - other.x;
  double dy = y - other.y;
  double dz = z - other.z;
  return std::sqrt(dx * dx + dy * dy + dz * dz);
}

std::vector<double> point::vector_to(const point& other)
{
  double dx = other.x - x;
  double dy = other.y - y;
  double dz = other.z - z;

  std::vector<double> vec_to;
  vec_to.push_back(dx);
  vec_to.push_back(dy);
  vec_to.push_back(dz);

  return vec_to;

}

bool same_point(const point& other)
{
  //update this when we get clarification from stewart. 
  return false;
}

double point::dot_product(const point& other) const{
  return x * other.x + y * other.y + z * other.z;
}

point point::cross_product(const point& other) const {
  double cross_x = y * other.z - z * other.y;
  double cross_y = z * other.x - x * other.z;
  double cross_z = x * other.y - y * other.x;
  return point(cross_x, cross_y, cross_z);
}