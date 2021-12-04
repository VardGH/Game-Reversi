#include <iostream>
#include <unistd.h>

#include "termio.hpp"
#include "keyhandler.hpp"
#include "gameboard.hpp"

void GameBoard::play()
{
    printBoard();
    while (m_isRunning) {
        handleKeyPress();
    }
    printWinner();
}

void GameBoard::printBoard()
{
    system("clear");

    m_mat[3][3] = m_mat[4][4] = 'c';//spitak
    m_mat[3][4] = m_mat[4][3] = 'b';//sev

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
            if (m_mat[k][i] == 'b') {
                std::cout << "\u25CB";
            } else if (m_mat[k][i] == 'c') {
                std::cout << "\u25CF";
            } else std::cout << " ";
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


bool GameBoard::checkLeft()
{
    int i = (m_yCoord - 11 ) / 2;
    int j = (m_xCoord - 61 ) / 4 - 1;
    int k = j;
    char ballColor;

    if ( m_color % 2 == 0 ) {
        ballColor = 'b';
    } else {
        ballColor = 'c';
    }

    while ( j >= 0 && m_mat[i][j]!=0 && m_mat[i][j] != ballColor ) {
        --j;
    }

    if ( j != -1 && m_mat[i][j]!=0 && j != k ) {
        for(int h = j + 1; h <= k; ++h ) {
            m_mat[i][h] = ballColor;
            gotoxy( 4 * h + 61 , 2 * i + 11 );
            if( ballColor == 'b' ) {
                ++m_blackCount;
                --m_whiteCount;
            } else  {
                --m_blackCount;
                ++m_whiteCount;
            }

            ( ballColor == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
        }
        return true;
    }
    return false;
}

bool GameBoard::checkRight()
{
    int i = (m_yCoord - 11 ) / 2;
    int j = (m_xCoord - 61 ) / 4 + 1;
    int k = j;
    char ballColor;

    if ( m_color % 2 == 0 ) {
        ballColor = 'b';
    } else {
        ballColor = 'c';
    }

    while ( j <=7 && m_mat[i][j]!=0 && m_mat[i][j] != ballColor ) {
        ++j;
    }

    if ( j != 8 && m_mat[i][j]!=0 && j != k ) {
        for(int h = k ; h < j; ++h ) {
            m_mat[i][h] = ballColor;
            gotoxy( 4 * h + 61 , 2 * i + 11 );
            if( ballColor == 'b' ) {
                ++m_blackCount;
                --m_whiteCount;
            } else  {
                --m_blackCount;
                ++m_whiteCount;
            }
            ( ballColor == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
        }
        return true;
    }
    return false;
}

bool GameBoard::checkUp()
{
    int i = (m_yCoord - 11 ) / 2 - 1;
    int j = (m_xCoord - 61 ) / 4;
    int k = i;
    char ballColor;
    if ( m_color % 2 == 0 ) {
        ballColor = 'b';
    } else {
        ballColor = 'c';
    }

    while ( i >= 0 && m_mat[i][j]!=0 && m_mat[i][j] != ballColor ) {
        --i;
    }

    if ( i != -1 && m_mat[i][j]!=0 && i != k ) {
        for(int h = i + 1; h <= k; ++h ) {
            m_mat[h][j] = ballColor;
            gotoxy( 4 * j + 61 , 2 * h + 11 );
            if( ballColor == 'b' ) {
                ++m_blackCount;
                --m_whiteCount;
            } else  {
                --m_blackCount;
                ++m_whiteCount;
            }
            ( ballColor == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
        }
        return true;
    }
    return false;
}

bool GameBoard::checkDown()
{
    int i = (m_yCoord - 11 ) / 2 + 1;
    int j = (m_xCoord - 61 ) / 4;
    int k = i;
    char ballColor;

    if ( m_color % 2 == 0 ) {
        ballColor = 'b';
    } else {
        ballColor = 'c';
    }

    while ( i <= 7 && m_mat[i][j]!=0 && m_mat[i][j] != ballColor ) {
        ++i;
    }

    if ( i != 8 && m_mat[i][j]!=0 && i != k ) {
        for(int h = k; h < i; ++h ) {
            m_mat[h][j] = ballColor;
            gotoxy( 4 * j + 61 , 2 * h + 11 );
            if( ballColor == 'b' ) {
                ++m_blackCount;
                --m_whiteCount;
            } else {
                --m_blackCount;
                ++m_whiteCount;
            }
            ( ballColor == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
        }
        return true;
    }
    return false;
}

bool GameBoard::checkUpLeftDiagonal()
{
    int i = (m_yCoord - 11 ) / 2 - 1;
    int j = (m_xCoord - 61 ) / 4 - 1;
    int k = i;
    int l = j;
    char ballColor;

    if ( m_color % 2 == 0 ) {
        ballColor = 'b';
    } else {
        ballColor = 'c';
    }

    while ( i >= 0 && j>=0  && m_mat[i][j]!=0 && m_mat[i][j] != ballColor ) {
        --i;
        --j;
    }

    if ( i != -1 && j != -1 && m_mat[i][j]!=0 && i != k ) {
        for(int h = i+1, m = j + 1;  h <= k, m <= l; ++h, ++m  ) {
            m_mat[h][m] = ballColor;
            gotoxy( 4 * m + 61 , 2 * h + 11 );
            if( ballColor == 'b' ) {
                ++m_blackCount;
                --m_whiteCount;
            } else  {
                --m_blackCount;
                ++m_whiteCount;
            }
            ( ballColor == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
        }
        return true;
    }
    return false;
}

bool GameBoard::checkDownRightDiagonal()
{
    int i = (m_yCoord - 11 ) / 2 + 1;
    int j = (m_xCoord - 61 ) / 4 + 1;
    int k = i;
    int l = j;
    char ballColor;

    if ( m_color % 2 == 0 ) {
        ballColor = 'b';
    } else {
        ballColor = 'c';
    }

    while ( i <=7 && j<=7  && m_mat[i][j]!=0 && m_mat[i][j] != ballColor ) {
        ++i;
        ++j;
    }

    if ( i != 8 && j != 8 && m_mat[i][j]!=0 && i != k ) {
        for(int h = k, m = l;  h < i, m < j; ++h, ++m  ) {
            m_mat[h][m] = ballColor;
            gotoxy( 4 * m + 61 , 2 * h + 11 );
            if( ballColor == 'b' ) {
                ++m_blackCount;
                --m_whiteCount;
            } else  {
                --m_blackCount;
                ++m_whiteCount;
            }
            ( ballColor == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
        }
        return true;
    }
    return false;
}

bool GameBoard::checkUpRightDiagonal()
{
    int i = (m_yCoord - 11 ) / 2 - 1;
    int j = (m_xCoord - 61 ) / 4 + 1;
    int k = i;
    int l = j;
    char ballColor;

    if ( m_color % 2 == 0 ) {
        ballColor = 'b';
    } else {
        ballColor = 'c';
    }

    while ( i >= 0 && j<=7  && m_mat[i][j]!=0 && m_mat[i][j] != ballColor ) {
        --i;
        ++j;
    }

    if ( i != -1 && j != 8 && m_mat[i][j]!=0 && i != k ) {
        for(int h = k, m = l;  h > i, m < j; --h, ++m  ) {
            m_mat[h][m] = ballColor;
            gotoxy( 4 * m + 61 , 2 * h + 11 );
            if( ballColor == 'b' ) {
                ++m_blackCount;
                --m_whiteCount;
            } else  {
                --m_blackCount;
                ++m_whiteCount;
            }

            ( ballColor == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
        }
        return true;
    }
    return false;
}

bool GameBoard::checkDownLeftDiagonal()
{
    int i = (m_yCoord - 11 ) / 2 + 1;
    int j = (m_xCoord - 61 ) / 4 - 1;
    int k = i;
    int l = j;
    char ballColor;

    if ( m_color % 2 == 0 ) {
        ballColor = 'b';
    } else {
        ballColor = 'c';
    }

    while ( i <= 7 && j>=0  && m_mat[i][j]!=0 && m_mat[i][j] != ballColor ) {
        ++i;
        --j;
    }

    if ( i != 8 && j != -1 && m_mat[i][j]!=0 && i != k ) {
        for(int h = k , m = l;  h < i, m > j; ++h, --m  ) {
            m_mat[h][m] = ballColor;
            gotoxy( 4 * m + 61 , 2 * h + 11 );
            if( ballColor == 'b' ) {
                ++m_blackCount;
                --m_whiteCount;
            } else  {
                --m_blackCount;
                ++m_whiteCount;
            }
            ( ballColor == 'b' ) ?  std::cout << "\u25CB" << std::flush : std::cout << "\u25CF" << std::flush ;
        }
        return true;
    }
    return false;
}

bool GameBoard::check()
{
	return checkLeft() | checkRight() | checkUp() | checkDown() | checkUpLeftDiagonal() | checkDownRightDiagonal() | checkUpRightDiagonal() | checkDownLeftDiagonal();
}

void GameBoard::printWinner() {

    int coordX = 67;
    int coordY = 28;

    gotoxy(coordX, coordY);
    std::cout << "\033[32;1m The game is over \033[0m";

    if( m_blackCount > m_whiteCount ) {
        gotoxy(coordX + 2, coordY + 2);
        std::cout << "\033[32;1m Black Wins!\033[0m";
    }
    else if( m_blackCount < m_whiteCount ) {
        gotoxy(coordX + 2, coordY + 2);
        std::cout << "\033[32;1m White Wins! \033[0m";
    } else {
        gotoxy(coordX + 2, coordY + 2);
        std::cout << "\033[32;1m It is a draw ! \033[0m";
    }

    gotoxy(0, coordY + 7);
}

void GameBoard::handleKeyPress()
{
    gotoxy(m_xCoord, m_yCoord);
    std::cout << std::flush;
    usleep(10000);

    if (m_key.kbhit()) {
        switch (static_cast<KeyPressHandler::Key>(m_key.getch())) {
            case KeyPressHandler::Key::UP : {
                KeyPressHandler::handleUp(m_yCoord);
                break;
            }
            case KeyPressHandler::Key::DOWN : {
                KeyPressHandler::handleDown(m_yCoord);
                break;
            }
            case KeyPressHandler::Key::LEFT: {
                KeyPressHandler::handleLeft(m_xCoord);
                break;
            }
            case KeyPressHandler::Key::RIGHT : {
                KeyPressHandler::handleRight(m_xCoord);
                break;
            }
            case KeyPressHandler::Key::ESC : {
                KeyPressHandler::handleEsc();
                break;
            }
            case KeyPressHandler::Key::SPACE : {
                if (m_mat[ (m_yCoord - 11 ) / 2 ][ ( m_xCoord - 61 ) / 4] == 0 ) {
                    if (check()) {
                        m_isRunning = KeyPressHandler::handleSpace(m_mat, m_xCoord, m_yCoord, m_blackCount, m_whiteCount, m_color);
                    }
                }
                break;
            }
        }
    }
}

