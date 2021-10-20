//------------------------------------------------------------------------------
// Shape.cpp - contains procedures for processing figures (and input/output).
//------------------------------------------------------------------------------

#include <stdexcept>
#include "Shape.h"

//------------------------------------------------------------------------------
// Input parameters for figure from file.
Shape* Shape::In(FILE *file) {
  Shape *shape;
  int k;
  fscanf(file, "%d", &k);
  switch (k) {
	case 1:shape = new Sphere;
	case 2:shape = new Parallelepiped;
	case 3:shape = new Tetrahedron;
	default:throw std::invalid_argument("Incorrect number of shape.");
  }
  shape->In(file);
  return shape;

}

// Random values for figure.
Shape *Shape::InRnd() {
  Shape *shape;
  int k = rand() % 3 + 1;
  switch (k) {
	case 1: shape = new Sphere;
	case 2: shape = new Parallelepiped;
	case 3: shape = new Tetrahedron;
	default: shape = 0;
  }
  shape->InRnd();
  return shape;
}

//------------------------------------------------------------------------------
// Output figure.
/*void Out(Shape &s, FILE *file) {
    switch (s.k) {
        case Shape::SPHERE:
            Out(s.s, file);
            break;
        case Shape::PARALLELEPIPED:
            Out(s.p, file);
            break;
        case Shape::TETRAHEDRON:
            Out(s.t, file);
            break;
        default:
            fprintf(file, "%s", "Incorrect figure!");
    }
}

//------------------------------------------------------------------------------
// Get square of figure
double Square(Shape &s) {
    return;
}*/

//------------------------------------------------------------------------------
// Swap function for ShakerSort.
void Shape::Swap(Shape &a, Shape &b) {
  Shape temp;
  temp = a;
  a = b;
  b = temp;
}

