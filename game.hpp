#pragma once

#include <string>
#include <fstream>
#include "termio.hpp"
#include "gameboard.hpp"

class Game
{
public:
    void play();

private:
    void currentMenu();
    void handleKeyPress();
    void mainMenu(int);
    void startGame();
    void rules();
    void options();
    void about();
    void score();
    int  getBoardSize();

private:
    void loading() const;
    void printName() const;
    void printMenu(int id = 0) const;

private:
    bool m_isRunning = true ;
    int m_firstIndex = 0;
    int m_lastIndex = 0;
    int m_firstY = 15;
    int m_lastY = 15;

    GameBoard m_board;
    keyboard m_key;

    static const std::string m_menu[6];
};
