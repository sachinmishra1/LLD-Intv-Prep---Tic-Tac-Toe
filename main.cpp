#include "Game.h"
#include <iostream>
using namespace std;

int main() {
    int boardSize;
    string player1Name, player2Name;

    cout << "Enter the board size (N): ";
    cin >> boardSize;

    cout << "Enter Player 1's name: ";
    cin >> player1Name;
    cout << "Enter Player 2's name: ";
    cin >> player2Name;

    Game ticTacToe(player1Name, player2Name, boardSize);
    ticTacToe.start();

    return 0;
}
