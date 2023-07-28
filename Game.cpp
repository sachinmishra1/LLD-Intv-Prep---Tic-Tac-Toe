#include "Game.h"
#include <iostream>
using namespace std;

Game::Game(const string& player1Name, const string& player2Name, int boardSize)
    : player1(player1Name, 'X'), player2(player2Name, 'O'), board(boardSize), currentPlayer(&player1), isGameOver(false) {}


void Game::start()
{
    cout << "Tic Tac Toe Game!\n";
    board.display();

    while (!isGameOver)
    {
        playTurn();
        board.display();

        if (board.checkWin(currentPlayer->getSymbol()))
        {
            cout << currentPlayer->getName() << " wins!\n";
            isGameOver = true;
        }
        else if (board.isFull())
        {
            cout << "It's a draw!\n";
            isGameOver = true;
        }
        else
        {
            // Switch to the other player's turn
            currentPlayer = (currentPlayer == &player1) ? &player2 : &player1;
        }
    }
}

void Game::playTurn()
{
    int row, col;
    cout << currentPlayer->getName() << "'s turn. Enter row and column (0-based indexing): ";
    cin >> row >> col;

    while (!board.placeMove(row, col, currentPlayer->getSymbol()))
    {
        cout << "Invalid move. Try again: ";
        cin >> row >> col;
    }
}

bool Game::isDraw() const
{
    return !board.checkWin(player1.getSymbol()) && !board.checkWin(player2.getSymbol()) && board.isFull();
}
