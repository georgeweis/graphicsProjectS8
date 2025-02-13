// point class
#ifndef POINT_H
#define POINT_H
#include <tuple>
#include<iostream>
#include<string>
#include <vector>

class point
{
private:
  double x ;
  double y ;
  double z ;
  
public:

// Default constructor
  point() = default;
// Parameterized constructor
  point(const double& xIn, const double& yIn, const double& zIn);
    
// Destructor
  ~point();

  void print() const;


// Functions without arguments 
  double distance_to_origin();
  std::tuple<double, double, double> cartesian_to_spherical() const;
  std::vector<double> coords() const;

// Functions with arguments
  double distance_to(const point& other) const;
  std::vector<double> vector_to(const point& other);
  bool same_point(const point& other);
  
  double dot_product(const point& other) const;

  point cross_product(const point& other) const;

};





#endif //POINT_H