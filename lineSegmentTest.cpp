//
// Created by George Weis on 27/02/2025.
//

#include<iostream>
#include "point.h"
#include "line.h"
#include "triangle.h"
#include "lineSegment.h"
#include "plane.h"


int main()
{

    point p0_1=point(1,0,0);
    point n_1=point(1,1,0);
    double l_1=5;

    lineSegment lineSeg1 = lineSegment(p0_1, n_1, l_1);
    lineSegment lineSeg2 = lineSegment(point(1,1,0), point(0,1,0.0000001), 5);

    std::cout<<"lineSeg1: \np0: ";
    lineSeg1.get_p0().print();
    std::cout<<"n_1: ";
    lineSeg1.get_n_l().print();
    std::cout<<"l_1: "<<lineSeg1.get_length()<<std::endl;

    std::cout<<"\n\nlineSeg1.end_point(): ";
    lineSeg1.end_point().print();
    std::cout<<"\n\nlineSeg1.midpoint():";
    lineSeg1.midpoint().print();

    std::cout<<"\n\nlineSeg1.print():"<<std::endl;
    lineSeg1.print();

    // testing intersection with plane functions

    //define line
    point p0_3=point(1,1,-1);
    point n_3=point(0,0,1);
    double l_3=5;
    lineSegment lineSeg3 = lineSegment(p0_3, n_3, l_3);

    //define plane
    point n_plane1 = point(0,0,1);
    point p_plane1 = point(0,0,0);
    plane plane1 = plane(n_plane1, p_plane1);


    std::cout<<"\n\nINTERSECTION WITH PLANE TESTS "<<std::endl;
    std::cout<< "lineSeg3.calc_intersect_param(plane1): "<<lineSeg3.calc_intersect_param(plane1)<<std::endl;
    std::cout<< "lineSeg3.intersect(plane1) ";
    lineSeg3.intersect(plane1).print();
    std::cout<<"lineSeg3.does_intersect(plane1): "<<lineSeg3.does_intersect(plane1)<<std::endl;
















    return 0;
}