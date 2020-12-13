#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

enum
{
    GRIDCOLS = 9,
    GRIDROWS = 9
};

void show_grid(char grid[9][9][50], char *cellnum, char *p_val)
{
    printf("I am the grid\n");
    // define the column names
    char cols[GRIDCOLS] = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I'};
    printf(" ");
    for (int i = 0; i < GRIDCOLS; i++)
        printf("%*c", 9, cols[i]);

    for (int i = 1; i <= GRIDROWS; i++)
    {
        // print the row number 
        printf("\n%d", i);
        for (int j = 0; j < GRIDCOLS; j++)
        {
            char *c_val = grid[i - 1][j];
            printf("%*s", 9, c_val);
        }
    }
    printf("\n\nPervious input =>  Cell Number: %s, Value: %s\n\n", cellnum, p_val);
}

int validate_cell(int row_num, int col_num)
{
    if (col_num < 0 || col_num > (GRIDCOLS - 1))
    {
        return 1;
    }
    if (row_num < 0 || row_num > (GRIDROWS - 1))
    {
        return 1;
    }
    return 0;
}

int main(void)
{
    char cell_num[3];
    char val[50];
    char grid[GRIDROWS][GRIDCOLS][50];

    // fill in the grid with dash
    for (int i = 0; i < GRIDROWS; i++)
    {
        for (int j = 0; j < GRIDCOLS; j++)
        {
            strcpy(grid[i][j], "_");
        }
    }

    while (1)
    {
        // user input cell number
        printf("Enter the cell number or quit: ");
        scanf("%s", cell_num);

        // quit if the user input is 'quit'
        if (strcmp(cell_num, "quit") == 0)
            return 0;

        // extract the row's and col's num from the given cell
        int col = ((int)toupper(cell_num[0])) - 'A';
        int row = ((int)(cell_num[1] - '0')) - 1;

        // validate the row and col numbers
        if (validate_cell(row, col) == 1)
        {
            printf("Cell is not valid\n");
        }
        else
        {
            // user input the value to insert
            printf("Enter the value: ");
            scanf("%s", val);

            // update the value of the grid cell
            strcpy(grid[row][col], val);

            // show the grid
            show_grid(grid, cell_num, val);
        }
    }
    return 0;
}