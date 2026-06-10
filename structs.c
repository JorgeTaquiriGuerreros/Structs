#include "structs.h"
#include "ritchie.h"
#include <stdio.h>
#include <ctype.h>
#include <string.h>

/*int isspace(char c){
  return c == ' ' || c == '\n' || c == '\t';
}

int isalpha(char c){
  return 'a' <= c && c <= 'z' ||
         'A' <= c && c <= 'Z';
}

int isnum(char c){
  return '0' <= c && c <= '9';
}

int isalnum(char c){
  return isalpha(c) || isnum(c);
}
*/
int isalnum_(char c){
  return c == '_' || isalnum(c);
}
int getword(char* word, int lim) { //lim = nro maximo chars que puedo tener en el buffer
  int c;
  char *w = word;

  while(isspace(c = getch())); //detecta espacios blanco, tabs, saltos linea

  if(c != EOF) *w++ = c;
  //elimina constantes cadena y caracter
  if(c == '\"' || c == '\'') {
    int quote = c; //se guarda que tipo de comilla se ingreso
    while((c = getch()) != quote && c != EOF) {
      if(c == '\\'){
        c = getch();
      }
    }
    word[0] = quote; //deja comilla principio
    word[1] = 0;
    return quote; //devuelve comilla
  }

  if(c == '#'){//para tratar directivas como include define ifndef o endif :D
    w--;
    while ((c = getch()) != '\n' && c != EOF){
    //consumir toda la palabra despues del #
    }
    word[0] = '\0';
    return getword(word,lim);//llamamos otra vez para seguir con la otra palabra
  }

  if(!isalpha(c) && c != '_'){ //si no es char alfabetico ni guion bajo
    *w = 0; //string acaba en 0 o '\0'
    return c;
  }

  for(; --lim > 0; w++){
    if(!isalnum_(*w = getch())){ //verifica si es caracter alfab. o subrayado
      ungetch(*w);
      break;//sino es letra o numero temina
    }
  }

  *w = 0;
  return word[0];
}

int binsearch(char *word, struct key tab[], int n) {
  int low = 0;
  int high = n - 1;
  int mid, cond;

  while (low <= high) {
    mid = (low + high) / 2;
    if ((cond = strcmp(word, tab[mid].word)) < 0) {
      high = mid - 1; 
    } else if (cond > 0) {
      low = mid + 1;  
    } else {
      return mid;//se encontro coincidencia+1
    }
  }
  return -1;//no hay wordd 
}

//ejercicio 6-4

int findWord(struct wordCount words[], int nWords, const char *word) {
  for (int i = 0; i < nWords; i++) {
    if (strcmp(words[i].word, word) == 0) {
      return i; //palabra encontrada
    }
  }
  return -1;
}

void addWord(struct wordCount words[], int *nWords, const char *word) {
  int idx = findWord(words, *nWords, word);
  if (idx >= 0) {
    words[idx].count++;//si existe +1
  } else {
    if (*nWords < MAXWORDS) {
      strcpy(words[*nWords].word, word);
      words[*nWords].count = 1;
      (*nWords)++;//se agrego la nueva word
    }
  }
}

int compareCounts(const void *a, const void *b) {
  struct wordCount *wa = (struct wordCount *)a;
  struct wordCount *wb = (struct wordCount *)b;
  return wb->count - wa->count; //orden decreciente
}
