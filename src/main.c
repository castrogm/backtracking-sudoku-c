#include <stdio.h>
#include <time.h>
#include "display.h"
#include "check.h"
#include "settings.h"
#include "solver.h"
#include "files.h"

int main()
{
    int matrix[SIZE][SIZE]; // Initialize the Sudoku matrix
    char ender;             // Variable to consume the newline character after reading the matrix

    printf("What mode do you want to use?\n1- Manual input\n2- File input (.txt)\n");
    char mode;
    do
    {
        printf("Enter your choice: ");
        scanf(" %c", &mode); // Reads the user's choice for input mode
        if (mode != '1' && mode != '2')
        {
            printf("Invalid choice. Please enter 1 or 2.\n");
        }
    } while (mode != '1' && mode != '2');

    if (mode == '1')
        readManualMatrix(matrix);
    else
    {
        if (readFileMatrix(matrix))
        {
            printf("Error reading file.\n");
            return 1;
        }
    }
    printf("Sudoku Matrix:\n");
    printMatrix(matrix);

    clock_t start = clock(); // Starts the clock to measure the time taken to solve the Sudoku
    int backtracks = 0;      // Variable to count the number of backtracking steps
    int recursive_calls = 0; // Variable to count the number of recursive calls

    if (start_solver(matrix, &backtracks, &recursive_calls))
    {
        clock_t end = clock(); // Ends the clock after solving the Sudoku
        double time_spent = ((double)(end - start)) / CLOCKS_PER_SEC;
        printf("Solution found in %.3f seconds:\nNumber of backtracks: %d\nNumber of recursive calls: %d\n",
               time_spent, backtracks, recursive_calls);

        printMatrix(matrix); // Prints the solved Sudoku matrix

        printf("Would you like to save the solution to a file? (y/n): ");
        char saveChoice;
        scanf(" %c", &saveChoice); // Read the choice, with a space before %c to consume any whitespace
        if (saveChoice == 'y' || saveChoice == 'Y')
        {
            if (writeFileMatrix(matrix))
            {
                printf("Error writing to file.\n");
            }
        }
    }
    else
    {
        printf("No solution found for the given Sudoku.\n");

        printf("Press Enter to exit...");
        scanf(" %c", &ender); // Waits for the user to press Enter before exiting
    }

    return 0;
}