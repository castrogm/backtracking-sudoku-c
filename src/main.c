#include <stdio.h>
#include <time.h>
#include "display.h"
#include "check.h"
#include "settings.h"
#include "solver.h"

int main()
{
    int matrix[SIZE][SIZE]; // Initialize the Sudoku matrix
    char ender;             // Variable to consume the newline character after reading the matrix

    readMatrix(matrix);
    printf("Sudoku Matrix:\n");
    printMatrix(matrix);

    clock_t start = clock(); // Starts the clock to measure the time taken to solve the Sudoku
    if (start_solver(matrix))
    {
        clock_t end = clock(); // Ends the clock after solving the Sudoku
        double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Solution found in %.2f seconds:\n", time_spent);

        printMatrix(matrix); // Prints the solved Sudoku matrix

        printf("Press Enter to exit...");
        scanf("%c", &ender); // Waits for the user to press Enter before exiting
    }
    else
    {
        printf("No solution found for the given Sudoku.\n");

        printf("Press Enter to exit...");
        scanf("%c", &ender); // Waits for the user to press Enter before exiting
    }

    return 0;
}