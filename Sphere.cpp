//------------------------------------------------------------------------------
// Sphere.cpp - implementation of sphere.h.
//------------------------------------------------------------------------------

#include "Sphere.h"
#include <math.h>
#include <stdexcept>
#include "Rand.h"
#include "Shape.h"

//------------------------------------------------------------------------------
// Input parameters from file.
void In(Sphere &s, FILE *file) {
    int radius;
    double density;
    if (fscanf(file, "%d %lf", &radius, &density) != 2)
        throw std::invalid_argument("Incorrect sphere.");
    s.radius = radius;
    s.density = density;

}

// Random parameters.
void InRnd(Sphere &s) {
    s.radius = Random();
    s.density = Random(1);
}

//------------------------------------------------------------------------------
// Output sphere parameters and square.
void Out(Sphere &s, FILE *file) {
    fprintf(file, "%s%d%s%.2f%s%.2f", "It is Sphere: radius = ", s.radius, ", density = ", s.density, ". Square = ",
            Square(s));
}

//------------------------------------------------------------------------------
// Get square of surface of sphere.
double Square(Sphere &s) {
    return 4.0 * M_PI * pow(s.radius, 2);
}
