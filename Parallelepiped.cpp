//------------------------------------------------------------------------------
// Parallelepiped.cpp - implementation of parallelepiped.h.
//------------------------------------------------------------------------------

#include <stdexcept>
#include "Parallelepiped.h"
#include "Rand.h"

//------------------------------------------------------------------------------
// Input parameters from file.
void Parallelepiped::In(Parallelepiped &p, FILE *file) {
    int a, b, c;
    double density;
    if (fscanf(file, "%d %d %d %lf", &a, &b, &c, &density) != 4)
        throw std::invalid_argument("Incorrect parallelepiped.");
    p.a = a;
    p.b = b;
    p.c = c;
    p.density = density;

}

// Random parameters.
void Parallelepiped::InRnd(Parallelepiped &p) {
    p.a = Random();
    p.b = Random();
    p.c = Random();
    p.density = Random(1);
}

//------------------------------------------------------------------------------
// Output parallelepiped parameters and square.
void Parallelepiped::Out(Parallelepiped &p, FILE *file) {
    fprintf(file, "%s%d%s%d%s%d%s%.2f%s%.2f", "It is Parallelepiped: a = ", p.a, ", b = ", p.b, ", c = ", p.c,
            ", density = ", p.density, ". Square = ", Square(p));
}

//------------------------------------------------------------------------------
// Get square of surface of parallelepiped.
double Parallelepiped::Square(Parallelepiped &p) {
    return 2.0 * (p.a * p.b + p.a * p.c + p.b * p.c);
}

