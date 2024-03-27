#include <iostream>
#include <vector>

const int N = 9;

// Function to print the Sudoku grid
void printGrid(std::vector<std::vector<int>> &grid)
{
    for (int row = 0; row < N; row++)
    {
        for (int col = 0; col < N; col++)
        {
            std::cout << grid[row][col] << " ";
        }
        std::cout << std::endl;
    }
}

// Function to check if a number is safe to place in a cell
bool isSafe(std::vector<std::vector<int>> &grid, int row, int col, int num)
{
    for (int i = 0; i < N; i++)
    {
        if (grid[row][i] == num || grid[i][col] == num)
        {
            return false;
        }
    }

    int startRow = row - row % 3;
    int startCol = col - col % 3;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            if (grid[startRow + i][startCol + j] == num)
            {
                return false;
            }
        }
    }

    return true;
}

// Sudoku solver using backtracking
bool solveSudoku(std::vector<std::vector<int>> &grid)
{
    int row, col;
    bool isEmpty = true;

    for (row = 0; row < N; row++)
    {
        for (col = 0; col < N; col++)
        {
            if (grid[row][col] == 0)
            {
                isEmpty = false;
                break;
            }
        }
        if (!isEmpty)
        {
            break;
        }
    }

    if (!isEmpty)
    {
        for (int num = 1; num <= 9; num++)
        {
            if (isSafe(grid, row, col, num))
            {
                grid[row][col] = num;

                if (solveSudoku(grid))
                {
                    return true;
                }

                grid[row][col] = 0;
            }
        }
    }
    else
    {
        return true;
    }

    return false;
}

int main()
{
    std::vector<std::vector<int>> grid = {
        {5, 3, 0, 0, 7, 0, 0, 0, 0},
        {6, 0, 0, 1, 9, 5, 0, 0, 0},
        {0, 9, 8, 0, 0, 0, 0, 6, 0},
        {8, 0, 0, 0, 6, 0, 0, 0, 3},
        {4, 0, 0, 8, 0, 3, 0, 0, 1},
        {7, 0, 0, 0, 2, 0, 0, 0, 6},
        {0, 6, 0, 0, 0, 0, 2, 8, 0},
        {0, 0, 0, 4, 1, 9, 0, 0, 5},
        {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    if (solveSudoku(grid))
    {
        std::cout << "Solved Sudoku:" << std::endl;
        printGrid(grid);
    }
    else
    {
        std::cout << "No solution exists." << std::endl;
    }

    return 0;
}
