//point script 
/*
to run on Georges:
/opt/homebrew/bin/g++-11 -std=c++17 -fdiagnostics-color=always -g pointScript.cpp  point.cpp -o pointScript.o

To run on Pablo's: /usr/local/bin/g++-11 -std=c++17 -fdiagnostics-color=always -g pointScript.cpp point.cpp -o pointScript.o

*/
#include<iostream>
#include "point.h"



int main()
{
  point p0;
  point p1 = point(1.0, -1.0, 5);
  point p2 = point (1.5, 3.5, 3.4);


  p0.print();
  p1.print();
  p2.print();

  std::cout << "Point p1 distance to origin is " << std::to_string(p1.distance_to_origin()) << std::endl;

  std::cout << "Distance from p1 to p0: " << p0.distance_to(p1) << std::endl;

  std::cout << "Distance from p2 to p1: " << p1.distance_to(p2) << std::endl;

  auto [r, theta, phi] = p1.cartesian_to_spherical();

  std::cout << "Spherical coordinates: \n";
    std::cout << "Radius (r): " << r << "\n";
    std::cout << "Inclination (theta, radians): " << theta << "\n";
    std::cout << "Azimuth (phi, radians): " << phi << std::endl;


std::vector<double> vec = p1.components();

std::cout << "(" << vec[0] << ", " << vec[1] << ", " << vec[2] << ")\n";


point vector_p1_p2 = p1.vector_to(p2);
std::cout<<"Vector from p1->p2:"<<std::endl;
vector_p1_p2.print();

std::cout << "Dot Product: " << p1.dot_product(p2) << std::endl;

  
point cross = p1.cross_product(p2);
cross.print();


}




