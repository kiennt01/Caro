#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string.h>
#include "Global.h"

class Player
{
private:
    Infor Player1;
    Infor Player2;
public:
    char* setNamePlayer1(char*);
    char* getNamePlayer1();
    char* setNamePlayer2(char*);
    char* getNamePlayer2();
};

#endif // PLAYER_H
