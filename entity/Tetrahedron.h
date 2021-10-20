#ifndef TASK1_TETRAHEDRON_H
#define TASK1_TETRAHEDRON_H

//------------------------------------------------------------------------------
// Tetrahedron.h - contains description of tetrahedron.
//------------------------------------------------------------------------------

#include <stdio.h>
#include "Shape.h"

//------------------------------------------------------------------------------
// Sphere.
class Tetrahedron : public Shape {
 private:
  int edge; // Edge of tetrahedron.

 public:
  // Input parameters from file.
  virtual void In(FILE *file);

  // Random parameters.
  virtual void InRnd();

  // Output tetrahedron.
  virtual void Out(FILE *file);

  // Get square of surface of tetrahedron.
  virtual double Square();
};

#endif
