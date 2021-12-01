#include <iostream>
#include <string>
#include <unistd.h>

#include "termio.hpp"
#include "menu.hpp"

const std::string Menu[6] = { "\u2329Start Game \u232A","\u2329How to play \u232A","\u2329Options \u232A", "\u2329About \u232A","\u2329Score \u232A","\u2329Exit \u232A" };

void GameMenu::print_GameName()
{
	std::cout << "\033[;1m"<< std::flush;
	std::cout << "\t\t\t\t****************************************************************************************" << "\n";
	std::cout << "\t\t\t\t*	*******    ********   **         **    ********    *******     *****    *****  *" << "\n";
	std::cout << "\t\t\t\t*	**   **    **	       **       **     **          **   **    **          *    *" << "\n";
	std::cout << "\t\t\t\t*	**  **     **		**     **      **	   **  **      **         *    *" << "\n";
	std::cout << "\t\t\t\t*	*****	   ********      **   **       ********    *****         **       *    *" << "\n";
	std::cout << "\t\t\t\t*	**  **	   **             ** **        **	   **  **         **      *    *" << "\n";
	std::cout << "\t\t\t\t*	**   **    **              ***         **          **   **        **      *    *" << "\n";
	std::cout << "\t\t\t\t*       **    **   ********         *          ********    **     **   ****     *****  *" << "\n";
	std::cout << "\t\t\t\t****************************************************************************************" << "\n";
	std::cout << "\033[0m" << std::flush;
}

void GameMenu::print_Loading()
{

	system("clear");

	gotoxy(70,15);
	std::cout << "\033[;1mLoading...\033[0m" << std::flush;
	gotoxy(50, 17);
	for (int i = 0; i < 40; ++i) {
		std::cout << "\033[96;2m\u2588" << std::flush;
		if (i < 20) {
			usleep(80000);
		} else {
			usleep(50000);
		}
	}
	system("clear");
	std::cout << "\033[0m"; //Back to normal (remove all styles)
}



void GameMenu::print_Menu(int greenID)
{
    const int x = 70;
    int init_Y = 15;
    int y = greenID * 2 + init_Y;

    gotoxy(x - 5, y); //initial position of the arrow
    std::cout << "\u279C" << std::flush;
    for (int i = 0; i < 6; ++i){
        gotoxy(x, init_Y);
        if (i == greenID) {
            std::cout << "\033[92;1m" << Menu[i] << "\033[0m" << std::flush;
        } else {
            std::cout << Menu[i] << std::flush;
        }
        init_Y += 2;
    }
    gotoxy(x - 5, y);
    std::cout << std::flush;
}

