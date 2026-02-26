#include <stdio.h>
#include "settings.h"
#include <string.h>

void printMatrix(int matrix[SIZE][SIZE])
{
    for (int i = 0; i < SIZE; i++)
    {
        if (i % 3 == 0 && i != 0)
            printf("------+-------+------\n");
        for (int j = 0; j < SIZE; j++)
        {
            if (j % 3 == 0 && j != 0)
                printf("| ");
            else if (matrix[i][j] == 0)
                printf(". ");
            else
                printf("%d ", matrix[i][j]);
        }
        printf("\n");
    }
}

void readManualMatrix(int matrix[SIZE][SIZE])
{
    char buffer[SIZE + 1]; // +1 for null terminator
    for (int i = 0; i < SIZE; i++)
    {
        printf("Enter line %d: ", i + 1);
        do
        {
            scanf(" %s", buffer);
            if (strlen(buffer) != SIZE)
            {
                printf("Invalid input. Please enter exactly %d characters (digits or '.').\n", SIZE);
                continue; // Validate input length
            }
            // else
            break;
        } while (1);
        for (int j = 0; j < SIZE; j++)
        {
            if (buffer[j] == '.')
                matrix[i][j] = 0;
            else
                matrix[i][j] = buffer[j] - '0';
        }
    }
}