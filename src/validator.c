#include <string.h>
#include "settings.h"

int isValidLine(char line[SIZE + 1])
{
    if (strlen(line) != SIZE)
        return 0; // Invalid length

    // else

    for (int i = 0; i < SIZE; i++)
    {
        if (line[i] != '.' && (line[i] < '1' || line[i] > '9'))
            return 0; // Invalid character detected
    } // else

    return 1; // Valid line
}