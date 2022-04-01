#ifndef GLOBAL_H
#define GLOBAL_H

#define  COLUM 10
#define  ROW 10
#define GameWoncondition 4
struct Block
{
    int x;
    int y;
};
struct Infor
{
    char name[50];
    int win;
    int lose;
    int draw;
};
enum Option
{
    PLAY_OFFLINE = 1,
    DATABASE = 2,
    REPLAY_MODE = 3,
    PLAY_ONLINE = 4,
    EXIT = 0
};

#endif // GLOBAL_H
