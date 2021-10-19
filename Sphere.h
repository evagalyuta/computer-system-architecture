#ifndef TASK1_SPHERE_H
#define TASK1_SPHERE_H

//------------------------------------------------------------------------------
// Sphere.h - contains description of sphere.
//------------------------------------------------------------------------------

#include <stdio.h>
#include "Rand.h"

//------------------------------------------------------------------------------
// Sphere.
struct Sphere {
    int radius; // Radius.
    double density; // Density of material.
};

// Input parameters from file.
void In(Sphere &s, FILE* file);

// Random parameters.
void InRnd(Sphere &s);

// Output sphere.
void Out(Sphere &s, FILE* file);

// Get square of surface of sphere.
double Square(Sphere &s);

#endif //TASK1_SPHERE_H
