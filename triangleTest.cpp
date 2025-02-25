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

  point t2_surface_normal = t2.normal();
  std::cout<<"\nt2.surface_normal(): "<<std::endl;
  t2_surface_normal.print();
  point t3_surface_normal = t3.normal();
  std::cout<<"t3.surface_normal(): "<<std::endl;
  t3_surface_normal.print();

  std::cout<<"t2.is_valid(): "<<t2.is_valid()<<std::endl;



  //testing intersect function
  // defining triangle in xy plane
  point p0t = point(0,0,0);
  point p1t = point(1,1,2);
  point p2t = point(1,0,0);

  triangle t2t = triangle(p0t,p1t,p2t);

  // defining line in z direction
  point line_t_normal = point(0,0,-1);
  point line_t_point = point(0.5,0.05,2);
  line line_t = line(line_t_point, line_t_normal);


  std::cout<<"\nt2t.does_intersect(line_t): "<<t2t.does_intersect(line_t)<<std::endl;

  point t_intersection = t2t.intersect(line_t);
  std::cout<<"\nt2t.intersect(line_t): "<<std::endl;
  t_intersection.print();

  std::vector<double> sides = t2t.side_lengths_descending();

  std::cout << "Side lengths in descending order: ";
  for (double side : sides) {
    std::cout << side << " ";
  }
  std::cout << std::endl;

  
}


