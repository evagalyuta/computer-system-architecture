#ifndef TASK1_CONTAINER_H
#define TASK1_CONTAINER_H

//------------------------------------------------------------------------------
// Container.h - contains data type that represents simple Container.
//------------------------------------------------------------------------------

#include "Shape.h"

//------------------------------------------------------------------------------
// Container based on 1-dimension array.
struct Container {
    enum {max_len = 30000}; // Max length.
    int len; // Current length.
    Shape *cont[max_len];
};

// Initialization.
void Init(Container &c);

// Deleting Container's data.
void Clear(Container &c);

// Input data.
void In(Container &c, FILE* file);

// Random input.
void InRnd(Container &c, int size);

// Output Container's data.
void Out(Container &c, FILE* file);

// Get sum of squares of figures.
double SquareSum(Container &c);

// Shaker sort for container.
void ShakerSort(Container &c,int size);

#endif //TASK1_CONTAINER_H
