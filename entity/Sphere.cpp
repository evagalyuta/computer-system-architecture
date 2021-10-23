//------------------------------------------------------------------------------
// Sphere.cpp - implementation of sphere.h.
//------------------------------------------------------------------------------

#include "Sphere.h"
#include <math.h>
#include <stdexcept>
#include "../function/Rand.h"

//------------------------------------------------------------------------------
// Input parameters from file.
void Sphere::In(FILE *file) {
  int radius;
  double density;
  if (fscanf(file, "%d %lf", &radius, &density) != 2)
	throw std::invalid_argument("Incorrect sphere.");
  this->radius = radius;
  this->density = density;

}

// Random parameters.
void Sphere::InRnd() {
  radius = Random();
  density = Random(1);
}

//------------------------------------------------------------------------------
// Output sphere parameters and square.
void Sphere::Out(FILE *file) {
  fprintf(file, "%s%d%s%.2f%s%.2f", "It is Sphere: radius = ", radius, ", density = ", density, ". Square = ",
		  Square());
}

//------------------------------------------------------------------------------
// Get square of surface of sphere.
double Sphere::Square() {
  return 4.0 * M_PI * pow(radius, 2);
}
