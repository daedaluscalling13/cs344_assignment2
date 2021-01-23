#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>
#include <fcntl.h>
#include <time.h>
#include <unistd.h>
#include "movie.h"

void processPathname(struct movie* list){
    int randSuffix;
    char dirPath[32];
    char filePath[64];
    int dd;
    FILE* pFile = NULL;
    DIR* dirFromFile = NULL;
    struct movie* head = NULL;
    struct movie* next = NULL;
    struct movie* prev = NULL;
    char currYear[5];
    struct movie* currMovie = NULL;
    struct movie* currList = NULL;

    currMovie = list;


    // Make dir
    // Create directory name with random number
    srandom(time(NULL));
    randSuffix = random() % 99999;
    sprintf(dirPath, "kiblerke.movies.%d", randSuffix);
    dd = mkdir(dirPath, 0750);

    // Create and write data to files
    while (currMovie != NULL){
        currList = list;

        // Find the year of the file from the front of the list
        strcpy(currYear, currMovie->year);

        // Create a file with the current string
        sprintf(filePath, "%s/%s.txt", dirPath, currYear);
        
        pFile = fopen(filePath, "wa");
        if (pFile == NULL){
            printf("fopen() failed on %s\n", filePath);
            return;
        }

        while (currList != NULL){
            // Write data to the file
            if (strcmp(currList->year, currMovie->year) == 0){
                fprintf(pFile, currList->title);
                fprintf(pFile, "\n");
            }

            currList = currList->next;
        }

        fclose(pFile);
        chmod(filePath, 0640);

        currMovie = currMovie->next;
    }

    printf("Created direcotry with name %s\n", dirPath);

    return;
}