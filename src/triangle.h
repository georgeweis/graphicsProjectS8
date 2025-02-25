// triangle class
#ifndef TRIANGLE_H
#define TRIANGLE_H


#include<iostream>
#include<string>
#include<cmath>

#include "point.h"
#include "line.h"

class triangle
{
private:
  point p0 ;
  point p1 ;
  point p2 ;

public:

  // Default constructor
  triangle() = default ;
  // Parameterized constructor
  triangle(const point& p0In, const point& p1In, const point& p2In) ;

  // Destructor
  ~triangle();



  // Functions without arguments
  point get_p0() const;
  point get_p1() const;
  point get_p2() const;

  void print() const;
  point centroid() const;
  double area() const;
  point normal() const;
  bool is_valid() const;
  bool does_intersect(const line& l) const;
  point intersect(const line& l);

  std::vector<double> side_lengths_descending() const;
  // Functions with arguments



};




#endif //TRIANGLE_H