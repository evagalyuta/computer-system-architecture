#include <iostream>
#include <pthread.h>
#include <unistd.h>
#include <semaphore.h>
#include <cstring>
#include <sys/time.h>

const int MAX_SIZE = 2;
int bufferProducts[MAX_SIZE];
std::pair<int, int> *allProducts;
int iterations;
bool isWaiting;

sem_t empty; // emptiness of buffer
sem_t full; // fullness of buffer

pthread_mutex_t mutexD; // mutex for write
pthread_mutex_t mutexF; // mutex for read

void errMessage1(); // error message 1 type
void errMessage2(); // error message 2 type

// Get name of product by number.
std::string getNameProduct(int number) {
  switch (number) {
	case 1: {
	  return "tobacco";
	}
	case 2: {
	  return "paper";
	}
	case 3: {
	  return "match";
	}
	default: {
	  return "smth strange";
	}
  }
}

// Choose smoker that will smoke.
int chooseSmoker() {
  if (bufferProducts[0] == -1 || (bufferProducts[0] == bufferProducts[1])) {
	return -1;
  }

  if (bufferProducts[0] == 1) {
	if (bufferProducts[1] == 2) {
	  return 3;
	} else {
	  return 2;
	}
  } else if (bufferProducts[0] == 2) {
	if (bufferProducts[1] == 1) {
	  return 3;
	} else {
	  return 1;
	}
  } else if (bufferProducts[0] == 3) {
	if (bufferProducts[1] == 1) {
	  return 2;
	} else {
	  return 1;
	}
  }
  return 0;
}

// Dealer (producer)
void *Dealer(void *param) {
  int index = *((int *)param);

  // Input elements in buffer.
  while (true) {
	if (iterations <= 0) {
	  return nullptr;
	}
	sleep(3);
	if (!isWaiting) {
	  pthread_mutex_lock(&mutexD);
	  sem_wait(&empty);

	  bufferProducts[0] = allProducts[index - iterations].first;
	  bufferProducts[1] = allProducts[index - iterations].second;

	  sem_post(&full);
	  pthread_mutex_unlock(&mutexD);
	  // Message from dealer.
	  printf("Dealer's supply. (%s %s)\n", getNameProduct(bufferProducts[0]).c_str(),
			 getNameProduct(bufferProducts[1]).c_str());

	  isWaiting = true;
	  sleep(4);
	}
  }
}

// Smoker with tabacco.
void *SmokerTabacco(void *param) {
  while (true) {
	if (iterations <= 0) {
	  return nullptr;
	}
	if (chooseSmoker() == 1) {
	  sleep(2);

	  pthread_mutex_lock(&mutexF);
	  sem_wait(&full);

	  bufferProducts[0] = -1;
	  bufferProducts[1] = -1;

	  sem_post(&empty);
	  pthread_mutex_unlock(&mutexF);

	  printf("Smoker with tabacco: smokes.\n");
	  --iterations;
	  isWaiting = false;
	}
  }
}

// Smoker with paper.
void *SmokerPaper(void *param) {
  while (true) {
	if (iterations <= 0) {
	  return nullptr;
	}
	if (chooseSmoker() == 2) {
	  sleep(2);

	  pthread_mutex_lock(&mutexF);
	  sem_wait(&full);

	  bufferProducts[0] = -1;
	  bufferProducts[1] = -1;

	  sem_post(&empty);
	  pthread_mutex_unlock(&mutexF);

	  printf("Smoker with paper: smokes.\n");
	  --iterations;
	  isWaiting = false;
	}
  }
}

// Smoker with match.
void *SmokerMatch(void *param) {
  while (true) {
	if (iterations <= 0) {
	  return nullptr;
	}
	if (chooseSmoker() == 3) {
	  sleep(2);

	  pthread_mutex_lock(&mutexF);
	  sem_wait(&full);

	  bufferProducts[0] = -1;
	  bufferProducts[1] = -1;

	  sem_post(&empty);
	  pthread_mutex_unlock(&mutexF);

	  printf("Smoker with match: smokes.\n");
	  --iterations;
	  isWaiting = false;
	}
  }
}

void inputData(int index, FILE *file) {
  int first, second;
  for (int i = 0; i < index; ++i) {
	if (fscanf(file, "%d %d", &first, &second) != 2) {
	  throw std::invalid_argument("Incorrect number of products from dealer.");
	}
	if (first == second) {
	  throw std::invalid_argument("Incorrect products from dealer");
	}
	allProducts[i] = std::pair<int, int>(first, second);
  }
}

void inputRandom(int index) {
  int first, second;
  for (int i = 0; i < index; ++i) {
	first = rand() % 3 + 1;
	second = rand() % 3 + 1;
	while (first == second) {
	  second = rand() % 3 + 1;
	}
	allProducts[i] = std::pair<int, int>(first, second);
  }
}

int main(int argc, char *argv[]) {
  struct timeval timeval{};
  gettimeofday(&timeval, nullptr);
  int64_t s1 = (int64_t)(timeval.tv_sec) * 1000;
  int64_t s2 = (timeval.tv_usec / 1000);
  long long start = s1 + s2;   // Set timer.

  if (argc != 3) {
	errMessage1();
	return 1;
  }

  printf("Start\n");

  pthread_mutex_init(&mutexD, nullptr);
  pthread_mutex_init(&mutexF, nullptr);
  sem_init(&empty, 0, 2); // count of empty cells set 2
  sem_init(&full, 0, 0); // count of fully cells set 0

  FILE *file;

  if (!strcmp(argv[1], "-f")) {
	file = fopen(argv[2], "r");
	fscanf(file, "%d", &iterations);
	allProducts = new std::pair<int, int>[iterations];
	inputData(iterations, file);
	fclose(file);
  } else if (!strcmp(argv[1], "-n")) {
	iterations = atoi(argv[2]);
	if ((iterations < 1) || (iterations > 30)) {
	  printf("incorrect number of iterations = %d", iterations);
	  printf(". Set 0 < number <= 30\n");
	  return 3;
	}
	allProducts = new std::pair<int, int>[iterations];
	srand(static_cast<unsigned int>(time(nullptr)));
	inputRandom(iterations);
  } else {
	errMessage2();
	return 2;
  }

  int count = iterations;

  pthread_t threadDealer;
  pthread_create(&threadDealer, nullptr, Dealer, (void *)(&count));
  pthread_t threadTabacco;
  pthread_t threadPaper;
  pthread_t threadMatch;
  pthread_create(&threadTabacco, nullptr, SmokerTabacco, (void *)(&count));
  pthread_create(&threadPaper, nullptr, SmokerPaper, (void *)(&count));
  pthread_create(&threadMatch, nullptr, SmokerMatch, (void *)(&count));

  pthread_join(threadDealer, nullptr);
  pthread_join(threadTabacco, nullptr);
  pthread_join(threadPaper, nullptr);
  pthread_join(threadMatch, nullptr);

  gettimeofday(&timeval, nullptr);
  s1 = (int64_t)(timeval.tv_sec) * 1000;
  s2 = (timeval.tv_usec / 1000);
  long long end = s1 + s2; // End timeval.

  double total_time = static_cast<double>(end - start) / 1000;
  printf("%s %lf %s \n", "Total timeval for program:", total_time, "seconds");
  printf("Stop\n");
  delete[] allProducts;
  return 0;
}

void errMessage1() {
  printf("incorrect command line!\n"
		 "  Waited:\n"
		 "     command -f infile \n"
		 "  Or:\n"
		 "     command -n number\n");
}

void errMessage2() {
  printf("incorrect qualifier value!\n"
		 "  Waited:\n"
		 "     command -f infile\n"
		 "  Or:\n"
		 "     command -n number\n");
}
