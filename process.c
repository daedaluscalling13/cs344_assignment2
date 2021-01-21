#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process_prompt.h"
#include "invalid_prompt.h"

void userProcessFile(void){

    // flag
    int fileProcessed = 0;
    int prompt;

    while(!fileProcessed){
        prompt = receiveProcessPrompt();
        switch(prompt){
            case 1:
                printf("You picked %i", prompt);
                fileProcessed = 1;
                break;
            case 2:
                printf("You picked %i", prompt);
                fileProcessed = 1;
                break;
            case 3:
                printf("You picked %i", prompt);
                fileProcessed = 1;
                break;
            default:
                invalidPrompt();
                break;
        }
    }
}