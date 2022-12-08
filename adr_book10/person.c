#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "person.h"

#define DELIMETER ","

struct Person* create_node(char *name, char *surname, char *number, char *email)
{
    struct Person *person = NULL;
    person = (struct Person*)malloc(sizeof(struct Person));
    if (person == NULL) {
        return NULL;
    }
    strncpy(person->name, name, SIZE - 1);
    strncpy(person->surname, surname, SIZE - 1); 
    strncpy(person->number, number, SIZE - 1); 
    strncpy(person->email, strcat(email,"\n"), SIZE-1);
    person->next = NULL;

    return person;
}
