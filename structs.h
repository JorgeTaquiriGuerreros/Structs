#ifndef STRUCTS_H
#define STRUCTS_H

#define MAXWORD 100
#define MAXWORDS 1000

struct key {
  char *word;
  int count;
};

struct wordCount {
  char word[MAXWORD];
  int count;
};


int getword(char *word, int lim);
int binsearch(char *word, struct key tab[], int n);

int findWord(struct wordCount words[], int nWords, const char *word);
void addWord(struct wordCount words[], int *nWords, const char *word);
int compareCounts(const void *a, const void *b);
#endif

