
#ifndef LINE_H
#define LINE_H


#include<iostream>
#include<string>
#include<cmath>

#include "point.h"
#include "plane.h"


class plane;  // Forward declaration of plane class
class triangle;

class line
{
private:
  point p0 ; //starting point
  point n_l ; // normalised direction

public:

  // Default constructor
  line() = default ;
  // Parameterized constructor
  line(const point& p0In, const point& nIn ) ;

  // Destructor
  ~line();



  // Functions without arguments
  point get_p0() const;
  point get_n_l() const;

  void print() const;

  

  // Functions with arguments
  bool is_parallel(const line& other_line) const;
  bool includes_point(const point& p) const;
  bool does_intersect(const plane& plane_0) const;
  point intersect(const plane& plane_0) const;
  bool does_intersect(const triangle& tri) const;



  /*
  bool intersects(const other);
  bool is_parallel(const other);
  bool is_perpendiclar(const line& other); //allow precision
  point intersects_plane(const pane& plane); //add after plane class 

  */



};




#endif //LINE_H