#include "structs.h"
#define BUFF_SIZE 256
#include <stdio.h>
#define PROMPT "structs> "
int main(){
  
  char buffer[BUFF_SIZE];
  while(getword(buffer, BUFF_SIZE) != EOF)
    printf("%s\n", buffer);
  
  return 0;
}
