#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "person.h"

#define DELIMETER ","

void clearInput() {
    while(getchar() != '\n' && getchar() != EOF) {}
}

int main(void) {
    char* data = NULL;
    data = (char *)malloc(sizeof(char)*30);
    char* data2 = NULL;
    data2 = (char *)malloc(sizeof(char)*30);
    char* token;
    int index = -1;

    printf("Write your output\n");
    scanf("%30[^\n]s", data);
    printf("%s\n", data);
    printf("Write index\n");
    scanf("%2d", &index);
    printf("Wrote: %d",index);
    free(data);
    free(data2);
    return 0;
}
