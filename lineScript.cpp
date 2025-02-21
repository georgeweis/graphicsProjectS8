//point script 
/*
to run on Georges:
g++-11 -std=c++17 -fdiagnostics-color=always -g lineScript.cpp line.cpp point.cpp plane.cpp -o lineScript.o

To run on Pablo's: /usr/local/bin/g++-11 -std=c++17 -fdiagnostics-color=always -g pointScript.cpp point.cpp -o pointScript.o

*/ //
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

  //testing intersection with plane functions

  //define line
  point p0_3=point(0,0,-1);
  point n_3=point(0,0,1);
  double l_3=4;
  line line3 = line(p0_3, n_3, l_3);

  //define plane
  point n_plane1 = point(1,0,0); 
  point p_plane1 = point(0,0,0);
  plane plane1 = plane(n_plane1, p_plane1);
  std::cout<<"plane1"<<std::endl;

  //output
  std::cout<<"plane1 intersects with line3"<<std::endl;
  std::cout<<"line3.intersects_plane(plane1): "<<line3.intersects_plane(plane1)<<std::endl;
  std::cout<<"\nPoint of intersection of plane1 with line1:"<<std::endl;
  point line3_plane1_intersection = line3.point_of_intersection_with_plane(plane1);
  line3_plane1_intersection.print();


}
