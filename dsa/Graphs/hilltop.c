#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

void readGrid(int rows, int cols, int grid[rows][cols])
{
    // Add code to read in all the elements of grid from standard input.
    // ...
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < cols; j++)
        {
            scanf("%d", &grid[i][j]);
        }
    }
}

// Add parameters to to pass a variable-sized array to the following
// function.  It's the same as the previous function, but I want you
// to get a chance to type it in yourself.
void reportMaxima(int rows, int cols, int grid[rows][cols])
{
    // Add code to find local maxima and print them out in row major order.
    // ...
    int i = 0;
    int j = 0;
    int neighbours[8];
    int maxima = grid[i][j];
    int flag = 0;
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            maxima = grid[i][j];
            flag = 0;
            for (int k = 0; k < 8; k++)
            {
                neighbours[k] = 0;
            }

            if (i == 0 && j == 0)
            {
                neighbours[4] = grid[i][j + 1];
                neighbours[6] = grid[i + 1][j];
                neighbours[7] = grid[i + 1][j + 1];
                flag = 1;
            }

            if (i == 0 && j == cols - 1 && flag == 0)
            {
                neighbours[3] = grid[i][j - 1];
                neighbours[5] = grid[i + 1][j - 1];
                neighbours[6] = grid[i + 1][j];
                flag = 1;
            }

            if (i == rows - 1 && j == cols - 1 && flag == 0)
            {
                neighbours[3] = grid[i][j - 1];
                neighbours[0] = grid[i - 1][j - 1];
                neighbours[1] = grid[i - 1][j];
                flag = 1;
            }

            if (i == rows - 1 && j == 0 && flag == 0)
            {
                neighbours[1] = grid[i - 1][j];
                neighbours[2] = grid[i - 1][j + 1];
                neighbours[4] = grid[i][j + 1];
                flag = 1;
            }

            if (i == 0 && flag == 0)
            {
                neighbours[0] = 0;
                neighbours[1] = 0;
                neighbours[2] = 0;
                neighbours[3] = grid[i][j - 1];
                neighbours[4] = grid[i][j + 1];
                neighbours[5] = grid[i + 1][j - 1];
                neighbours[6] = grid[i + 1][j];
                neighbours[7] = grid[i + 1][j + 1];
                flag = 1;
            }

            if (j == 0 && flag == 0)
            {
                neighbours[0] = 0;
                neighbours[1] = grid[i - 1][j];
                neighbours[2] = grid[i - 1][j + 1];
                neighbours[3] = 0;
                neighbours[4] = grid[i][j + 1];
                neighbours[5] = 0;
                neighbours[6] = grid[i + 1][j];
                neighbours[7] = grid[i + 1][j + 1];
                flag = 1;
            }

            if (i == rows - 1 && flag == 0)
            {
                neighbours[0] = grid[i - 1][j - 1];
                neighbours[1] = grid[i - 1][j];
                neighbours[2] = grid[i - 1][j + 1];
                neighbours[3] = grid[i][j - 1];
                neighbours[4] = grid[i][j + 1];
                neighbours[5] = 0;
                neighbours[6] = 0;
                neighbours[7] = 0;
                flag = 1;
            }

            if (j == cols - 1 && flag == 0)
            {
                neighbours[0] = grid[i - 1][j - 1];
                neighbours[1] = grid[i - 1][j];
                neighbours[2] = 0;
                neighbours[3] = grid[i][j - 1];
                neighbours[4] = 0;
                neighbours[5] = grid[i + 1][j - 1];
                neighbours[6] = grid[i + 1][j];
                neighbours[7] = 0;
                flag = 1;
            }

            if ((i != 0 || j != 0) && flag == 0)
            {
                neighbours[0] = grid[i - 1][j - 1];
                neighbours[1] = grid[i - 1][j];
                neighbours[2] = grid[i - 1][j + 1];
                neighbours[3] = grid[i][j - 1];
                neighbours[4] = grid[i][j + 1];
                neighbours[5] = grid[i + 1][j - 1];
                neighbours[6] = grid[i + 1][j];
                neighbours[7] = grid[i + 1][j + 1];
                flag = 1;
            }

            for (int k = 0; k < 8; k++)
            {
                // printf("%d ", neighbours[k]);
                if (grid[i][j] < neighbours[k])
                {
                    maxima = neighbours[k];
                }
            }
            if (maxima == grid[i][j])
            {
                printf("%d %d\n", i, j);
            }

            // readGrid(rows, cols, grid);

            // printf("%d", maxima);
        }
    }
}

int main()
{
    // Add code to read in the grid size from standard input.
    // ...
    int row_size;
    int column_size;

    printf("Enter the row size: ");
    scanf("%d", &row_size);
    printf("Enter the column size: ");
    scanf("%d", &column_size);
    // Declare a variable-sized array to hold the grid.
    // ...
    printf("Row size: %d\n", row_size);
    printf("Column size: %d\n", column_size);

    int grid[row_size][column_size];
    // Call readGrid() to populate the array.
    // ...
    readGrid(row_size, column_size, grid);
    // Call reportMaxima() to print out all local maxima.
    // ...
    reportMaxima(row_size, column_size, grid);

    return EXIT_SUCCESS;
}
