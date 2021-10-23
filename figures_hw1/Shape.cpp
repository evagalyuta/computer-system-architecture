//------------------------------------------------------------------------------
// Shape.cpp - contains procedures for processing figures (and input/output).
//------------------------------------------------------------------------------

#include <stdexcept>
#include "Shape.h"

//------------------------------------------------------------------------------
// Input parameters for figure from file.
Shape *In(FILE *file) {
    Shape *sp;
    int k;
    fscanf(file, "%d", &k);
        switch (k) {
            case 1:
                sp = new Shape;
                sp->k = Shape::SPHERE;
                In(sp->s, file);
                return sp;
            case 2:
                sp = new Shape;
                sp->k = Shape::PARALLELEPIPED;
                In(sp->p, file);
                return sp;
            case 3:
                sp = new Shape;
                sp->k = Shape::TETRAHEDRON;
                In(sp->t, file);
                return sp;
            default:
                throw std::invalid_argument("Incorrect number of shape.");
        }

}

// Random values for figure.
Shape *InRnd() {
    Shape *sp;
    int k = rand() % 2 + 1;
    switch (k) {
        case 1:
            sp = new Shape;
            sp->k = Shape::SPHERE;
            InRnd(sp->s);
            return sp;
        case 2:
            sp = new Shape;
            sp->k = Shape::PARALLELEPIPED;
            InRnd(sp->p);
            return sp;
        case 3:
            sp = new Shape;
            sp->k = Shape::TETRAHEDRON;
            InRnd(sp->t);
            return sp;
        default:
            return 0;
    }
}

//------------------------------------------------------------------------------
// Output figure.
void Out(Shape &s, FILE *file) {
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
    switch (s.k) {
        case Shape::SPHERE:
            return Square(s.s);
        case Shape::PARALLELEPIPED:
            return Square(s.p);
        case Shape::TETRAHEDRON:
            return Square(s.t);
        default:
            return 0.0;
    }
}

//------------------------------------------------------------------------------
// Swap function for ShakerSort.
void Swap(Shape &a, Shape &b) {
    Shape temp;
    temp = a;
    a = b;
    b = temp;
}
