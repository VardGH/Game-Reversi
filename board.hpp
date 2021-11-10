#pragma once
#include <iostream>
#include "termio.hpp"
#include "gameintro.hpp"

void print_board();
void _Keypress();

const int board_hight = 8;
const int board_width = 8;
char mat[board_hight][board_width]{};

keyboard k;
int _Y = 17;
int _X = 69;
int color = 0;
int count_black = 2;
int count_white = 2;
bool game_continues = true;

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

bool check_left() {
	
	int i = (_Y - 11 ) / 2;
	int j = (_X - 61 ) / 4 - 1;
	int k = j;
	char ball_color;
	
	if ( color % 2 == 0 ) {
		
		ball_color = 'b';
	}
	else {
		ball_color = 'c';
	}
	
	while ( j >= 0 && mat[i][j]!=0 && mat[i][j] != ball_color ) {
		--j;
	}	
	
	if ( j != -1 && mat[i][j]!=0 && j != k ) {
		
		for(int h = j + 1; h <= k; ++h ) {
			mat[i][h] = ball_color;
			gotoxy( 4 * h + 61 , 2 * i + 11 );
			
			if( ball_color == 'b' ) {
			
				++count_black;
				--count_white;
			
			}
			else  {
				--count_black;
				++count_white;			
			}
			
			( ball_color == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
		}
		return true;
	}
		
	return false;
}

bool check_right() 
{
	int i = (_Y - 11 ) / 2;
	int j = (_X - 61 ) / 4 + 1;
	int k = j;
	char ball_color;
	
	if ( color % 2 == 0 ) {
		
		ball_color = 'b';
	}
	else {
		ball_color = 'c';
	}
	
	while ( j <=7 && mat[i][j]!=0 && mat[i][j] != ball_color ) {
		++j;
	}	
	
	if ( j != 8 && mat[i][j]!=0 && j != k ) {
		
		for(int h = k ; h < j; ++h ) {
			mat[i][h] = ball_color;
			gotoxy( 4 * h + 61 , 2 * i + 11 );
			
			if( ball_color == 'b' ) {
			
				++count_black;
				--count_white;
			
			}
			else  {
				--count_black;
				++count_white;			
			}
			
			( ball_color == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
		}
		return true;
	}
		
	return false;
}

bool check_up()
{
	int i = (_Y - 11 ) / 2 - 1;
	int j = (_X - 61 ) / 4;
	int k = i;
	char ball_color;
	
	if ( color % 2 == 0 ) {
		
		ball_color = 'b';
	}
	else {
		ball_color = 'c';
	}
	
	while ( i >= 0 && mat[i][j]!=0 && mat[i][j] != ball_color ) {
		--i;
	}	
	
	if ( i != -1 && mat[i][j]!=0 && i != k ) {
		
		for(int h = i + 1; h <= k; ++h ) {
			mat[h][j] = ball_color;
			gotoxy( 4 * j + 61 , 2 * h + 11 );
			
			if( ball_color == 'b' ) {
			
				++count_black;
				--count_white;
			
			}
			else  {
				--count_black;
				++count_white;			
			}
			
			( ball_color == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
		}
		return true;
	}
		
	return false;
	
	
}

bool check_down()
{
	int i = (_Y - 11 ) / 2 + 1;
	int j = (_X - 61 ) / 4;
	int k = i;
	char ball_color;
	
	if ( color % 2 == 0 ) {
		
		ball_color = 'b';
	}
	else {
		ball_color = 'c';
	}
	
	while ( i <= 7 && mat[i][j]!=0 && mat[i][j] != ball_color ) {
		++i;
	}	
	
	if ( i != 8 && mat[i][j]!=0 && i != k ) {
		
		for(int h = k; h < i; ++h ) {
			mat[h][j] = ball_color;
			gotoxy( 4 * j + 61 , 2 * h + 11 );
			
			if( ball_color == 'b' ) {
			
				++count_black;
				--count_white;
			
			}
			else  {
				--count_black;
				++count_white;			
			}
			
			( ball_color == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
		}
		return true;
	}
		
	return false;	
}

bool check_up_left_diagonal() 
{
	int i = (_Y - 11 ) / 2 - 1;
	int j = (_X - 61 ) / 4 - 1;
	int k = i;
	int l = j;
	char ball_color;
	
	if ( color % 2 == 0 ) {
		
		ball_color = 'b';
	}
	else {
		ball_color = 'c';
	}
	
	while ( i >= 0 && j>=0  && mat[i][j]!=0 && mat[i][j] != ball_color ) {
		--i;
		--j;
	}
	
	if ( i != -1 && j != -1 && mat[i][j]!=0 && i != k ) {
		
		for(int h = i+1, m = j + 1;  h <= k, m <= l; ++h, ++m  ) {
			
			mat[h][m] = ball_color;
			gotoxy( 4 * m + 61 , 2 * h + 11 );
			
			if( ball_color == 'b' ) {
			
				++count_black;
				--count_white;
			
			}
			else  {
				--count_black;
				++count_white;			
			}
			
			( ball_color == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
		}
		return true;
	}
		
	return false;	
		
}

bool check_down_right_diagonal()
{
	int i = (_Y - 11 ) / 2 + 1;
	int j = (_X - 61 ) / 4 + 1;
	int k = i;
	int l = j;
	char ball_color;
	
	if ( color % 2 == 0 ) {
		
		ball_color = 'b';
	}
	else {
		ball_color = 'c';
	}
	
	while ( i <=7 && j<=7  && mat[i][j]!=0 && mat[i][j] != ball_color ) {
		++i;
		++j;
	}
	
	if ( i != 8 && j != 8 && mat[i][j]!=0 && i != k ) {
		
		for(int h = k, m = l;  h < i, m < j; ++h, ++m  ) {
			
			mat[h][m] = ball_color;
			gotoxy( 4 * m + 61 , 2 * h + 11 );
			
			if( ball_color == 'b' ) {
			
				++count_black;
				--count_white;
			
			}
			else  {
				--count_black;
				++count_white;			
			}
			
			( ball_color == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
		}
		return true;
	}
		
	return false;
}

bool check_up_right_diagonal()
{
	int i = (_Y - 11 ) / 2 - 1;
	int j = (_X - 61 ) / 4 + 1;
	int k = i;
	int l = j;
	char ball_color;
	
	if ( color % 2 == 0 ) {
		
		ball_color = 'b';
	}
	else {
		ball_color = 'c';
	}
	
	while ( i >= 0 && j<=7  && mat[i][j]!=0 && mat[i][j] != ball_color ) {
		--i;
		++j;
	}
	
	if ( i != -1 && j != 8 && mat[i][j]!=0 && i != k ) {
		
		for(int h = k, m = l;  h > i, m < j; --h, ++m  ) {
			
			mat[h][m] = ball_color;
			gotoxy( 4 * m + 61 , 2 * h + 11 );
			
			if( ball_color == 'b' ) {
			
				++count_black;
				--count_white;
			
			}
			else  {
				--count_black;
				++count_white;			
			}
			
			( ball_color == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
		}
		return true;
	}
		
	return false;
}

bool check_down_left_diagonal()
{
	int i = (_Y - 11 ) / 2 + 1;
	int j = (_X - 61 ) / 4 - 1;
	int k = i;
	int l = j;
	char ball_color;
	
	if ( color % 2 == 0 ) {
		
		ball_color = 'b';
	}
	else {
		ball_color = 'c';
	}
	
	while ( i <= 7 && j>=0  && mat[i][j]!=0 && mat[i][j] != ball_color ) {
		++i;
		--j;
	}
	
	if ( i != 8 && j != -1 && mat[i][j]!=0 && i != k ) {
		
		for(int h = k , m = l;  h < i, m > j; ++h, --m  ) {
			
			mat[h][m] = ball_color;
			gotoxy( 4 * m + 61 , 2 * h + 11 );
			
			if( ball_color == 'b' ) {
			
				++count_black;
				--count_white;
			
			}
			else  {
				--count_black;
				++count_white;			
			}
			
			( ball_color == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
		}
		return true;
	}
		
	return false;
}

bool check () {
	return check_left() | check_right() | check_up() | check_down() | check_up_left_diagonal() | check_down_right_diagonal() | check_up_right_diagonal() | check_down_left_diagonal();
}

void who_won() {
	
	int coordinate_x = 67;
	int coordinate_y = 28;
	
	gotoxy(coordinate_x,coordinate_y);
	std::cout << "\033[32;1m The game is over \033[0m";
	
	if( count_black > count_white ) {
		gotoxy(coordinate_x + 2,coordinate_y + 2);
		std::cout << "\033[32;1m Black Wins!\033[0m";
	}
	else if( count_black < count_white ) {
		gotoxy(coordinate_x + 2,coordinate_y + 2);
		std::cout << "\033[32;1m White Wins! \033[0m";
	}
	else {
		gotoxy(coordinate_x + 2,coordinate_y + 2);
		std::cout << "\033[32;1m It is a draw ! \033[0m";
	}
	
	gotoxy(0,coordinate_y + 7);

}  

void update_count_blas( int black, int white ) {
	
	gotoxy( 66 , 8 );
	std::cout<<"Black "<< black <<" vs "<<white<<" white";		
	std::cout << std::flush;
}

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
    	
		    	if (check()) {
		    	
		    		gotoxy( 69 , 6 );
		    		std::cout << std::flush;
		    		
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
				++color;
				
				if(count_black + count_white == 64) {
					game_continues = false;	
				
				}
				
				update_count_blas( count_black , count_white );
				gotoxy(_X,_Y);
				std::cout << std::flush;
			}
			
		}
		
            	break;
            }

        }
        
    }
    
}



