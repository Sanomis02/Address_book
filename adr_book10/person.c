#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#include "person.h"

 #define DELIMETER ","

struct Person* create_address_node(char *address_line)
{
    struct Person *person = NULL;
    char *name = NULL;
    char *surname = NULL;
    char *number = NULL;
    char *email = NULL;

    name = strtok(address_line, DELIMETER);
    if(name == NULL)
        name = "NaN";
    surname = strtok(NULL, DELIMETER);
    if(surname == NULL)
        surname = "NaN";
    number = strtok(NULL, DELIMETER);
    if(number == NULL)
        number = "NaN";
    email = strtok(NULL, DELIMETER);
    if(email == NULL)
        email = "NaN";
    person = create_node(name, surname, number, email);
    
    return person;
}

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