#pragma once
    
#include <termios.h>
    
class keyboard{
    public:
        keyboard();
        ~keyboard();
        int kbhit();
        int getch();
        void reset_terminal();
        void new_settings_terminal();

    private:
        struct termios initial_settings, new_settings;
        int peek_character;
};

void gotoxy(int,int);
