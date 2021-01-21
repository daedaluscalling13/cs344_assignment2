#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <dirent.h>

void getUserPathname(char* pathname){

    struct stat dirStat;

    // Get a file name
    printf("Enter the complete file name: ");
    scanf("%s", pathname);

    // If the 
    if (stat(pathname, &dirStat) != 0){
        printf("The file %s was not found. Try again.\n", pathname);
        strcpy(pathname, "");
    }

    return;

}