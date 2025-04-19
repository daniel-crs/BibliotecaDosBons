#include <stdio.h>
#include <stdlib.h>
#include <string.h>


int main(void) {
	
	FILE *stream;
	fopen("data.csv", "r");
  if(stream==NULL){
    fclose(stream);
    return -1;
  }

  float *price=(float*)malloc(sizeof(stream));
  if(price==NULL){
    puts("erro no alocamento");
    return -1;
  }

  char* authors=(char*)malloc(sizeof(stream));
  if(authors==NULL){
    puts("erro no alocamento");
    return -1;
  }

  char* titles=(char*)malloc(sizeof(stream));
  if(titles==NULL){
    puts("error no alocamento");
    return -1;
  }
 //teste 	
  char text[sizeof(stream)];
  while(fgets(text, sizeof(text),stream) != NULL){
    printf("%s",text);
  }

  int option;
  printf("1--ordenar por titulo 2--ordenar por autor 3--ordenar por preco");
  fflush(stdin);
  switch(option){
    case 1:
       //funcao de ordenar por titulo aqui
    case 2:
      //funcao de ordenar por autor
    case 3:
      //funcao ordenar por preco
  }
	
	fclose(stream);
  free(price);
  free(authors);
  free(titles);
	return 0;
}
