#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

#define PREFIX "movies_"
#define FILE_TYPE ".csv"

// Returns the largest file in the specified directory
void getSmallestFile(char* pathname, char* smallestFile){
    DIR* currDir = opendir(pathname);
    struct dirent* pDirent;
    struct stat dirStat;
    off_t smallestSize = -1;

    // Loop through the directory to find the largest file
    while((pDirent = readdir(currDir)) != NULL){

        // Check for correct file prefix and type
        if((strncmp(PREFIX, pDirent->d_name, strlen(PREFIX)) == 0) && strrchr(pDirent->d_name, '.') != NULL && (strncmp(strrchr(pDirent->d_name, '.'), FILE_TYPE, strlen(FILE_TYPE)) == 0)){
            
            // Get stats to compare to largest
            stat(pDirent->d_name, &dirStat);
            
            if (smallestSize < 0 || smallestSize > dirStat.st_size){    
                smallestSize = dirStat.st_size;
                strcpy(smallestFile, pDirent->d_name);
            }
        }
    }

    closedir(currDir);
    return;
}