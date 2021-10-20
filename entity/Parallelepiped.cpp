//------------------------------------------------------------------------------
// Parallelepiped.cpp - implementation of parallelepiped.h.
//------------------------------------------------------------------------------

#include <stdexcept>
#include "Parallelepiped.h"
#include "../Rand.h"

//------------------------------------------------------------------------------
// Input parameters from file.
void Parallelepiped::In(FILE *file) {
    int a, b, c;
    double density;
    if (fscanf(file, "%d %d %d %lf", &a, &b, &c, &density) != 4)
        throw std::invalid_argument("Incorrect parallelepiped.");
    this->a = a;
    this->b = b;
    this->c = c;
    this->density = density;

}

// Random parameters.
void Parallelepiped::InRnd() {
    a = Random();
    b = Random();
    c = Random();
    density = Random(1);
}

//------------------------------------------------------------------------------
// Output parallelepiped parameters and square.
void Parallelepiped::Out(FILE *file) {
    fprintf(file, "%s%d%s%d%s%d%s%.2f%s%.2f", "It is Parallelepiped: a = ", a, ", b = ", b, ", c = ", c,
            ", density = ", density, ". Square = ", Square());
}

//------------------------------------------------------------------------------
// Get square of surface of parallelepiped.
double Parallelepiped::Square() {
    return 2.0 * (a * b + a * c + b * c);
}

