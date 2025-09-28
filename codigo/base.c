#include <stdio.h>
#include <stdlib.h>
#include <sys/resource.h>
#include <sys/time.h>
#include "base.h"

struct timeval real_start, real_end;
struct rusage usage_start, usage_end;

static void record_time(void) {
    gettimeofday(&real_start, NULL);
    getrusage(RUSAGE_SELF, &usage_start);
}


static void print_time(void) {
    gettimeofday(&real_end, NULL);
    getrusage(RUSAGE_SELF, &usage_end);

    double real_sec = (real_end.tv_sec - real_start.tv_sec)
                    + (real_end.tv_usec - real_start.tv_usec) / 1e6;

    double user_sec = (usage_end.ru_utime.tv_sec - usage_start.ru_utime.tv_sec)
                    + (usage_end.ru_utime.tv_usec - usage_start.ru_utime.tv_usec) / 1e6;

    double sys_sec  = (usage_end.ru_stime.tv_sec - usage_start.ru_stime.tv_sec)
                    + (usage_end.ru_stime.tv_usec - usage_start.ru_stime.tv_usec) / 1e6;

    printf("  real: %.3f s\n", real_sec);
    printf("  user: %.3f s\n", user_sec);
    printf("  sys:  %.3f s\n", sys_sec);
}

int main(int argc, char** argv) {
  FILE* input = stdin;
  if (argc > 1) {
    input = fopen(argv[1], "r");
    if(!input) {
      perror("Failed to open file");
    }
  }
  size_t size = 0;
  int* arr = malloc(size * sizeof(int));
  while(!feof(input)) {
    size ++;
    arr = realloc(arr, size * sizeof(int));
    if(fscanf(input, "%d", arr + size - 1) == EOF) {
      size--;
    }
  }

  record_time();
  sort(arr, size);
  print_time();
  return 0;
}
