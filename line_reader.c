#include "line_reader.h"
#include <stdio.h>
#include <stdlib.h>

char* readLine() {
  size_t size = 64;   
  size_t len = 0;
  char *buffer = malloc(size);
  if (!buffer) return NULL;

  int c;
  while ((c = getchar()) != EOF && c != '\n') {
    buffer[len++] = (char)c;
    if (len >= size) {
      size *= 2; 
      char *newBuffer = realloc(buffer, size);
      if (!newBuffer) {
        free(buffer);
        return NULL;
      }
      buffer = newBuffer;
    }
  }
  buffer[len] = '\0'; 
  return buffer;
}