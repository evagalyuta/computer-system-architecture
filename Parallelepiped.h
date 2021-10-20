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
  virtual void In(Parallelepiped &t, FILE *file);

  // Random parameters.
  virtual void InRnd(Parallelepiped &p);

  // Output sphere parameters and square.
  virtual void Out(Parallelepiped &t, FILE *file);

  // Get square of surface of parallelepiped.
  virtual double Square(Parallelepiped &t);

  // Destructor.
  virtual ~Parallelepiped() = default;
};

#endif
