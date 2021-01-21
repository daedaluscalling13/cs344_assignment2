// If you are not compiling with the gcc option --std=gnu99, then
// uncomment the following line or you might get a compiler warning
//#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"
#include "process.h"
#include "prompt.h"
#include "invalid_prompt.h"

/*
*   Process the file provided as an argument to the program to
*   create a linked list of student structs and print out the list.
*   Compile the program as follows:
*       gcc --std=gnu99 -o movies movies.c
*/

int main(int argc, char *argv[])
{
    // if (argc < 2)
    // {
    //     printf("You must provide the name of the file to process\n");
    //     printf("Example usage: ./movies movies_info.txt\n");
    //     return EXIT_FAILURE;
    // }

    // struct movie* list = processFile(argv[1]);

    int prompt;
    do{
        prompt = receivePrompt();
        switch(prompt){
            case 1:
                userProcessFile();
                break;
            case 2:
                break;
            default:
                invalidPrompt();
                break;
        }
    } while(prompt != 2);   

    return EXIT_SUCCESS;
}