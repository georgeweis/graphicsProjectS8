//line class funciton definitions

#include <iostream>
#include <cmath>
#include <tuple>
#include <vector>

#include "line.h"
#include "point.h"


// Parameterized constructor:
line::line(const point& p0In, const point& nIn, const double& lIn )
  : p0{p0In}, n{nIn.normalise()}, l{lIn} {}


// Destructor:
line::~line(){} 



// Funcitons without arguments
point line::get_p0() const {return p0;}
point line::get_n() const {return n;}
double line::get_l() const {return l;}

point line::end_point() const
{
  return p0 + n*l;
}

void line::print() const
{
  std::cout<<"p0";
  p0.print();
  std::cout<<"n";
  n.print();
  std::cout<<"l = "<<l<<std::endl;
}

double line::change_in_x() const {return (n*l).get_x();}
double line::change_in_y() const {return (n*l).get_y();}
double line::change_in_z() const {return (n*l).get_z();}





// Functions with arguments 

