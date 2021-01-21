#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "process_prompt.h"
#include "invalid_prompt.h"
#include "largest_file.h"
#include "smallest_file.h"
#include "user_file.h"
#include "process_file.h"
#include "movie.h"
#include "process_pathname.h"

// Prompt the user to choose a file.
// The file is then processed as per the specifications.
void userProcessFile(void){

    int proceed = 0; //Flag
    int prompt;
    char pathname[256] = "";

    while(!proceed){
        prompt = receiveProcessPrompt();
        switch(prompt){
            case 1:
                // Get largest file pathname
                getLargestFile(".", pathname);
                printf("The file selected was %s\n", pathname);
                proceed = 1;
                break;
            case 2:
                // Get smallest file pathname
                getSmallestFile(".", pathname);
                printf("The file selected was %s\n", pathname);
                proceed = 1;
                break;
            case 3:
                // Get file from the user
                getUserPathname(pathname);
                if (strcmp(pathname, "") != 0){
                    proceed = 1;
                }
                printf("The file selected was %s\n", pathname);
                break;
            default:
                invalidPrompt();
                break;
        }
    }

    // Process file from fd
    printf("Now processing the chosen file named %s\n", pathname);
    struct movie* movieList = processFile(pathname);
    processPathname(movieList);
}