//------------------------------------------------------------------------------
// Container.cpp - Container handling functions.
//------------------------------------------------------------------------------

#include "Container.h"
#include "Shape.h"
#include <stdio.h>
#include <cstddef>

//------------------------------------------------------------------------------
// Initialization of Container.
Container::Container(int size) {
  list = new Shape *[size];
}

Container::~Container() {
  Clear();
  delete[] list;
}

//------------------------------------------------------------------------------
// Clear data from Container.
void Container::Clear() {
  for (int i = 0; i < size; i++) {
	delete list[i];
  }
  size = 0;
}

//------------------------------------------------------------------------------
// Input Container's data.
void Container::In(FILE *file) {
  while (!feof(file)) {
	if ((list[size] = Shape::In(file)) != nullptr) {
	  ++size;
	}
  }
}

// Random input to Container.
void Container::InRnd(int size) {
  while (len < size) {
	if ((list[len] = Shape::InRnd()) != nullptr) {
	  ++len;
	}
  }
}

//------------------------------------------------------------------------------
// Output Container data.
void Container::Out(FILE *file) {
  fprintf(file, "%s%d%s", "Container contains ", len, " elements.");
  for (int i = 0; i < len; i++) {
	fprintf(file, "%s", "\n");
	list[i]->Out(file);
  }
}

//------------------------------------------------------------------------------
// Get sum of squares all figures.
double Container::SquareSum() {
  double sum = 0.0;
  for (int i = 0; i < len; i++) {
	sum += list[i]->Square();
  }
  return sum;
}

//------------------------------------------------------------------------------
// Swap function for ShakerSort.
void Container::Swap(Shape *a, Shape *b) {
  Shape *temp;
  temp = a;
  a = b;
  b = temp;
}

//------------------------------------------------------------------------------
// Shaker sort for container.
void Container::ShakerSort(int size) {
  bool swapped = true;
  int start = 0;
  int end = size - 1;

  while (swapped) {
	swapped = false;
	for (int i = start; i < end; ++i) {
	  if (list[i]->Square() > list[i + 1]->Square()) {
		Swap(list[i], list[i + 1]);
		swapped = true;
	  }
	}
	if (!swapped)
	  break;
	swapped = false;
	--end;
	for (int i = end - 1; i >= start; --i) {
	  if (list[i]->Square() > list[i + 1]->Square()) {
		Swap(list[i], list[i + 1]);
		swapped = true;
	  }
	}
	++start;
  }
}
