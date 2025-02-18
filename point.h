// point class

#ifndef POINT_H
#define POINT_H
#include <tuple>
#include <iostream>
#include <string>
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




// Functions without arguments 

  void print() const;

  double get_x() const;
  double get_y() const;
  double get_z() const;

  double magnitude() const;
  std::tuple<double, double, double> cartesian_to_spherical() const;
  std::vector<double> components() const;
  point normalise() const;
  void normalise();

  
  // Functions with arguments

  static double default_epsilon;
  bool is_equal_within_tolerance(const point& other, double epsilon = 1e-6) const;

  static void set_default_tolerance(double new_epsilon); // Static function to set default tolerance


  double distance_to(const point& other) const;
  point vector_to(const point& other);

  double dot_product(const point& other) const;

  point cross_product(const point& other) const;

  double angle_between_vecs_rads(const point& other) const;

  point operator+(const point& other) const;



};





#endif //POINT_H