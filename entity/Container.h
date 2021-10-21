#ifndef TASK1_CONTAINER_H
#define TASK1_CONTAINER_H

//------------------------------------------------------------------------------
// Container.h - contains data type that represents simple Container.
//------------------------------------------------------------------------------

#include "Shape.h"

//------------------------------------------------------------------------------
// Container based on 1-dimension array.
class Container {
 private:
  int max_size; // Max size;
  Shape **list; // List of shapes.

 public:
  int len; // Current length.

  // Initialization.
  explicit Container();

  // Deleting Container's data.
  void Clear();

  // Input data.
  void In(FILE *file);

  // Random input.
  void InRnd(int size);

  // Output Container's data.
  void Out(FILE *file);

  // Get sum of squares of figures.
  double SquareSum();

  // Shaker sort for container.
  void ShakerSort();

  // Destructor.
  ~Container();
};

#endif //TASK1_CONTAINER_H
