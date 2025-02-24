#include "cuboid.h"
#include <iostream>

cuboid::cuboid() {
    // Define points
    point p1(0.0, 0.0, 0.0);
    point p2(1.0, 0.0, 0.0);
    point p3(1.0, 0.0, 1.0);
    point p4(0.0, 0.0, 1.0);
    point p5(0.0, 2.0, 0.0);
    point p6(1.0, 2.0, 0.0);
    point p7(0.0, 2.0, 1.0);
    point p8(1.0, 2.0, 1.0);

    // Define triangles
    // Face 1 (square at origin)
    triangles.push_back(triangle(p1, p2, p3)); // t1
    triangles.push_back(triangle(p1, p3, p4)); // t2

    // Face 2 (square at y=2)
    triangles.push_back(triangle(p5, p6, p7)); // t3
    triangles.push_back(triangle(p6, p7, p8)); // t4

    // Face 3 (rectangle face at z=0)
    triangles.push_back(triangle(p1, p2, p6)); // t5
    triangles.push_back(triangle(p1, p5, p6)); // t6

    // Face 4 (rectangle face at x=0)
    triangles.push_back(triangle(p1, p4, p5)); // t7
    triangles.push_back(triangle(p4, p5, p7)); // t8

    // Face 5 (rectangle face at z=1)
    triangles.push_back(triangle(p3, p4, p8)); // t9
    triangles.push_back(triangle(p3, p7, p8)); // t10

    // Face 6 (rectangle face at x=1)
    triangles.push_back(triangle(p2, p3, p6)); // t11
    triangles.push_back(triangle(p3, p6, p8)); // t12
}


std::vector<triangle> cuboid::get_triangles() const {
    return triangles;
}
// Method to print all triangles
void cuboid::print_triangles() const {
    for (size_t i = 0; i < triangles.size(); ++i) {
        std::cout << "Triangle " << i + 1 << ":\n";
        triangles[i].print();
        std::cout << "\n";
    }
}