#ifndef CARO_H
#define CARO_H
#include<iostream>
#include<vector>
#include<cstdlib>
#include "Global.h"
#include "Player.h"
#include "DataFile.h"

class Caro
{
private:
    Player *player;
    DataFile *savedData;
    char gameTABLE[COLUM][ROW];
    std::vector<Block> Data;
    Block Grid;
    bool checkHorizontal();
    bool checkCross();
    bool CheckDiagonal1();
    bool CheckDiagonal2();
public:
    Caro();
    Caro(Player*, DataFile*);
    ~Caro();
    bool CheckTurn();
    void Init();
    bool CheckDrawGame();
    void Player1Move(const int&, const int&);
    void Player2Move(const int&, const int&);
    bool checkExist(const int&, const int&);
    bool checkGameOver();
    int GetTotalMove();
    void UpdateInfo();
    char getSpot(const int&, const int&);
    char setSpot(int&, int&);
    int GetX(int);
    int GetY(int);
    void WriteLastGame();
    void WriteFileReplay();
};

#endif // CARO_H
