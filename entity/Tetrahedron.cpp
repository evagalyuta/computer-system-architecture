//------------------------------------------------------------------------------
// Tetrahedron.cpp - implementation of tetrahedron.h.
//------------------------------------------------------------------------------

#include "Tetrahedron.h"
#include "../Rand.h"
#include <math.h>
#include <stdexcept>

//------------------------------------------------------------------------------
// Input parameters from file.
void Tetrahedron::In(FILE *file) {
  int edge;
  double density;
  if (fscanf(file, "%d %lf", &edge, &density) != 2)
	throw std::invalid_argument("Incorrect tetrahedron.");
  this->edge = edge;
  this->density = density;
}

// Random parameters.
void Tetrahedron::InRnd() {
  edge = Random();
  density = Random(1);
}

//------------------------------------------------------------------------------
// Output tetrahedron parameters and square.
void Tetrahedron::Out(FILE *file) {
  fprintf(file, "%s%d%s%.2f%s%.2f", "It is Tetrahedron: edge = ", edge, ", density = ", density, ". Square = ",
		  Square());
}

//------------------------------------------------------------------------------
// Get square of surface of tetrahedron.
double Tetrahedron::Square() {
  return (pow(edge, 2) * sqrt(3)) / 4.0;
}
