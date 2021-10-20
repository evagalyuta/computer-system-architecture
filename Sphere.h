#ifndef TASK1_SPHERE_H
#define TASK1_SPHERE_H

//------------------------------------------------------------------------------
// Sphere.h - contains description of sphere.
//------------------------------------------------------------------------------

#include <stdio.h>
#include "Shape.h"

//------------------------------------------------------------------------------
// Sphere.
class Sphere : public Shape {
 private:
  int radius; // Radius.

 public:
  // Input parameters from file.
  virtual void In(Sphere &s, FILE *file);

  // Random parameters.
  virtual void InRnd(Sphere &s);

  // Output sphere.
  virtual void Out(Sphere &s, FILE *file);

  // Get square of surface of sphere.
  virtual double Square(Sphere &s);

  // Destructor.
  virtual ~Sphere() = default;
};

#endif
