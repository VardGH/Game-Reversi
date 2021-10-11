#include "termio.hpp"
#include <stdio.h>
#include <unistd.h> // read()
    
keyboard:: keyboard() {
    tcgetattr(0, &initial_settings);
    new_settings = initial_settings;
    new_settings.c_lflag &= ~(ICANON | ECHO | ISIG);
    new_settings.c_cc[VMIN] = 1;
    new_settings.c_cc[VTIME] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
    peek_character = -1;
}
    
keyboard:: ~keyboard() {
    tcsetattr(0, TCSANOW, &initial_settings);
}

void keyboard :: reset_terminal()
{
	tcsetattr(0, TCSANOW, &initial_settings);
}

void keyboard :: new_settings_terminal()
{
	tcsetattr(0, TCSANOW, &new_settings);
}
    
int keyboard:: kbhit() {
    unsigned char ch;
    int nread;
    if (peek_character != -1) return 1;
    new_settings.c_cc[VMIN] = 0;
    tcsetattr(0, TCSANOW, &new_settings);
    nread = read(0,&ch,1);
    new_settings.c_cc[VMIN] = 1;
    tcsetattr(0, TCSANOW, &new_settings);

    if (nread == 1) {
        peek_character = ch;
        return 1;
    }
    return 0;
}
    
int keyboard:: getch(){
    char ch;

    if (peek_character != -1){
        ch = peek_character;
        peek_character = -1;
    }
    else read(0, &ch, 1);
    return ch;
}

void gotoxy(int x, int y)
{
    printf("%c[%d;%df", 0x1B, y, x);
}

