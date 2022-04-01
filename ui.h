#ifndef UI_H
#define UI_H
#include <iostream>
#include "Global.h"
#include "Caro.h"
#include "DataFile.h"
#include "Player.h"
#include "Replay.h"

class ui
{
private:
    Caro *process;
    DataFile *usedData;
    Player *gamer;
    Replay *rep;
    void Init();
    void DrawBoard();
    void InputName1();
    void InputName2();
    void PlayMode();
    void DataMode();
    void ReplayMode();
    void PlayerEnd();
    void GetPlayer1Move();
    void GetPlayer2Move();
    void PlayerInput();
public:
    ui();
    ~ui();
    void Menu();
};

#endif // UI_H
