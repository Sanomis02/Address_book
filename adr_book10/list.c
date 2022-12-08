#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "list.h"

int size = 0;

void add_to_list(struct Person **list, struct Person *person)
{
    struct Person* temp = *list;
    if (temp == NULL) {
        *list = person;
        size++;
        return; 
    }

    while (temp->next != NULL) {
        temp = temp->next;
    }
    temp->next = person;
    size++;
}

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

void add_by_index(struct Person **list, struct Person *person, int ind) {
    if(person == NULL)
        return;
    if(size == 0) {
        *list = person;
        size++;
        return;
    }  

    struct Person *node = find_node(*list, ind);
    struct Person *temp = node->next;

    node->next = NULL;
    node->next = person;
    person->next = temp;
    size++;
}

struct Person* find_node(struct Person *list, int ind) {
    if(ind > size-1 || ind < 0) {
        printf("index out of range\n");
        return create_address_node(" ");
    }

    struct Person *node = NULL;
    struct Person *temp = list;

    for(int i = 0; i <= ind; i++) {
        node = temp;
        temp=temp->next;
    }
    return node;
}

struct Person* find_node_text(struct Person *list, int option, char *data) {
    if(list == NULL) {
        printf("Empty list, can not find\n");
        return NULL;
    }
    struct Person *to_find = NULL;
    switch(option) {
        case 10: //find by name
            while(list != NULL) {
                if(strcmp(list->name,data) == 0)
                    return list;
                list = list->next;
            }
            return NULL;
        case 11: //find by surname
            while(list != NULL) {
                if(strcmp(list->surname,data) == 0)
                    return list;
                list = list->next;
            }
            return NULL;
        case 12: //find by email
            while(list != NULL) {
                if(strcmp(list->email,data) == 0)
                    return list;
                list = list->next;
            }
            return NULL;
        case 13: //find by number
            while(list != NULL) {
                if(strcmp(list->number,data) == 0)
                    return list;
                list = list->next;
            }
            return NULL;
        default:
            printf("Choose valid option\n");
            return NULL;            
    }
}

int remove_by_index(struct Person **list, int ind) {
    struct Person *prev = *list;
    struct Person *temp = *list;
    int i = 0;
    if(*list == NULL) {
        return 1;
    }
    while(temp != NULL) {
        if(ind == i) {
            prev->next = temp->next;
            free(temp);
            return 0;
        }
        prev = temp;
        temp = temp->next;
        i++;
    }
    return 0;
}

void print_list(struct Person *list)
{
    if(list == NULL) {
        printf("empty list, can not print\n");
        return;
    }
    struct Person *temp = list;
    int i = 0;
    while (temp != NULL) {
        printf("[%d] %s %s %s %s",i,temp->name, temp->surname, temp->number, temp->email);
        temp = temp->next;
        i++;
    }
}

void delete_list(struct Person **list) 
{
    struct Person *to_delete = *list;
    while (*list != NULL) {
        *list = (*(list))->next;
        free(to_delete);
        to_delete = *list;
    }
    size = 0;
}

void load_addresses(FILE *file, struct Person **list)
{
    char line[128];
    while (fgets(line, sizeof(line), file)) {
        struct Person *person = NULL;
         if (strcmp(line, "\n") == 0) {
             continue;
         }
        person = create_address_node(line);
        if (person != NULL) {
            add_to_list(list, person);
        }
    }
}

int getSize(struct Person *list) {
    size = 0;
    struct Person *temp = list;
    while(temp != NULL) {
        temp = temp->next;
        size++;
    }
    return size;
}
