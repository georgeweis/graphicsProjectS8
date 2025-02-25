#include "solid.h"
#include "triangle.h"
#include "line.h"
#include <iostream>

solid::solid(std::vector<triangle> triangles) : triangles(triangles) {}


void solid::print_triangles() const {
  std::cout << "Printing triangles for the solid:\n";
  for (size_t i = 0; i < triangles.size(); ++i) {
    std::cout << "Triangle " << i + 1 << ":\n";
    triangles[i].print();
    std::cout << "\n";
  }
}

// bool solid::is_inside(const point& p) const {
//   int intersection_count = 0;
//
//   // Define a ray along the +X direction
//   point ray_direction(1, 0, 0);  // A unit vector along X
//   line ray(p, ray_direction, 1000.0);  // Long ray to ensure it exits the solid
//
//   // Count intersections with triangles
//   for (const auto& tri : triangles) {
//       if (ray.intersects_with_triangle(tri)) {
//           intersection_count++;
//       }
//   }
//
//   return (intersection_count % 2 == 1);  // Odd: inside, Even: outside
// }

