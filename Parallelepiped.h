#ifndef TASK1_PARALLELEPIPED_H
#define TASK1_PARALLELEPIPED_H

//------------------------------------------------------------------------------
// Parallelepiped.h - contains description of parallelepiped.
//-----------------------------------------------------------------------------

#include <stdio.h>
#include "Rand.h"

//------------------------------------------------------------------------------
// Parallelepiped.
struct Parallelepiped {
    int a, b, c; // Sides.
    double density; // Density of material.
};

// Input parameters from file.
void In(Parallelepiped &t, FILE* file);

// Random parameters.
void InRnd(Parallelepiped &p);

// Output sphere parameters and square.
void Out(Parallelepiped &t, FILE* file);

// Get square of surface of parallelepiped.
double Square(Parallelepiped &t);

#endif //TASK1_PARALLELEPIPED_H
