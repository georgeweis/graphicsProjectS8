#include "solid.h"
#include "triangle.h"
#include "line.h"
#include <iostream>
#include <fstream>
#include <sstream>

solid::solid(std::vector<triangle> triangles) : triangles(triangles) {}

solid solid::load_stl(const std::string& filename) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr << "Error: Unable to open STL file: " << filename << std::endl;
        return solid();  // Return an empty solid
    }

    std::string line;
    std::vector<triangle> triangles;
    std::vector<point> vertices;

    // Read the file line by line
    while (std::getline(file, line)) {
        std::stringstream ss(line);
        std::string keyword;
        ss >> keyword;

        if (keyword == "facet") {
            // Skip the normal line (as we're not using the normal anymore)
            std::string dummy;
            double nx, ny, nz;
            ss >> dummy >> nx >> ny >> nz;
        } else if (keyword == "vertex") {
            double x, y, z;
            ss >> x >> y >> z;
            vertices.push_back(point(x, y, z));

            // Once we have 3 vertices, create a triangle and reset vertices
            if (vertices.size() == 3) {
                triangles.emplace_back(vertices[0], vertices[1], vertices[2]);
                vertices.clear();  // Reset for next triangle
            }
        }
    }

    file.close();
    return solid(triangles);  // Return the solid with the loaded triangles
}


bool solid::is_inside(const point& p) const {
  int intersection_count = 0;

  // Define a ray along the +X direction
  point ray_direction(1, 0, 0);  // A unit vector along X
  line ray(p, ray_direction, 1000.0);  // Long ray to ensure it exits the solid

  // Count intersections with triangles
  for (const auto& tri : triangles) {
      if (ray.intersects_with_triangle(tri)) {
          intersection_count++;
      }
  }

  return (intersection_count % 2 == 1);  // Odd: inside, Even: outside
}

void solid::print_triangles() const {
    std::cout << "Printing triangles for the solid:\n";
    for (size_t i = 0; i < triangles.size(); ++i) {
        std::cout << "Triangle " << i + 1 << ":\n";
        triangles[i].print();
        std::cout << "\n";
    }
}

void solid::print_triangle_areas() const {
    std::cout << "Printing areas of all triangles in the solid:\n";
    for (size_t i = 0; i < triangles.size(); ++i) {
        std::cout << "Triangle " << i + 1 << " area: " << triangles[i].area() << "\n";
    }
}