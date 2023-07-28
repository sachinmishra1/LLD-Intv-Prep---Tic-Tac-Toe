#ifndef BOARD_H
#define BOARD_H

#include<bits/stdc++.h>
using namespace std;

class Board {
private:
    int size;
    vector<vector<char>> board;

public:
    Board(int size);
    void display() const;
    bool isFull() const;
    bool placeMove(int row, int col, char symbol);
    bool checkWin(char symbol) const;
};

#endif
