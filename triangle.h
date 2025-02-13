// triangle class
#ifndef TRIANGLE_H
#define TRIANGLE_H


#include<iostream>
#include<string>
#include<cmath>

#include "point.h"

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



// Functions
  void print() const;
  point centroid();
  double area();
  std::vector<double> normal();
};

#endif //TRIANGLE_H