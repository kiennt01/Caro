#include "Player.h"

char* Player::setNamePlayer1(char* name)
{
    strcpy(Player1.name, name);
    return Player1.name;
}
char* Player::setNamePlayer2(char* name)
{
    strcpy(Player2.name, name);
    return Player2.name;
}
char* Player::getNamePlayer1()
{
    return Player1.name;
}
char* Player::getNamePlayer2()
{
    return Player2.name;
}
