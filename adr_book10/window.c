#include <stdio.h>
#include <string.h>
#include "window.h"

#define SIZE 64

void drawLine() {
    printf("%0*d\n", SIZE, 0);
}

void drawFunctions() {
    printf("        Functions       \n");
    printf("[1] - view list\n");
    printf("[2] - add element to end\n");
    printf("[3] - add element by index\n");
    printf("[4] - remove element by index\n");
    printf("[5] - destroy list\n");
    printf("[6] - find person by index\n");
    printf("[7] - find person by chosen criteria\n");
    printf("[8] - help\n");
}

void helpWindow() {
    printf("        Search options      \n");
    printf("[10] - searches by name\n");
    printf("[11] - searches by surname\n");
    printf("[12] - searches by email\n");
    printf("[13] - searches by number\n");
    printf("\n");
    printf("        Program options     \n");
    printf("[9] - quits program\n");
    printf("[0] - function window\n");
}