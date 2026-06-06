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

  if(c == '\"' || c == '\'') {
    int quote = c; //se guarda que tipo de comilla se ingreso
    w--;

    while((c = getch()) != quote && c != EOF) {
      if(c == '\\'){
        *w++ = c;
        c = getch();
      }
      if(lim > 1){//para no sobrepasar limite del buffer
        *w++ = c;
        lim--;
      }
    }
    *w = '\0';
    return word[0] ? word[0] : quote;
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
