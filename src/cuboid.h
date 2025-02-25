//cuboid header

#ifndef CUBOID_H
#define CUBOID_H

#include "triangle.h"
#include "point.h"
#include <vector>

class cuboid {
  private:
    std::vector<triangle> triangles; // Store all triangles
    
    
  public:
    cuboid(); // Constructor to initialize the cuboid
    void print_triangles() const; 
  
    std::vector<triangle> get_triangles() const;


};

#endif // CUBOID_H