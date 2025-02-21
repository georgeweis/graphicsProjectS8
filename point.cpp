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
  std::cout<<"components: [x,y,z] = ["<<x<<","<< y<<","<<z<<"]"<<std::endl;
  return;
}

double point::get_x() const {return x;}
double point::get_y() const {return y;}
double point::get_z() const {return z;}

double point::magnitude() const
{
  double magnitude_squared = x*x + y*y + z*z;
  double distance_to_origin = std::sqrt(magnitude_squared);
  return distance_to_origin;
}

std::tuple<double, double, double> point::to_spherical() const {
    double r = std::sqrt(x * x + y * y + z * z);
    double theta = (r != 0) ? std::acos(z / r) : 0; // Avoid division by zero
    double phi = std::atan2(y, x);

    return std::make_tuple(r, theta, phi);
}

std::vector<double> point::components() const {
    return {this->x, this->y, this->z};  // Accessing member variables directly
}

point point::make_normal() const
{
  // creates a new point (vector) which is normalised 
  double magnitude = std::sqrt(x*x + y*y + z*z);
  double x_norm = x/magnitude;
  double y_norm = y/magnitude;
  double z_norm = z/magnitude;
  point normalised_vector = point(x_norm, y_norm, z_norm);

  return normalised_vector;
}




void point::normalise()
{
  // normalises the point by changing member variables (no const)
  double magnitude = std::sqrt(x*x + y*y + z*z);
  if (magnitude != 0) { // Prevent division by zero
    x /= magnitude;
    y /= magnitude;
    z /= magnitude;
  }
}


// Functions with arguments

double point::default_epsilon = 1e-6; 

bool point::is_equal_within_tolerance(const point& other, double epsilon) const {
  if (epsilon == 0) {
    epsilon = default_epsilon; // Use default tolerance if epsilon is 0
  }
  return (std::fabs(x - other.x) < epsilon) &&
          (std::fabs(y - other.y) < epsilon) &&
          (std::fabs(z - other.z) < epsilon);
}

void point::set_default_tolerance(double new_epsilon) {
  default_epsilon = new_epsilon; // Set new default tolerance
}


double point::distance_to(const point& other) const {
  double dx = x - other.x;
  double dy = y - other.y;
  double dz = z - other.z;
  return std::sqrt(dx * dx + dy * dy + dz * dz);
}

point point::vector_to(const point& other) const
{
  double dx = other.x - x;
  double dy = other.y - y;
  double dz = other.z - z;

  point vec_to = point(dx, dy, dz);

  return vec_to;

}

double point::dot_product(const point& other) const
{
  return x * other.x + y * other.y + z * other.z;
}

point point::cross_product(const point& other) const 
{
  double cross_x = y * other.z - z * other.y;
  double cross_y = z * other.x - x * other.z;
  double cross_z = x * other.y - y * other.x;
  return point(cross_x, cross_y, cross_z);
}

double point::angle_between_vecs_rads(const point& other) const
{

  double dot_prod_ab = dot_product(other);
  double magnitude_a = magnitude();
  double magnitude_b = other.magnitude();
  double cos_theta = dot_prod_ab/(magnitude_a*magnitude_b);
  double angle = std::acos(cos_theta);
  return angle;
}

point point::operator+(const point& other) const
{
  point result(x + other.x, y + other.y, z+other.z);
  return result;

}

point point::operator*(const double& scalar) const
{
  point result(x*scalar, y*scalar, z*scalar);
  return result;
}

point point::operator-(const point& other) const
{
  point result = point(x-other.x, y-other.y, z-other.z);
  return result;
}
 