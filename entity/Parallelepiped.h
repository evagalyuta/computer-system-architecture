#ifndef TASK1_PARALLELEPIPED_H
#define TASK1_PARALLELEPIPED_H

//------------------------------------------------------------------------------
// Parallelepiped.h - contains description of parallelepiped.
//-----------------------------------------------------------------------------

#include <stdio.h>
#include "Shape.h"

//------------------------------------------------------------------------------
// Parallelepiped.
class Parallelepiped : public Shape {
 private:
  int a, b, c; // Sides.
 public:
  // Input parameters from file.
  virtual void In(FILE *file);

  // Random parameters.
  virtual void InRnd();

  // Output sphere parameters and square.
  virtual void Out(FILE *file);

  // Get square of surface of parallelepiped.
  virtual double Square();

  // Destructor.
  virtual ~Parallelepiped() = default;
};

#endif
