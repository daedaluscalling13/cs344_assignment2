#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "movie.h"

void freeList(struct movie* list){
    struct movie* currMovie;

    while (list != NULL){
        currMovie = list;
        list = list->next;
        free(currMovie->title);
        free(currMovie->year);
        free(currMovie);
    }
}