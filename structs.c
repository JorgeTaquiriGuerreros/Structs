#include "structs.h"
#include "ritchie.h"
#include <stdio.h>
#include <ctype.h>

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

  if(!(isalpha(c) || c != '\"')){ //caracter alfabetico o comilla
    *w = 0; //string acaba en 0 o '\0'
    return c;
  }
  
  if(c == '\"'){
    w--;
    while((c = getch()) != '\"'){
      if(c == '\\'){
        c = getch();
      }
      *w++ = c;
    }
    *w = 0;
    return word[0];
  }
  for(; --lim > 0; w++){
    if(!isalnum_(*w = getch())){ //verifica si es caracter alfab. o subrayado
      ungetch(*w);//getch toma carac. entrada y ungetch devuelve caracter
      break;//sino es letra o numero temina for
    }
  }

  *w = 0;
  return word[0];//retorna primer carac. leido

}
