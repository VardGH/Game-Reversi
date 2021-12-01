#pragma once
#include "termio.hpp"

class GameBoard
{
public:
    GameBoard()
        :
         _X(69)
        , _Y(17)
        , color(0)
        , blackCount(2)
        , whiteCount(2)
        , isRunning(true)
    {}

    void play();

private:
    bool check();
    bool checkLeft();
    bool checkRight();
    bool checkUp();
    bool checkDown();

    bool checkUpLeftDiagonal();
    bool checkUpRightDiagonal();
    bool checkDownRightDiagonal();
    bool checkDownLeftDiagonal();

private:
    void printBoard();
    void printWinner();
    void updateCountBlas(int black, int white);
    void handleKeyPress();

private:
    static const int boardHeight = 8;
    static const int boardWidth = 8;

    keyboard k;
    int _Y;
    int _X;
    int color;
    int blackCount;
    int whiteCount;
    bool isRunning;
    char mat[][boardWidth];
};



