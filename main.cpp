#include <iostream>
#include "termio.hpp"
#include "show.hpp"
#include "gameintro.hpp"
#include "board.hpp"

int main()
{
	print_Loading();
	print_GameName();
	print_Menu();
	
	while (start){
		
	   Menu_Keypress();
	
	}
	
	key.reset_terminal();
	
	system("clear");
	
	print_board();	
	
	while (game_continues) {

	    _Keypress();

	}
	
	who_won();
	
	return 0;
}
