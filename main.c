#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main () {
  char * fileName = "main.c";
  struct stat buffer;
  stat(fileName, &buffer);
  printf("%ld\n", buffer.st_size);
  return 0;
}
