#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <assert.h>
#include <unistd.h>
#include <string.h>

int ismapped(void *ptr, int bytes, bool write) {
  pid_t child;

  child = fork();
  if (child == 0) {
    if (write == true) {
      memset(ptr, 0, bytes);
    } else {
      void *data = malloc(bytes);
      memcpy(data, ptr, bytes);
    }
    exit(EXIT_SUCCESS);
  }

  int status;
  pid_t result = waitpid(child, &status, 0);
  assert(result >= 0);
  return (status == EXIT_SUCCESS);
}

void testptr(void *p, int bytes, char *name, bool write) {
  printf("%s:\t%d\t%p\n", name, ismapped(p, bytes, write), p);
}
