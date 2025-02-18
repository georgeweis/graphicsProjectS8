// triangle class
#ifndef LINE_H
#define LINE_H


#include<iostream>
#include<string>
#include<cmath>

#include "point.h"

class line
{
private:
  point p0 ; //starting point
  point n ; // normalised direction 
  double l; //length

public:

  // Default constructor
  line() = default ;
  // Parameterized constructor
  line(const point& p0In, const point& nIn, const double& lIn ) ;

  // Destructor
  ~line();



  // Functions without arguments
  point get_p0() const;
  point get_n() const;
  double get_l() const;

  point end_point() const;
  point midpoint() const;
  void print() const;
  double change_in_x() const;
  double change_in_y() const;
  double change_in_z() const;

  

  // Functions with arguments
  bool is_parallel(const line& other_line) const;
  bool includes_point(const point& p) const;



  /*
  bool intersects(const other);
  bool is_parallel(const other);
  bool is_perpendiclar(const line& other); //allow precision
  point intersects_plane(const pane& plane); //add after plane class 



*/



};




#endif //LINE_H