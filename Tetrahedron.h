#ifndef TASK1_TETRAHEDRON_H
#define TASK1_TETRAHEDRON_H

//------------------------------------------------------------------------------
// Tetrahedron.h - contains description of tetrahedron.
//------------------------------------------------------------------------------

#include <stdio.h>
#include "Shape.h"

//------------------------------------------------------------------------------
// Sphere.
struct Tetrahedron : public Shape {
 private:
    int edge; // Edge of tetrahedron.

 public:
  // Input parameters from file.
  virtual void In(Tetrahedron &t, FILE* file);

  // Random parameters.
  virtual void InRnd(Tetrahedron &t);

  // Output tetrahedron.
  virtual void Out(Tetrahedron &t, FILE* file);

  // Get square of surface of tetrahedron.
  virtual double Square(Tetrahedron &t);
};

#endif //TASK1_TETRAHEDRON_H
