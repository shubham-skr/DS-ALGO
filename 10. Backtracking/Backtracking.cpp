/*
    Backtracking Problems

    -- Find all subsets
    -- Find all permutations
    -- Generate all combinations of balanced brackets
    -- Solve n queen problem
    -- Solve 9x9 sudoku

*/

#include <bits/stdc++.h>
using namespace std;


// Find all subsets
void findSubsets(vector<int> &inp, int index)
{
    // stores subsets
    static vector<int> out;
    // Base case
    if (index == inp.size())
    {
        if (out.size() == 0)
            cout << "NULL";
        else
            for (int x : out)
                cout << x << " ";
        cout << endl;
        return;
    }

    // Recursive case
    // Include the ith element
    out.push_back(inp[index]);
    findSubsets(inp, index + 1);
    // Exclude the ith element
    out.pop_back();
    findSubsets(inp, index + 1);
}


// Find all permutations
void findPermutations(vector<int> &inp, int index)
{
    // Base case
    if (index == inp.size())
    {
        for (int x : inp)
            cout << x << " ";
        cout << endl;
    }

    // Recursive case
    for (int i = index; i < inp.size(); i++)
    {
        swap(inp[index], inp[i]);
        findPermutations(inp, index + 1);
        swap(inp[index], inp[i]);
    }
}


// Generate all combinations of balanced brackets
void generateBrackets(int n, int open, int close, int i)
{
    static string output = "";

    // base case
    if (i == 2 * n)
    {
        cout << output << endl;
        return;
    }

    // recursive case
    // for open bracket
    if (open < n)
    {
        output.push_back('(');
        generateBrackets(n, open + 1, close, i + 1);
        output.pop_back();
    }
    // for close bracket
    if (close < open)
    {
        output.push_back(')');
        generateBrackets(n, open, close + 1, i + 1);
        output.pop_back();
    }
}


// Solve n queen problem
void solveNQueen(vector<vector<int>> &board, int n, int i)
{
    // base case
    if (i == n)
    {
        for (auto b : board)
        {
            for (auto x : b)
                cout << x << " ";
            cout << endl;
        }
        cout << endl;
        return;
    }

    // recursive case
    // try to place queen in current row for each column
    for (int j = 0; j < n; j++)
    {
        // check if safe to place in current cell
        bool canPlace = true;

        // column
        for (int k = 0; k < i; k++)
        {
            if (board[k][j] == 1)
                canPlace = false;
        }

        // left diagonal
        int x = i;
        int y = j;
        while (x >= 0 && y >= 0)
        {
            if (board[x][y] == 1)
                canPlace = false;
            x--;
            y--;
        }

        // right diagonal
        x = i;
        y = j;
        while (x >= 0 && y < n)
        {
            if (board[x][y] == 1)
                canPlace = false;
            x--;
            y++;
        }

        // safe to place
        if (canPlace)
        {
            board[i][j] = 1;
            solveNQueen(board, n, i + 1);
        }

        board[i][j] = 0;
    }
}


// Solve 9x9 sudoku
bool solveSudoku(int mat[][9], int i, int j, int n)
{
    // base cases
    if (i == n)
    {
        for (int x = 0; x < n; x++)
        {
            for (int y = 0; y < n; y++)
                cout << mat[x][y] << " ";
            cout << endl;
        }
        return true;
    }

    // recursive cases
    if (j == n)
        return solveSudoku(mat, i + 1, 0, n);

    // skip prefilled cell
    if (mat[i][j] != 0)
        return solveSudoku(mat, i, j + 1, n);

    // try out all possibilities for the cell to be filled
    for (int num = 1; num <= n; num++)
    {
        // true if it safe to fill cell with current value
        bool isSafe = true;
        // check for row and column
        for (int k = 0; k < n; k++)
        {
            if (mat[k][j] == num || mat[i][k] == num)
                isSafe = false;
        }
        // check for subgrid
        int sx = (i / 3) * 3;
        int sy = (j / 3) * 3;
        for (int x = sx; x < sx + 3; x++)
        {
            for (int y = sy; y < sy + 3; y++)
            {
                if (mat[x][y] == num)
                    isSafe = false;
            }
        }

        if (isSafe)
        {
            mat[i][j] = num;
            bool success = solveSudoku(mat, i, j + 1, n);
            if (success)
                return true;
        }
    }
    // if not safe to fill with any number
    mat[i][j] = 0;
    return false;
}


/*

int main()
{
    int sudokuBoard[9][9] = {
            {5, 3, 0, 0, 7, 0, 0, 0, 0},
            {6, 0, 0, 1, 9, 5, 0, 0, 0},
            {0, 9, 8, 0, 0, 0, 0, 6, 0},
            {8, 0, 0, 0, 6, 0, 0, 0, 3},
            {4, 0, 0, 8, 0, 3, 0, 0, 1},
            {7, 0, 0, 0, 2, 0, 0, 0, 6},
            {0, 6, 0, 0, 0, 0, 2, 8, 0},
            {0, 0, 0, 4, 1, 9, 0, 0, 5},
            {0, 0, 0, 0, 8, 0, 0, 7, 9}};

    solveSudoku(sudokuBoard, 0, 0, 9);
    return 0;
}

*/
