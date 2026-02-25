#include <stdio.h>
#include "settings.h"

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
        printf("Digite os caracteres da linha %d: ", i + 1);
        scanf("%s", buffer);
        for (int j = 0; j < SIZE; j++)
        {
            if (buffer[j] == '.')
                matrix[i][j] = 0;
            else
                matrix[i][j] = buffer[j] - '0';
        }
    }
}