#ifndef SOLID_H
#define SOLID_H
#include "point.h"
#include "triangle.h"

class point;

class solid
{

private:
  std::vector<triangle> triangles;

public:

  solid() = default ;
  solid(std::vector<triangle>);

  /* is the point inside or outside the solid */
  bool is_inside(const point& p) const;

  /* print all triangles to std::cout */
  void print_triangles() const;
};

#endif