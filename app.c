#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void) {
    FILE *stream = fopen("data.csv", "r");
    if (stream == NULL) {
        perror("erro ao abrir o arquivo");
        return -1;
    }

    int i = 0;
    int *price = (int *)malloc(512 * sizeof(int));
    char *author[512];
    char *title[512];
    char text[2048];

    if (price == NULL) {
        fclose(stream);
        puts("erro ao alocar memória");
        return -1;
    }

    fgets(text, 2048, stream); // ignora cabeçalho
    while (fgets(text, 2048, stream) != NULL) {
        char *parser = strtok(text, ",");
        author[i] = strdup(parser);

        parser = strtok(NULL, ",");
        title[i] = strdup(parser);

        parser = strtok(NULL, "\n");
        price[i] = atoi(parser);
        i++;
    }
#ifdef DEBUG
    for(int count=0;count<i;count++){
    printf("%s,%s,%d\n",author[count],title[count],price[count]);
  } 
  
#endif

    int option = 0;
    printf("||0- sair do programa||\n||1--ordenar por titulo||\n||2--ordenar por autor||\n||3--ordenar por preco||\n");
    scanf("%d", &option);

    switch (option) {
        case 0:
            break;
        case 1:
            // TODO: ordenar por título
            break;
        case 2:
            // TODO: ordenar por autor
            break;
        case 3:
            // TODO: ordenar por preço
            break;
        default:
            puts("erro: opcao invalida");
            break;
    }

    fclose(stream);
    for (int j = 0; j < i; j++) {
        free(author[j]);
        free(title[j]);
    }
    free(price);

    return 0;
}
