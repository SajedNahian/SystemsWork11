#include <stdio.h>
#include <stdlib.h>
#include <sys/stat.h>

int main () {
  char * fileName = "main.c";
  struct stat buffer;
  stat(fileName, &buffer);
  // printf("%ld\n", buffer.st_size);
  printf("File Size: ");
  if (buffer.st_size < 1000) {
  	printf("%ld B\n", buffer.st_size);
  } else if (buffer.st_size < 1000000) {
  	printf("%0.3f KB\n", buffer.st_size/1e3);
  } else {
  	printf("%0.3f KB\n", buffer.st_size/1e6);
  }

  printf("File Mode: %o\n", buffer.st_mode);
  char * permissions = malloc(10);
  permissions[9] = 0;
  for (int i = 0; i < 9; i += 3) {
  	// Credits to Jared Asch for helping me out with this
	permissions[8 - i] = (buffer.st_mode >> i) % 2 ? 'x' : '-';
	permissions[7 - i] = (buffer.st_mode >> (1 + i)) % 2 ? 'w' : '-';
  	permissions[6 - i] = (buffer.st_mode >> (2 + i)) % 2 ? 'r' : '-';
  }

  printf("Converted File Mode: %s\n", permissions);
  printf("Last Access: %s", ctime(&buffer.st_atime));
  printf("Last Modified: %s", ctime(&buffer.st_mtime));
  return 0;
}
