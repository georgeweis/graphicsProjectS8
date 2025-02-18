#include "square_based_pyramid.h"

// Constructor


square_based_pyramid::square_based_pyramid(const point& p1, const point& p2, const point& p3, const point& p4, const point& top)
    : base{p1, p2, p3, p4}, apex(top) {
    // Create the four triangular faces of the pyramid
    // use an iterator
    faces.push_back(triangle(base[0], base[1], apex));
    faces.push_back(triangle(base[1], base[2], apex));
    faces.push_back(triangle(base[2], base[3], apex));
    faces.push_back(triangle(base[3], base[0], apex));
}

// Destructor
square_based_pyramid::~square_based_pyramid() {

}


std::vector<point> square_based_pyramid::get_base_points() const {
    return {base[0], base[1], base[2], base[3]}; // Return the base points as a vector
}

point square_based_pyramid::get_apex_point() const {
    return apex;
}

std::vector<triangle> square_based_pyramid::split_base() const{
    triangle triangle_1(base[0], base[1], base[2]);
    triangle triangle_2(base[1], base[2], base[3]);
    return {triangle_1, triangle_2};
}

double square_based_pyramid::surface_area() const {

    std::vector<triangle> base_triangles = split_base();
    double base_area = base_triangles[0].area() + base_triangles[1].area();

    // Calculate side areas
    double side_area = 0.0;
    for (const auto& face : faces) {
        side_area += face.area();
    }

    return base_area + side_area;

}
