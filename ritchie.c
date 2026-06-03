#include <stdio.h>
#include "ritchie.h"

#define BUFSIZE 100

char buf[BUFSIZE];
int bufp = 0;

int getch(void) {
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c) {
  if (bufp >= BUFSIZE) {
    fprintf(stderr, "ungetch: demasiados caracteres\n");
  } else {
    buf[bufp++] = c;
  }
}

