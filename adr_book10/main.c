#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <signal.h>
#include "list.h"
#include "window.h"
#include "function.h"

#define SIZE 52

static int run = 1;

void sigint_handler(int signum) {
    printf("SIGINT INITIATED\n");
}

void sigquit_handler(int signum) {
    printf("QUIT SIGNAL INITIATED\n");
    run = 0;
}

int main(void) {

    signal(SIGINT, sigint_handler);
    signal(SIGQUIT, sigquit_handler);

    char adr_file_path[SIZE] = "data.csv";
    struct Person *list = NULL;
    FILE *adr_file = NULL;

    adr_file = fopen(adr_file_path, "r");
    if(adr_file == NULL) {
        printf("Unable to open file\n");
        exit(1);
    }

    load_addresses(adr_file, &list);
    fclose(adr_file);

    char ctrl[12];

    int ind = -1;

    drawLine();
    drawFunctions();
    drawLine();
    helpWindow();
    drawLine();

    while(run) {
        printf("What function to perform?\n");
        scanf(" %10[^\n]s", ctrl);
        clearInput();
        switch(*ctrl) {
            case '0': //draw functions
                drawFunctions();
                break;
            case '1': //print list
                print_list(list);
                printf("Amount: %d\n",getSize(list));
                break;
            case '2': //add element to the end
                func_add(&list);
                break;
            case '3': //add element by index
                func_add_index(&list);
                break;
            case '4': //remove element by index
                func_remove_index(&list);
                break;
            case '5': //destroy list
                printf("Destroying list ...\n");
                delete_list(&list);
                //goto CLEAN_UP;
                break;
            case '6': //find person by index
                func_find_index(list);
                break;
            case '7': //find person by chosen criteria
                func_find_criteria(list);
                break;
            case '8': //help window
                helpWindow();
                break;
            case '9':
                printf("Stopping program...\n");
                run = 0;
                break;
            default:
                printf("Did not select viable option, try again\n");
                break;
        }
    }
    delete_list(&list);
    return 0;
}

