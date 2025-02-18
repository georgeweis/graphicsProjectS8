//point script 
/*
to run on Georges:
/opt/homebrew/bin/g++-11 -std=c++17 -fdiagnostics-color=always -g lineScript.cpp line.cpp point.cpp -o lineScript.o

To run on Pablo's: /usr/local/bin/g++-11 -std=c++17 -fdiagnostics-color=always -g pointScript.cpp point.cpp -o pointScript.o

*/
#include<iostream>
#include "point.h"
#include "line.h"

int main()
{
  point p0_1=point(1,0,0);
  point n_1=point(0,1,0);
  double l_1=5;

  line line1 = line(p0_1, n_1, l_1);
  line line2 = line(point(1,1,0), point(0,1,0.0000001), 2);

  std::cout<<"line1.print(): "<<std::endl;
  line1.print();

  std::cout<<"change in xyz for line1: ["<<line1.change_in_x()<<","
           <<line1.change_in_y()<< ","<<line1.change_in_z()<<"]"<<std::endl;


  std::cout<<"line1.is_parallel(line2): "<<line1.is_parallel(line2)<<std::endl;

  //point for includes_point check
  point point1 = point(-1,0,0);
  std::cout<<"line1.includes_point(point1): "<<line1.includes_point(point1)<<std::endl;

  //   //




}
