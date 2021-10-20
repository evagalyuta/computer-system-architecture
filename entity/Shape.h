#ifndef TASK1_SHAPE_H
#define TASK1_SHAPE_H

//------------------------------------------------------------------------------
// Shape.h - contains definition of figure.
//------------------------------------------------------------------------------

#include "stdio.h"

//------------------------------------------------------------------------------
// Class summarizing all shapes.
class Shape {
 protected:
  double density; // Density of material.

 public:
  // Input figure.
  static Shape *InStatic(FILE *file);

  // Random input.
  static Shape *InRndStatic();

  // Virtual input figure.
  virtual void In(FILE *file) = 0;

  // Virtual random input.
  virtual void InRnd() = 0;

  // Output figure.
  virtual void Out(FILE *file) = 0;

  // Get square of figure.
  virtual double Square() = 0;

  // Destructor.
  virtual ~Shape() = default;
};

#endif
