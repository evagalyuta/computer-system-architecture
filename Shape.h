#ifndef TASK1_SHAPE_H
#define TASK1_SHAPE_H

//------------------------------------------------------------------------------
// Shape.h - contains definition of figure.
//------------------------------------------------------------------------------

#include "Sphere.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"

//------------------------------------------------------------------------------
// Structure summarizing all shapes.
class Shape {
 protected:
  double density; // Density of material.

 public:
  // Input figure.
  static Shape *In(FILE *file);

  // Random input.
  static Shape *InRnd();

  // Output figure.
  virtual void Out(Shape &s, FILE *file);

  // Get square of figure.
  virtual double Square(Shape &s);

  // Swap function for ShakerSort.
  virtual void Swap(Shape &a, Shape &b);

  // Destructor.
  virtual ~Shape() = default;
};

#endif
