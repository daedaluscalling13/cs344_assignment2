#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Prompt was not a valid choice, notify user.
void invalidPrompt(void)
{
    printf("You entered an incorrect choice. Try again.\n");
    return;
}