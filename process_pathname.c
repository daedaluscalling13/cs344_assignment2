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
    char* dirPath;
    char* filePath;
    int dd;
    int fd;
    DIR* dirFromFile;
    struct movie* head;
    struct movie* next;
    struct movie* prev;
    char* currYear;
    char* strToWrite;
    struct movie* currMovie;
    struct movie* currList;

    currMovie = list;


    // Make dir
    // Create directory name with random number
    srandom(time(NULL));
    randSuffix = random() % 99999;
    sprintf(dirPath, "kiblerke.movies.%d", randSuffix);
    dd = mkdir(dirPath, 0750);

    // Open dir
    dirFromFile = opendir(dirPath);

    // Create and write data to files
    while (currMovie != NULL){
        currList = list;

        // Find the year of the file from the front of the list
        strcpy(currYear, currMovie->year);

        // Create a file with the current string
        sprintf(filePath, "%s.txt", currYear);
        
        fd = open(filePath, O_RDWR | O_CREAT, 0640);
        if (fd == -1){
            printf("open() failed on %s\n", filePath);
        }

        while (currList != NULL){
            // Write data to the file
            if (strcmp(currList->year, currMovie->year)){
                sprintf(strToWrite, "%s\n", currList->title);
                int numWritten = write(fd, strToWrite, strlen(strToWrite));
            }

            currList = currList->next;
        }

        currMovie = currMovie->next;
    }

    return;
}