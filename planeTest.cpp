//point script 
/*
to run on Georges:
/opt/homebrew/bin/g++-11 -std=c++17 -fdiagnostics-color=always -g planeScript.cpp plane.cpp point.cpp -o planeScript.o

To run on Pablo's: /usr/local/bin/g++-11 -std=c++17 -fdiagnostics-color=always -g pointScript.cpp point.cpp -o pointScript.o

*/
#include<iostream>
#include "point.h"
#include "plane.h"



int main()
{
  point p0;
  point p1 = point(1.0, -1.0, 5);
  point p2 = point (1.5, 3.5, 3.4);

// plane stuff
point normal(1, 2, 3);
point p5(1, 0, 0);  // A point on the plane
plane pl(normal, p5);
pl.print_equation();
pl.print_plane_equation();

point p6(3, 2, 1);
double distance = pl.distance_to_point(p6);
std::cout << "Distance from test point (3,2,1) to plane: " << distance << std::endl;

point p7(2, -1, 1.0/3);
if (pl.point_lies_on_plane(p7)) {
        std::cout << "Point p2 lies on the plane." << std::endl;
    } else {
        std::cout << "Point p2 does NOT lie on the plane." << std::endl;
    }


}
