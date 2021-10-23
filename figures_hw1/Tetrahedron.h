#ifndef TASK1_TETRAHEDRON_H
#define TASK1_TETRAHEDRON_H

//------------------------------------------------------------------------------
// Tetrahedron.h - contains description of tetrahedron.
//------------------------------------------------------------------------------

#include <stdio.h>
#include "Rand.h"

//------------------------------------------------------------------------------
// Sphere.
struct Tetrahedron {
    int edge; // Edge of tetrahedron.
    double density; // Density of material.
};

// Input parameters from file.
void In(Tetrahedron &t, FILE* file);

// Random parameters.
void InRnd(Tetrahedron &t);

// Output tetrahedron.
void Out(Tetrahedron &t, FILE* file);

// Get square of surface of tetrahedron.
double Square(Tetrahedron &t);

#endif //TASK1_TETRAHEDRON_H
