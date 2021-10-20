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
  virtual void In(FILE *file);

  // Random parameters.
  virtual void InRnd();

  // Output sphere.
  virtual void Out(FILE *file);

  // Get square of surface of sphere.
  virtual double Square();

  // Destructor.
  virtual ~Sphere() = default;
};

#endif
