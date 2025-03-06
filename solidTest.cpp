#include "square_based_pyramid.h"
#include "point.h"
#include "solid.h"
#include "triangle.h"

int main() {
    point p1(0, 0, 0);
    point p2(1, 0, 0);
    point p3(1, 1, 0);
    point p4(0, 1, 0);
    point apex(0.5, 0.5, 1);

    square_based_pyramid pyramid(p1, p2, p3, p4, apex);
    std::vector<point> base_points = pyramid.get_base_points();

    std::cout << "Base points of the pyramid:\n";
    for (const auto& pt : base_points) {
        pt.print();
    }

    point apex_of_pyramid = pyramid.get_apex_point();
    std::cout << "Apex point of the pyramid: ";
    apex_of_pyramid.print();
    std::cout << std::endl;

    double area = pyramid.surface_area();
    std::cout << "\nSurface area of the pyramid: " << area << std::endl;

    std::string filename = "liver.stl";

    solid liver = solid::load_stl("liver.stl");
    solid heart = solid::load_stl("heart.stl");

    if (heart.get_triangles().empty()) {
        std::cerr << "Error: No triangles loaded. Check the STL file or loading function." << std::endl;
        return 1;
    }

    std::vector<triangle> heart_triangles = heart.get_triangles();
    /*std::cout << "\nTriangles in the heart solid:\n";
    for (const auto& t : heart_triangles) {
        t.print();
    }*/

    // Generate and output CSV statistics
    std::string csv_output = heart.triangle_statistics_csv();
    /*std::cout << csv_output;*/

    heart.export_triangle_statistics_csv("heart_triangles.csv");

    std::cout << "Volume of the heart: " << heart.volume() << " cubic units" << std::endl;
    std::cout << "SA of the heart: " << heart.surface_area() << " square units" << std::endl;
    std::cout << "Volume of the liver: " << liver.volume() << " cubic units" << std::endl;
    std::cout << "SA of the liver: " << liver.surface_area() << " square units" << std::endl;

    point test_point(0.0001, 0.0001, 0.0001);  // Choose a point for testing

    if (heart.is_inside(test_point)) {
        std::cout << "The point is inside the heart." << std::endl;
    } else {
        std::cout << "The point is outside the heart." << std::endl;
    }

    // You can also test with the liver solid if needed
    if (liver.is_inside(test_point)) {
        std::cout << "The point is inside the liver." << std::endl;
    } else {
        std::cout << "The point is outside the liver." << std::endl;
    }



    point p5(0, 0, 0);
    point p6(1, 0, 0);
    point p7(0, 1, 0);
    point p8(0, 0, 1);

    // Manually defining the triangles of the tetrahedron
    std::vector<triangle> tetrahedron_triangles = {
        triangle(p5, p6, p7),
        triangle(p5, p6, p8),
        triangle(p5, p7, p8),
        triangle(p6, p7, p8)
    };

    // Create the solid
    solid tetrahedron(tetrahedron_triangles);

    // Define a point to test if it is inside the solid
    point test_point2(0.25, 0.25, 0.25);  // This point is inside the tetrahedron

    // Check if the test point is inside the solid
    if (tetrahedron.is_inside(test_point2)) {
        std::cout << "The point is inside the tetrahedron." << std::endl;
    } else {
        std::cout << "The point is outside the tetrahedron." << std::endl;
    }

    // Define another point outside the solid
    point test_point_outside(1.5, 1.5, 1.5);

    // Check if the test point is inside the solid
    if (tetrahedron.is_inside(test_point_outside)) {
        std::cout << "The point is inside the tetrahedron." << std::endl;
    } else {
        std::cout << "The point is outside the tetrahedron." << std::endl;
    }

    return 0;
}
