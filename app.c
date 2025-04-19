#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 549

int main(void) {
	int i;
	char title[MAX][250], author[MAX][250];
	float price[MAX];
	
	FILE *stream;
	fopen("data.csv", "r");
	
	for(i = 0; i < MAX; i++) {
		fscanf(stream, "%s", &title[i]);
		fscanf(stream, "%s", &author[i]);
		fscanf(stream, "%f", &price[i]);
	}
	
	for(i = 0; i < MAX; i++) {
		printf("%s", title[i]);
		printf("%s", author[i]);
		printf("%f", price[i]);
	}
	
	fclose(stream);
	return 0;
}
