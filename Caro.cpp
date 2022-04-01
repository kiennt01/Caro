#include <string.h>
#include <windows.h>
#include "Caro.h"

Caro::Caro(Player *player, DataFile *savedData)
{
    this -> player = player;
    this -> savedData = savedData;
}
Caro::Caro()
{

}
Caro::~Caro()
{

}
void Caro::Player1Move(const int& ix, const int& iy)
{
    Grid.x = ix;
    Grid.y = iy;
    Data.push_back(Grid);
    for (int i = 0; i < COLUM; i++)
    {
        for (int j = 0; j < ROW; j++) {

            if (Grid.x == i && Grid.y == j) {
                gameTABLE[i][j] = 'X';
            }
        }
    }
}
void Caro::Player2Move(const int& ix, const int& iy)
{
    Grid.x = ix;
    Grid.y = iy;
    Data.push_back(Grid);
    for (int i = 0; i < COLUM; i++)
    {
        for (int j = 0; j < ROW; j++) {
            if (Grid.x == i && Grid.y == j) {
                gameTABLE[i][j] = 'O';
            }
        }
    }
}

bool Caro::checkExist(const int& x, const int& y)
{
    for (int i = 0; i < Data.size(); i++)
    {
        if (Data[i].x == x && Data[i].y == y)
        {
            std::cout << "Invalid move, try again" << std::endl;
            return true;
        }
    }
    return false;
}
bool Caro::checkHorizontal() {
    int row = Data[Data.size() - 1].x;
    int column = Data[Data.size() - 1].y;
    char check = gameTABLE[row][column];
    int count = 1;
    int j = column;
    while (j > 0) {
        j--;
        if (gameTABLE[row][j] == check)
        {
            count++;

            if (count == GameWoncondition) return true;
        }
        else break;
    }
    j = column;
    while (j < (COLUM - 1)) {
        j++;

        if (gameTABLE[row][j] == check)
        {
            count++;

            if (count == GameWoncondition)   return true;
        }
        else break;
    }
    return false;
}
bool Caro::checkCross() {
    int row = Data[Data.size() - 1].x;
    int colum = Data[Data.size() - 1].y;
    char check = gameTABLE[row][colum];
    int count = 1;
    int i = colum;
    while (i > 0) {
        i--;
        if (gameTABLE[i][colum] == check)
        {
            count++;
            if (count == GameWoncondition) return true;
        }
        else break;
    }
    i = colum;
    while (i < (ROW - 1)) {
        i++;
        if (gameTABLE[i][colum] == check)
        {
            count++;
            if (count == GameWoncondition)   return true;
        }
        else break;
    }
    return false;
}
bool Caro::CheckDiagonal1() {
    int row = Data[Data.size() - 1].x;
    int colum = Data[Data.size() - 1].y;
    char check = gameTABLE[row][colum];
    int count = 1;
    int i = row;
    int j = colum;
    while (j > 0 && i > 0) {
        i--;
        j--;
        if (gameTABLE[i][j] == check) {
            count++;
            if (count == GameWoncondition) return true;
        }
        else break;

    }
    i = row;
    j = colum;
    while ((i < (COLUM - 1)) && (j < (ROW - 1))) {
        i++;
        j++;
        if (gameTABLE[i][j] == check) {
            colum++;
            if (count == GameWoncondition) return true
                ;
        }
        else break;
    }
    return false;
}
bool Caro::CheckDiagonal2() {
    int row = Data[Data.size() - 1].x;
    int column = Data[Data.size() - 1].y;
    char check = gameTABLE[row][column];
    int count = 1;
    int i = row;
    int j = column;
    while ((i > 0) && (j < (ROW - 1))) {
        i--;
        j++;
        if (gameTABLE[i][j] == check) {
            count++;
            if (count == GameWoncondition) return true;
        }
        else break;

    }
    i = row;
    j = column;
    while ((i < (ROW - 1)) && (j > 0)) {
        i++;
        j--;
        if (gameTABLE[i][j] == check) {
            count++;
            if (count == GameWoncondition) return true
                ;
        }
        else break;
    }
    return false;
}
bool Caro::CheckDrawGame()
{
    if (Data.size() == (COLUM * ROW)) return true;
    return false;
}
bool Caro::checkGameOver() {

    if (checkCross() || checkHorizontal() || CheckDiagonal1() || CheckDiagonal2() || CheckDrawGame())
    {
        return true;
    }
    return false;
}
bool Caro::CheckTurn()
{
        if (Data.size() % 2 == 1)
        {
            return true;
        }
        else if (Data.size() % 2 == 0)
        {
            return false;
        }
}

void Caro::WriteLastGame()
{
    savedData -> EraseFile();
    for (int i = 0; i < Data.size(); i++)
    {
        savedData -> WriteFileReplay(Data[i].x, Data[i].y);
    }
}
void Caro::UpdateInfo()
{
    if (checkGameOver() && CheckTurn())
    {
            savedData->WriteFile(player->getNamePlayer1(), 1, 0, 0);
            savedData->WriteFile(player->getNamePlayer2(), 0, 1, 0);
    }
     else if (checkGameOver() && !CheckTurn())
    {
            savedData->WriteFile(player->getNamePlayer1(), 0, 1, 0);
            savedData->WriteFile(player->getNamePlayer2(), 1, 0, 0);
    }
    else if (CheckDrawGame())
    {
        savedData->WriteFile(player->getNamePlayer1(), 0, 0, 1);
        savedData->WriteFile(player->getNamePlayer2(), 0, 0, 1);
    }
}
char Caro::getSpot(const int& x, const int& y)
{
    return gameTABLE[x][y];
}
char Caro::setSpot(int& x, int& y)
{
    return this -> gameTABLE[x][y];
}
void Caro::Init(){
    for(int i = 0 ; i < COLUM; i++){
        for(int j = 0; j < ROW; j++)
        {
            gameTABLE[i][j] = ' ';
        }
    }
}
void Caro::WriteFileReplay()
{
    savedData -> WriteGameOrder();
    for (int i = 0; i < Data.size(); i++)
    {
        savedData -> WriteFileReplay1(Data[i].x, Data[i].y);
    }
    savedData -> WriteSeparation();
}
