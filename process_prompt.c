#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process_prompt.h"

// Outputs user options for processing a file.
// Receives input from user. Does not check user input for valid prompt.
int receiveProcessPrompt(void){
    printf("\n");
    printf("While file do you want to process?\n");
    printf("Enter 1 to pick the largest file\n");
    printf("Enter 2 to pick the smallest file\n");
    printf("Enter 3 to specify the name of a file\n");
    printf("\n");
    printf("Enter a choice from 1 to 3: ");
    
    char* prompt = calloc(sizeof(char), 16);
    scanf("%s", prompt);
    int iPrompt = atoi(prompt);
    free(prompt);
    return iPrompt;
}