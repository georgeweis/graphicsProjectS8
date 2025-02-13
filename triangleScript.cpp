//triangle script 
/*
run on Georges: 
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

  triangle t3 = triangle(point(1,0,0), point(0,1,0), point(0,0,1));

  //printing coordinates of vertices
  t1.print();
  t2.print();

  //testing the centroid function
  point p_cent = t2.centroid();

  //printing coordinates of the centroid point of 
  std::cout<<"\nCentroid of t2:"<<std::endl;
  for (int i=0; i<3; i++)
  {
    std::cout<<"p_cent.coords()["<<i<<"]: "<<p_cent.components()[i]<<std::endl;
  }

  std::cout<<"\np0.distance_to(p1): "<< p0.distance_to(p1)<<std::endl;

  std::cout<<"\nt2.area(): "<< t2.area()<<std::endl;

  point t2_surface_normal = t2.surface_normal();
  std::cout<<"\nt2.surface_normal(): "<<std::endl;
  t2_surface_normal.print();
  point t3_surface_normal = t3.surface_normal();
  std::cout<<"t3.surface_normal(): "<<std::endl;
  t3_surface_normal.print();


  
}


