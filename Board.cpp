#include "Board.h"
#include <bits/stdc++.h>

using namespace std;

Board::Board(int n) : size(n), board(n, vector<char>(n, ' ')) {}

void Board::display() const
{
    // Display the current state of the board
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            cout << " " << board[i][j];
            if (j < size - 1)
                cout << " |";
        }
        cout << "\n";
        if (i < size - 1)
        {
            for (int j = 0; j < size; ++j)
                cout << "----";
            cout << "\n";
        }
    }
}

bool Board::isFull() const
{
    // Check if the board is full
    for (int i = 0; i < size; ++i)
    {
        for (int j = 0; j < size; ++j)
        {
            if (board[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}

bool Board::placeMove(int row, int col, char symbol)
{
    // Place a move on the board at the specified position
    if (row < 0 || row >= size || col < 0 || col >= size || board[row][col] != ' ')
    {
        return false; // Invalid move
    }
    board[row][col] = symbol;
    return true;
}

bool Board::checkWin(char symbol) const
{
    // Check if the player with the given symbol has won
    for (int i = 0; i < size; ++i)
    {
        // Check rows and columns
        bool rowWin = true;
        bool colWin = true;
        for (int j = 0; j < size; ++j)
        {
            if (board[i][j] != symbol)
                rowWin = false;
            if (board[j][i] != symbol)
                colWin = false;
        }
        if (rowWin || colWin)
            return true;
    }

    // Check diagonals
    bool mainDiagWin = true;
    bool antiDiagWin = true;
    for (int i = 0; i < size; ++i)
    {
        if (board[i][i] != symbol)
            mainDiagWin = false;
        if (board[i][size - 1 - i] != symbol)
            antiDiagWin = false;
    }
    if (mainDiagWin || antiDiagWin)
        return true;

    return false;
}
