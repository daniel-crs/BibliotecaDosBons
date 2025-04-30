#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void order_string(char* first_str[], char* second_str[], int price[], int size) {
    int flag = 1, i;
    while(flag) {
        flag = 0;
        for (i = 0; i < size - 1; i++) {
            if (strcmp(first_str[i], first_str[i + 1]) > 0) {
                char* tempTitle = first_str[i];
                first_str[i] = first_str[i + 1];
                first_str[i + 1] = tempTitle;

                char* tempAuthor = second_str[i];
                second_str[i] = second_str[i + 1];
                second_str[i + 1] = tempAuthor;

                int tempPrice = price[i];
                price[i] = price[i + 1];
                price[i + 1] = tempPrice;

                flag = 1;
            }
        }
    }
}

void order_price(int price[], char* title[], char* author[], int size) {
    int flag = 1, i;
    while(flag) {
        flag = 0;
        for (i = 0; i < size - 1; i++) {
            if (price[i] > price[i + 1]) {
                int tempPrice = price[i];
                price[i] = price[i + 1];
                price[i + 1] = tempPrice;
				
				char* tempTitle = title[i];
                title[i] = title[i + 1];
                title[i + 1] = tempTitle;

                char* tempAuthor = author[i];
                author[i] = author[i + 1];
                author[i + 1] = tempAuthor;

                flag = 1;
            }
        }
    }
}

void produce_new_archive(char* titles[], char* authors[], int* price, int size) {
    int c, i;
    while ((c = getchar()) != '\n' && c != EOF);

    char name_A[20];
    puts("digite o nome do arquivo:");
    fgets(name_A, 20, stdin);
    name_A[strcspn(name_A, "\n")] = 0;
    strcat(name_A,".csv");

    FILE *fp = fopen(name_A, "w");
    if (fp == NULL) {
        perror("erro ao criar arquivo");
        return;
    }

    fprintf(fp, "titulo,autor,preço\n");
    for (i = 0; i < size; i++) {
        fprintf(fp, "%s,%s,%d\n", titles[i], authors[i], price[i]);
    }

    fclose(fp);
}

