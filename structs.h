#ifndef STRUCTS_H
#define STRUCTS_H

struct key {
  char *word;
  int count;
};

int getword(char *word, int lim);
int binsearch(char *word, struct key tab[], int n);

#endif

