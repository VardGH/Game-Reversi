#pragma once

struct KeyPressHandler
{
public:
    enum class Key : int {
        UP    = 'w',
        DOWN  = 's',
        LEFT  = 'a',
        RIGHT = 'd',
        ESC   = 27,
        SPACE = 32,
        ENTER  = 10

    };

public:
    static inline void handleUp(int& y);
    static inline void handleDown(int& y);
    static inline void handleRight(int& x);
    static inline void handleLeft(int& x);
    static inline void handleEsc();
    static inline bool handleSpace(char** mat, int& x, int& y, int& blackCount, int& whiteCount, int& color);

};

void KeyPressHandler::handleUp(int& y)
{
    y -= 2;
    if (y < 11) {
        y = 25;
    }
}

void KeyPressHandler::handleDown(int& y)
{
    y += 2;
    if (y > 25) {
        y = 11;
    }
}

void KeyPressHandler::handleRight(int& x)
{
    x += 4;
    if (x > 89) {
        x = 61;
    }
}

void KeyPressHandler::handleLeft(int& x)
{
    x -= 4;
    if (x < 61) {
        x = 89;
    }
}

void KeyPressHandler::handleEsc()
{
    system("clear");
    gotoxy(0, 0);
    std::cout << std::flush;
    std::exit(0);
}

bool KeyPressHandler::handleSpace(char** mat, int& x, int& y, int& blackCount, int& whiteCount, int& color)
{
    gotoxy( 69 , 6 );
    std::cout << std::flush;
    if(color % 2 == 0) {
        mat[ (y - 11 ) / 2 ][ ( x - 61 ) / 4] = 'b';
        ++blackCount;
        std::cout << "\033[32;1m White's turn \033[0m";
        gotoxy(x,y);
        std::cout << "\u25CB";//sev
        std::cout << std::flush;
    } else {
        mat[ (y - 11 ) / 2 ][ ( x - 61 ) / 4] = 'c';
        ++whiteCount;
        std::cout << "\033[32;1m Black's turn \033[0m";

        gotoxy(x,y);

        std::cout << "\u25CF";//spitak
        std::cout << std::flush;
    }
    ++color;
	gotoxy( 66 , 8 );
	std::cout << "Black " << blackCount << " vs " << whiteCount << " white" << std::flush;

    gotoxy(x, y);
    std::cout << std::flush;
    if(blackCount + whiteCount == 64) {
        return false;
    }
    return true;
}

