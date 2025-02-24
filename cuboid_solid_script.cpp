//solid main to test cuboid

#include "point.h"
#include "cuboid.h"
#include "triangle.h"
#include "solid.h"

int main() {
    cuboid cuboid_1; // Create a cuboid object
    cuboid_1.print_triangles(); // Print all triangles in the cuboid

    solid cuboid_2(cuboid_1.get_triangles());  // Pass triangles to solid constructor
    cuboid_2.print_triangles();

}