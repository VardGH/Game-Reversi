#pragma once
#include "termio.hpp"

class GameBoard
{
public:
    GameBoard()
        : m_xCoord(69)
        , m_yCoord(17)
        , m_color(0)
        , m_blackCount(2)
        , m_whiteCount(2)
        , m_isRunning(true)
    {
        m_mat = new char* [s_boardHeight];
        for (int i = 0; i < s_boardHeight; ++i) {
            m_mat[i] = new char [s_boardWidth];
        }
    }

    ~GameBoard()
    {
        for (int i = 0; i < s_boardHeight; ++i) {
            delete [] m_mat[i];
        }
        delete [] m_mat;
    }

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
    void handleKeyPress();

private:
    static const int s_boardHeight = 8;
    static const int s_boardWidth = 8;

    keyboard m_key;
    int m_xCoord;
    int m_yCoord;
    int m_color;
    int m_blackCount;
    int m_whiteCount;
    bool m_isRunning;
    char** m_mat;
};


