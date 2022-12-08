#include <stdio.h>
#define SIZE 52

struct Person* create_node(char *name, char *surname, char *number, char *email);

struct Person {
    char name[SIZE];
    char surname[SIZE];
    char number[SIZE];
    char email[SIZE];
    struct Person *next;
};