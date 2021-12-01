#pragma once

#include <string>
#include <fstream>
#include "menu.hpp"
#include "termio.hpp"

void temp_Menu();
void Menu_KeyPress();
void MainMenu(int);
void StartGame();
void HowToPlay();
void Options();
void About();
void Score();
int  BoardSize();

bool start = true ;
static int first_index_Menu = 0;
static int last_index_Menu = 0;
static int first_Y = 15;
static int last_Y = 15;

keyboard key;

void Menu_Keypress() {
    if(key.kbhit()) {
        last_Y = first_Y;
        last_index_Menu = first_index_Menu;
        switch(key.getch()) {
        case 10 : {
            MainMenu(first_index_Menu);
            system("clear");
            GameMenu::print_GameName();
            GameMenu::print_Menu(first_index_Menu);
            break;
        }
        case 'w': {
            first_Y -= 2;
            if (first_Y < 15) {
                first_Y = 25;
                first_index_Menu = 5;
            } else
                --first_index_Menu;
            break;
        }

        case 's' : {
            first_Y += 2;
            if (first_Y > 25){
                first_Y = 15;
                first_index_Menu = 0;
            } else 
            	++first_index_Menu;
            break;
        }
    }

    	if (last_index_Menu != first_index_Menu) {
    		temp_Menu();
    	}
        
    }
    
}

void MainMenu(int index_Menu)
{
    gotoxy(0,14);
    std::cout << "\033[0J" << std::flush;
    switch(index_Menu) {
        case 0 : {
            
            start = false;
            StartGame();
            std::cout << "\033[1;31m" << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << "\033[0m" << std::endl;
            break;
        }
        case 1 : HowToPlay(); break;
        case 2 : Options(); break;
        case 3 : About(); break;
        case 4 : Score(); break;
        case 5 : {
            system("clear");
            std::cout << "\033[1;31m" << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << "\033[0m" << std::endl;
            exit(0);
        }
    }
}

int BoardSize() {
    
    key.reset_terminal();
    
    std::cout <<"Choose the size of the board" <<std::endl <<std::endl;    
    
    std::cout <<"1. 8X8  "<<std::endl; 
    std::cout <<"2. 16X16"<<std::endl;  
    
    int ID;
    
    std::cout <<"Enter your version: " ;
    std:: cin>> ID;
    key.new_settings_terminal();
    
    if (ID>0 && ID<3){
       return ID;
    }
    
    return 1;//defauly 8x8
    
}


void StartGame() {
    
    int ID = BoardSize();
    int MaxSizeName = 10;
    
    std::string player_1;
    std::string player_2;
    
    key.reset_terminal();
    std::cout << "Enter the name of the firs player: ";
    std::cin.ignore();
    std::getline(std::cin, player_1);
    player_1 = player_1.substr(0,MaxSizeName);
    
    std::cout << "Enter the name of the second player: ";
    std::cin.ignore();
    std::getline(std::cin, player_2);
    player_2 = player_2.substr(0,MaxSizeName);
    
    key.new_settings_terminal();
}

void HowToPlay() {

    std::ifstream file;
    file.open("Files/HowToPlay.txt");

    if(!file.is_open()) {
        system("clear");
        std::cout << "Error Open the File !\n" << std::flush;
        std::cout << "\033[1;31m" << __FILE__ << " " << __FUNCTION__ << " " << __LINE__ << "\033[0m" << std::endl;
        exit(0);
    } 
    else {
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
    
    while(key.getch() != 27); //27 = esc

}

void Options() {
    
    std::ifstream file;
    file.open("Files/Option.txt");

    if(!file.is_open()) {
        system("clear");
        std::cout << "Error Open the File !\n" << std::flush;
        exit(0);
    } 
    else {
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
    
    
    while(key.getch() != 27);//27 = esc

}

void About() {

    std::ifstream file;
    file.open("Files/About.txt");

    if(!file.is_open()) {
        system("clear");
        std::cout << "Error Open the File !\n" << std::flush;
        exit(0);
    } 
    else {
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
    
    key.new_settings_terminal();
    while(key.getch() != 27);
    

    return;
}

void Score() {

    std::ifstream file;
    file.open("Files/Score.txt");

    if(!file.is_open()){
        system("clear");
        std::cout << "Error Open the File !\n" << std::flush;
        exit(0);
    } 
    else {
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
    while(key.getch() != 27);

    return;
}



void temp_Menu()
{
    gotoxy(65,last_Y);
    std::cout << " " << std::flush;
    
    gotoxy(70,last_Y);
    std::cout << Menu[last_index_Menu] << std::flush;

    gotoxy(65, first_Y);
    std::cout << "\u279C" << std::flush;
    
    gotoxy(70,first_Y);
    std::cout << "\033[92;1m" << Menu[first_index_Menu] << "\033[0m" << std::flush;

    gotoxy(65, first_Y);
    std::cout << std::flush;
}




