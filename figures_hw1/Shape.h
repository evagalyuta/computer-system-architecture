#ifndef TASK1_SHAPE_H
#define TASK1_SHAPE_H

//------------------------------------------------------------------------------
// Shape.h - contains definition of figure.
//------------------------------------------------------------------------------

#include "Sphere.h"
#include "Parallelepiped.h"
#include "Tetrahedron.h"

//------------------------------------------------------------------------------
// Structure summarizing all shapes.
struct Shape {
    // Values of keys for different figures.
    enum key {SPHERE, PARALLELEPIPED, TETRAHEDRON};
    key k; // Key.
    // Alternatives.
    union { // Simple realization.
        Sphere s;
        Parallelepiped p;
        Tetrahedron t;
    };
};

// Input figure.
Shape *In(FILE* file);

// Random input.
Shape *InRnd();

// Output figure.
void Out(Shape &s, FILE* file);

// Get square of figure.
double Square(Shape &s);

// Swap function for ShakerSort.
void Swap(Shape &a, Shape &b);

#endif //TASK1_SHAPE_H
