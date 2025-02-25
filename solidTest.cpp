#include "square_based_pyramid.h"
#include "point.h"
#include "solid.h"
#include "triangle.h"
int main()
{

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

  solid s = solid::load_stl("/Users/pablomooney/Documents/Year 4/S8Project/graphicsProjectS8_git_backup/liver.stl");
  solid heart = solid::load_stl("/Users/pablomooney/Documents/Year 4/S8Project/graphicsProjectS8_git_backup/liver.stl");


  //Check if the solid is successfully loaded
  if (heart.get_triangles().empty()) {
    std::cerr << "Error: No triangles loaded. Check the STL file or loading function." << std::endl;
    return 1;
  }

  // Print the triangles in the solid
  heart.print_triangles();

  std::cout <<"heart"<< std::endl;

  heart.print_triangle_areas();
  return 0;
}