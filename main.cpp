#include <iostream>
#include "termio.hpp"
#include "show.hpp"
#include "gameintro.hpp"

int main()
{
	print_Loading();
	print_GameName();
	print_Menu();
	
	while (start){
		
	   Menu_Keypress();
	
	}
	
	system("clear");
	std::cout << "Start Game: " << std::endl;
	
	return 0;
}
