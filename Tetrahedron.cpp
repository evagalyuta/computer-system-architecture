//------------------------------------------------------------------------------
// Tetrahedron.cpp - implementation of tetrahedron.h.
//------------------------------------------------------------------------------

#include "Tetrahedron.h"
#include "Rand.h"
#include <math.h>
#include <stdexcept>

//------------------------------------------------------------------------------
// Input parameters from file.
void Tetrahedron::In(Tetrahedron &t, FILE* file) {
    int edge;
    double density;
     if (fscanf(file, "%d %lf", &edge, &density) != 2)
         throw std::invalid_argument("Incorrect tetrahedron.");
     t.edge = edge;
     t.density = density;
}

// Random parameters.
void Tetrahedron::InRnd(Tetrahedron &t) {
    t.edge = Random();
    t.density = Random(1);
}

//------------------------------------------------------------------------------
// Output tetrahedron parameters and square.
void Tetrahedron::Out(Tetrahedron &t, FILE* file) {
    fprintf(file, "%s%d%s%.2f%s%.2f", "It is Tetrahedron: edge = ", t.edge, ", density = ",t.density,". Square = ",
            Square(t));
}

//------------------------------------------------------------------------------
// Get square of surface of tetrahedron.
double Tetrahedron::Square(Tetrahedron &t) {
    return (pow(t.edge, 2) * sqrt(3)) / 4.0;
}
