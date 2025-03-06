//
// Created by George Weis on 27/02/2025.
//

#ifndef LINESEGMENT_H
#define LINESEGMENT_H

#include "point.h"
#include "line.h"
#include "triangle.h"

class lineSegment : public line {
private:
    double length;

public:
    // Default constructor
    lineSegment() = default;

    // Parameterized constructor
    lineSegment(const point& p0In, const point& n_lIn, const double& lengthIn);

    // Destructor
    ~lineSegment();


    // Functions without arguments
    double get_length() const;
    point end_point() const;
    point midpoint() const;
    void print() const;

    double change_in_x() const;
    double change_in_y() const;
    double change_in_z() const;

    // Functions with arguments
    double calc_intersect_param(const plane& plane_0) const;
    point intersect(const plane& plane_0) const;
    bool does_intersect(const plane& plane_0) const;
    bool does_intersect(const triangle& tri) const;








};

#endif //LINESEGMENT_H
