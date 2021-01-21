#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Output prompt options and receive a prompt input.
int receivePrompt(void)
{
    printf("\n");
    printf("1. Select file to process\n");
    printf("2. Exit the program\n");
    printf("\n");
    printf("Enter a choice 1 or 2: ");
    
    char* prompt = calloc(sizeof(char), 16);
    scanf("%s", prompt);
    int iPrompt = atoi(prompt);
    free(prompt);
    return iPrompt;
}