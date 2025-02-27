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
  //bool is_inside(const point& p) const;

  static solid load_stl(const std::string& filename);

  const std::vector<triangle>& get_triangles() const { return triangles; }

  /* print all triangles to std::cout */
  void print_triangles() const;

  void print_triangle_areas() const;

  std::string triangle_statistics_csv() const;

  void export_triangle_statistics_csv(const std::string& filename) const;

  double volume() const;

  double surface_area() const;


};

#endif