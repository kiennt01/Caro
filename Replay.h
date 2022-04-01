#ifndef REPLAY_H
#define REPLAY_H
#include <iostream>
#include <fstream>
#include <vector>
#include <windows.h>
#include <sstream>
#include "Global.h"
class Replay
{
private:
    std::string line;
    char replayTable[COLUM][ROW];
    std::vector<int> coordinate;
    std::vector<int> Xposition;
    std::vector<int> Yposition;
public:
    void Player1Replay(const int&, const int&);
    void Player2Replay(const int&, const int&);
    void LoadPlayerReplay(const int&);
    void replayInit();
    void replayDrawBoard();
    int replayOver();
    int countMatch();
    void ReadFileReplay();
    void SeparateXY();
    void LoadReplay(const int&);
};

#endif // REPLAY_H
