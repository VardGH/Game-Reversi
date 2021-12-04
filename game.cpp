#include <cstdlib>
#include <iostream>
#include <unistd.h>

#include "game.hpp"
#include "keyhandler.hpp"


const std::string Game::m_menu[6] = { "\u2329Start Game \u232A","\u2329How to play \u232A","\u2329Options \u232A", "\u2329About \u232A","\u2329Score \u232A","\u2329Exit \u232A" };

void Game::play()
{
    loading();
    printName();
    printMenu();

    while (m_isRunning) {
        handleKeyPress();
    }

    m_key.reset_terminal();

    system("clear");
    m_board.play();
}

void Game::handleKeyPress()
{
    if(m_key.kbhit()) {
        m_lastY = m_firstY;
        m_lastIndex = m_firstIndex;
        switch(static_cast<KeyPressHandler::Key>(m_key.getch())) {
            case KeyPressHandler::Key::ENTER : {
                mainMenu(m_firstIndex);
                system("clear");
                printName();
                printMenu(m_firstIndex);
                break;
            }
            case KeyPressHandler::Key::UP: {
                m_firstY -= 2;
                if (m_firstY < 15) {
                    m_firstY = 25;
                    m_firstIndex = 5;
                } else
                    --m_firstIndex;
                break;
            }
            case KeyPressHandler::Key::DOWN: {
                m_firstY += 2;
                if (m_firstY > 25){
                    m_firstY = 15;
                    m_firstIndex = 0;
                } else
                    ++m_firstIndex;
                break;
            }
        }
        if (m_lastIndex != m_firstIndex) {
            currentMenu();
        }
    }
}

void Game::mainMenu(int index_Menu)
{
    gotoxy(0,14);
    std::cout << "\033[0J" << std::flush;
    switch(index_Menu) {
        case 0 : {
            m_isRunning = false;
            startGame();
            break;
        }
        case 1 : rules(); break;
        case 2 : options(); break;
        case 3 : about(); break;
        case 4 : score(); break;
        case 5 : {
            system("clear");
            exit(0);
        }
    }
}

int Game::getBoardSize() {

    m_key.reset_terminal();

    std::cout <<"Choose the size of the board" <<std::endl <<std::endl;

    std::cout <<"1. 8X8  "<<std::endl;
    std::cout <<"2. 16X16"<<std::endl;

    int ID;

    std::cout <<"Enter your version: " ;
    std:: cin>> ID;
    m_key.new_settings_terminal();

    if (ID>0 && ID<3){
        return ID;
    }

    return 1;//defauly 8x8
}


void Game::startGame()
{
    int ID = getBoardSize();
    int MaxSizeName = 10;

    std::string player_1;
    std::string player_2;

    m_key.reset_terminal();
    std::cout << "Enter the name of the firs player: ";
    std::cin.ignore();
    std::getline(std::cin, player_1);
    player_1 = player_1.substr(0,MaxSizeName);

    std::cout << "Enter the name of the second player: ";
    std::cin.ignore();
    std::getline(std::cin, player_2);
    player_2 = player_2.substr(0,MaxSizeName);

    m_key.new_settings_terminal();
}

void Game::rules()
{
    std::ifstream file;
    file.open("Files/HowToPlay.txt");

    if(!file.is_open()) {
        system("clear");
        std::cout << "Error Open the File !\n" << std::flush;
        exit(0);
    } else {
        int x = 0;
        int y = 15;
        gotoxy(x,y);
        std::string text = "";
        while(!file.eof()) {
            text = "";
            getline(file,text);
            std::cout << text <<std::endl << std::flush;
            gotoxy(x, ++y);
        }
        file.close();
        gotoxy(x, ++y);
        std::cout << "\033[32;1m To go to the Main Menu,please click enter [ESC] \033[0m" << std::flush;
    }
    while(m_key.getch() != 27); //27 = esc
}

void Game::options()
{
    std::ifstream file;
    file.open("Files/Option.txt");

    if(!file.is_open()) {
        system("clear");
        std::cout << "Error Open the File !\n" << std::flush;
        exit(0);
    } else {
        int x = 0;
        int y = 15;
        gotoxy(x,y);
        std::string text = "";
        while(!file.eof()) {
            text = "";
            getline(file,text);
            std::cout << text <<std::endl << std::flush;
            gotoxy(x, ++y);
        }

        file.close();

        gotoxy(x, ++y);
        std::cout << "\033[32;1m To go to the Main Menu,please click enter [ESC] \033[0m" << std::flush;
    }
    while(m_key.getch() != 27);//27 = esc
}

void Game::about()
{
    std::ifstream file;
    file.open("Files/About.txt");

    if(!file.is_open()) {
        system("clear");
        std::cout << "Error Open the File !\n" << std::flush;
        exit(0);
    } else {
        int x = 0;
        int y = 15;
        gotoxy(x,y);
        std::string text = "";
        while(!file.eof()) {
            text = "";
            getline(file,text);
            std::cout << text << std::flush;
            gotoxy(x, ++y);
        }
        file.close();
        gotoxy(x , ++y);
        std::cout << "\033[32;1m To go to the Main Menu,please click enter [ESC] \033[0m" << std::flush;
    }
    m_key.new_settings_terminal();
    while(m_key.getch() != 27);

    return;
}

void Game::score()
{
    std::ifstream file;
    file.open("Files/Score.txt");

    if(!file.is_open()){
        system("clear");
        std::cout << "Error Open the File !\n" << std::flush;
        exit(0);
    } else {
        int x = 50;
        int y = 15;
        gotoxy(x,y);
        std::string text = "";
        while(!file.eof()) {
            text = "";
            getline(file,text);
            std::cout << text << std::flush;
            gotoxy(x, ++y);
        }
        file.close();
        gotoxy(x, ++y);
        std::cout << "\033[32;1m To go to the Main Menu,please click enter [ESC] \033[0m" << std::flush;
    }
    while(m_key.getch() != 27);

    return;
}



void Game::currentMenu()
{
    gotoxy(65, m_lastY);
    std::cout << " " << std::flush;

    gotoxy(70, m_lastY);
    std::cout << m_menu[m_lastIndex] << std::flush;

    gotoxy(65, m_firstY);
    std::cout << "\u279C" << std::flush;

    gotoxy(70, m_firstY);
    std::cout << "\033[92;1m" << m_menu[m_firstIndex] << "\033[0m" << std::flush;

    gotoxy(65, m_firstY);
    std::cout << std::flush;
}

void Game::loading() const
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

void Game::printName() const
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

void Game::printMenu(int id) const
{
    const int x = 70;
    int init_Y = 15;
    int y = id * 2 + init_Y;

    gotoxy(x - 5, y); //initial position of the arrow
    std::cout << "\u279C" << std::flush;
    for (int i = 0; i < 6; ++i){
        gotoxy(x, init_Y);
        if (i == id) {
            std::cout << "\033[92;1m" << m_menu[i] << "\033[0m" << std::flush;
        } else {
            std::cout << m_menu[i] << std::flush;
        }
        init_Y += 2;
    }
    gotoxy(x - 5, y);
    std::cout << std::flush;
}
