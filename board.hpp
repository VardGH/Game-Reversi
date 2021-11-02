#pragma once
#include <iostream>
#include "termio.hpp"
#include "gameintro.hpp"

void print_board();
void _Keypress();

const int board_hight = 8;
const int board_width = 8;
char mat[board_hight][board_width]{};



void print_board()
{
    system("clear");
    
    mat[3][3] = mat[4][4] = 'c';//spitak
    mat[3][4] = mat[4][3] = 'b';//sev
    
    
    int x = 60;
    int y = 10;
    
    gotoxy( x + 9 , y - 4 );
    std::cout << "\033[32;1m Black's turn \033[0m";
    
    gotoxy( 66 , 8 );
    std::cout<<"Black "<< 2 <<" vs "<< 2 <<" white";		
    std::cout << std::flush;
    
    
    for (int k = 0; k < 8; ++k) {
        gotoxy(x, y + k * 2);
        for (int i = 0; i < 16; ++i) {
            std::cout << "\u2015 " << std::flush;//horizonakan
        }

        gotoxy(x - 1, y + k * 2 + 1);
        std::cout << std::flush;

        for (int i = 0; i < 8; ++i) {
            std::cout << "\u007C " << std::flush;//uxahayac
            if (mat[k][i] == 'b') {
                std::cout << "\u25CB";
            }
            else if (mat[k][i] == 'c') {
                std::cout << "\u25CF";
            }
            else std::cout << " ";
            std::cout << " ";
        }
        std::cout << std::endl;
    }

    gotoxy(x, 26);
    std::cout << std::flush;
    for (int i = 0; i < 16; ++i) {
        std::cout << "\u2015 " << std::flush;//horizonakan
    }

    for (int i = 0; i < 8; ++i) {
        gotoxy(91, y + i * 2 + 1);
        std::cout << "\u007C " << std::flush;//uxahayac
    }

}

keyboard k;
int _Y = 17;
int _X = 69;
int color = -1;

void update_count_blas( int black, int white ) {
	
	gotoxy( 66 , 8 );
	std::cout<<"Black "<< black <<" vs "<<white<<" white";		
	std::cout << std::flush;
}

int count_black = 2;
int count_white = 2;
    
void _Keypress() {

    gotoxy(_X, _Y);
    std::cout << std::flush;
    usleep(10000);
    
    if (k.kbhit()) {

        switch (k.getch()) {

            case 'w': {
                _Y -= 2;
                if (_Y < 11) {
                    _Y = 25;
                }
            	break;
            }

            case 's': {
                _Y += 2;
                if (_Y > 25) {
                    _Y = 11;
                }
            	break;
            }

            case 'a': {
                _X -= 4;
                if (_X < 61) {
                    _X = 89;
                }
            	break;
            }

            case 'd': {
                _X += 4;
                if (_X > 89) {
                 _X = 61;
                }
            	break;
            }


            case 27 : {
                system("clear");
                gotoxy(0, 0);
                std::cout << std::flush;
                exit(0);
            	break;
            }
            
            case 32 : {
            	if (mat[ (_Y - 11 ) / 2 ][ ( _X - 61 ) / 4] == 0 ) {
		    	++color;
		    	gotoxy( 69 , 6 );
		    	
		    	if(color % 2 == 0) {
		    		mat[ (_Y - 11 ) / 2 ][ ( _X - 61 ) / 4] = 'b';
		    		++count_black;
		    		std::cout << "\033[32;1m White's turn \033[0m";
		    		
		    		gotoxy(_X,_Y);
		    		
		        	std::cout << "\u25CB";//sev
		        	std::cout << std::flush;
		        }
		        else {
		        	mat[ (_Y - 11 ) / 2 ][ ( _X - 61 ) / 4] = 'c';
		        	++count_white;
		        	 std::cout << "\033[32;1m Black's turn \033[0m";
		        	
		        	gotoxy(_X,_Y);
		        	
		        	std::cout << "\u25CF";//spitak
		        	std::cout << std::flush;
			}
		}
		update_count_blas( count_black , count_white );
		gotoxy(_X,_Y);
		std::cout << std::flush;
            	break;
            }

        }
    }
}



