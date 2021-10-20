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
  virtual void Out(FILE *file) = 0;

  // Get square of figure.
  virtual double Square() = 0;

  // Destructor.
  virtual ~Shape() = default;
};

#endif
