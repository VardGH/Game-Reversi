#include <iostream>

#include "termio.hpp"
#include "menu.hpp"
#include "gameintro.hpp"
#include "gameboard.hpp"

int main()
{
    GameMenu::print_Loading();
    GameMenu::print_GameName();
    GameMenu::print_Menu();

    while (start){
        Menu_Keypress();
    }

    key.reset_terminal();

    system("clear");
    GameBoard board;
    board.play();

    return 0;
}
