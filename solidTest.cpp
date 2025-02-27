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



    return 0;
}
