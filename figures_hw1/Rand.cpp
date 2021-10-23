//------------------------------------------------------------------------------
// Rand.cpp - Random functions.
//------------------------------------------------------------------------------

#include <stdlib.h>
#include "Rand.h"

// Random integer from 1 to 20.
int Random() {
    return rand() % 20 + 1;
}

// Random from 0.01 to 0.99
double Random(double i) {
    return (rand() % 99 + 1) / 100.0;
}
