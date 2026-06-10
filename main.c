#include "structs.h"
/* #define BUFF_SIZE 256 */
#include <stdio.h>
/* #define PROMPT "structs> " */
#include <ctype.h>
#include <string.h>
#include <stdlib.h>
#define MAXWORD 100
/*#define NKEYS (sizeof(keytab) / sizeof(keytab[0]))*/
/*
int main(){

  char buffer[BUFF_SIZE];
  while(getword(buffer, BUFF_SIZE) != EOF)
    printf("%s\n", buffer);

  return 0;
}
*/
/*
struct key keytab[] = {
  {"auto", 0}, {"break", 0}, {"case", 0}, {"char", 0},
  {"const", 0}, {"continue", 0}, {"default", 0}, {"do", 0},
  {"double", 0}, {"else", 0}, {"enum", 0}, {"extern", 0},
  {"float", 0}, {"for", 0}, {"goto", 0}, {"if", 0},
  {"int", 0}, {"long", 0}, {"register", 0}, {"return", 0},
  {"short", 0}, {"signed", 0}, {"sizeof", 0}, {"static", 0},
  {"struct", 0}, {"switch", 0}, {"typedef", 0}, {"union", 0},
  {"unsigned", 0}, {"void", 0}, {"volatile", 0}, {"while", 0}
};

int main() {
  int n;
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF) {
    if (isalpha(word[0])) { //se filtra basura
      if ((n = binsearch(word, keytab, NKEYS)) >= 0) {
        keytab[n].count++;
      }
    }
  }

  for (size_t i = 0; i < NKEYS; i++) {
    if (keytab[i].count > 0) {
      printf("%4d %s\n", keytab[i].count, keytab[i].word);
    }
  }

  return 0;
}
*/
struct wordCount words[MAXWORDS]; 
int nWords = 0;                   

int main() {
  char word[MAXWORD];

  while (getword(word, MAXWORD) != EOF) {
    if (isalpha(word[0]) || word[0] == '_') { //solo palabras o variables
      addWord(words, &nWords, word);
    }
  }

  //ordena por frecuencia
  qsort(words, nWords, sizeof(struct wordCount), compareCounts);

  for (int i = 0; i < nWords; i++) {
    printf("%4d %s\n", words[i].count, words[i].word);
  }

  return 0;
}
