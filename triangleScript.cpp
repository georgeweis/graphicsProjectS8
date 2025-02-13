//triangle script 
/*
run: 
/opt/homebrew/bin/g++-11 -std=c++17 -fdiagnostics-color=always -g point.cpp triangleScript.cpp triangle.cpp -o triangleScript.o

*/
#include<iostream>
#include "point.h" 
#include "triangle.h" 



int main()
{
  //triangle with default constructor
  triangle t1;

  //triangle with initialised constructor, defines vertices as points first
  point p0 = point(0,0,0);
  point p1 = point(1,1,0);
  point p2 = point(1,0,0);

  triangle t2 = triangle(p0,p1,p2);

  //printing coordinates of vertices
  t1.print();
  t2.print();

  //testing the centroid function
  point p_cent = t2.centroid();

  //printing coordinates of the centroid point of 
  std::cout<<"Centroid of t2:"<<std::endl;
  for (int i=0; i<3; i++)
  {
    std::cout<<"p_cent.coords()["<<i<<"]: "<<p_cent.coords()[i]<<std::endl;
  }

  std::cout<<"p0.distance_to(p1)"<< p0.distance_to(p1)<<std::endl;


  std::cout<<"t2.area()"<< t2.area()<<std::endl;
}


