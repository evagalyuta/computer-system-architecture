//------------------------------------------------------------------------------
// main.cpp - contains main function for testing functional.
//------------------------------------------------------------------------------

#include <stdlib.h> // For rand().
#include <time.h>   // For time().
#include <string.h>
#include <stdio.h>

#include "entity/Container.h"

void errMessage1() {
  printf("incorrect command line!\n"
		 "  Waited:\n"
		 "     command -f infile outfile01 outfile02\n"
		 "  Or:\n"
		 "     command -n number outfile01 outfile02\n");
}

void errMessage2() {
  printf("incorrect qualifier value!\n"
		 "  Waited:\n"
		 "     command -f infile outfile01 outfile02\n"
		 "  Or:\n"
		 "     command -n number outfile01 outfile02\n");
}

//------------------------------------------------------------------------------
int main(int argc, char *argv[]) {
  clock_t start = clock(); // Начальное время.

  if (argc != 5) {
	errMessage1();
	return 1;
  }

  printf("Start");
  Container container = Container();

  if (!strcmp(argv[1], "-f")) {
	FILE *file = fopen(argv[2], "r");
	container.In(file);
	fclose(file);
  } else if (!strcmp(argv[1], "-n")) {
	int size = atoi(argv[2]);
	if ((size < 1) || (size > 30000)) {
	  printf("incorrect number of figures");
	  printf(". Set 0 < number <= 30000\n");
	  return 3;
	}
	// System clock.
	srand(static_cast<unsigned int>(time(0)));
	// Random data for container.
	container.InRnd(size);
  } else {
	errMessage2();
	return 2;
  }

  // Output container data.
  FILE *fileOutput;
  fileOutput = fopen(argv[3], "w");
  container.Out(fileOutput);
  fclose(fileOutput);

  // The 2nd part of task.
  FILE *fileOutputSecond;
  fileOutputSecond = fopen(argv[4], "w");

  container.ShakerSort();
  container.Out(fileOutputSecond);
  fclose(fileOutputSecond);

  container.Clear();

  clock_t end = clock(); // Конечное время.
  double total_time = static_cast<double>(end - start) / CLOCKS_PER_SEC;
  printf("%s %lf %s \n", "Total time for program:", total_time, "seconds");
  printf("Stop");
  return 0;
}


