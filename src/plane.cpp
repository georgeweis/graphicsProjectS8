// plane.cpp

#include "plane.h"
#include <iostream>
#include <cmath>


plane::~plane() {
    // Nothing needed here
}


plane::plane(const point& normal, const point& point_on_plane)
    : normal(normal.make_normal()), point_on_plane(point_on_plane) {}

point plane::get_normal() const {
    return normal;
}


point plane::get_point_on_plane() const {  
    return point_on_plane;
}


double plane::distance_to_point(const point& p) const {
    // Corrected: Vector from point_on_plane to p
    point vec = point_on_plane.vector_to(p); // (p - p₀)

    // Dot product of the normal vector and the vector from the plane to the point
    double numerator = std::fabs(normal.dot_product(vec));

    // Magnitude of the normal vector (should be 1 if normalized)
    double denominator = normal.magnitude();

    return numerator / denominator;
}

void plane::print_equation() const {
    // Components of the normal vector
    double A = normal.components()[0];
    double B = normal.components()[1];
    double C = normal.components()[2];

    // Calculate D = -(n · p0)
    double D = -normal.dot_product(point_on_plane);

    // Print the equation
    std::cout << "Plane equation: " << A << "x + " << B << "y + " << C << "z + " << D << " = 0" << std::endl;
}

void plane::print_plane_equation() const {
   
    double A = normal.components()[0];
    double B = normal.components()[1];
    double C = normal.components()[2];
    
    double D = point_on_plane.components()[0];
    double E = point_on_plane.components()[1];
    double F = point_on_plane.components()[2];


    // Print the equation
    std::cout << "Plane equation: " << "n · p0 = 0 = " << "[" << A << "," << B << "," << C << "]" << "·" << "[" << D << "," << E << "," << F << "]" <<std::endl;

}

bool plane::point_lies_on_plane(const point& p, double tolerance) const {
    // Calculate the distance from the point to the plane
    double distance = distance_to_point(p);
    
    // If the distance is less than the tolerance, the point lies on the plane
    return distance < tolerance;
}

/*bool plane::intersects_with(const plane& other) const{

    point cross_product_two_normals;

    cross_product_two_normals = normal.cross_product(other.get_normal());
// cross product = 0 means parallel
    return !(cross_product_two_normals.is_equal_within_tolerance(point(0, 0, 0)));  

}*/

double plane::angle_between_in_rads(const plane& other) const
{
double dot_product_between_normals = normal.dot_product(other.get_normal());
double magnitude1 = normal.magnitude();
double magnitude2 = other.get_normal().magnitude();
// cos_theta = (n_1 dot n_2)/ (mag_n1*mag_n2)
return std::acos(dot_product_between_normals / (magnitude1 * magnitude2));
}

