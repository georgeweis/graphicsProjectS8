#include "solid.h"
#include "triangle.h"
#include <iostream>

solid::solid(std::vector<triangle> triangles) : triangles(triangles) {}


void solid::print_triangles() const 
{
    std::cout << "Printing triangles for the solid:\n";
    for (size_t i = 0; i < triangles.size(); ++i) {
        std::cout << "Triangle " << i + 1 << ":\n";
        triangles[i].print();
        std::cout << "\n";
    }
}

