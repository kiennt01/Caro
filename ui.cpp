#ifndef UI_CPP
#define UI_CPP
#include <string.h>
#include <windows.h>
#include "ui.h"
#include "DataFile.h"
#include "Replay.h"

ui::ui()
{
    process = new Caro();
    usedData = new DataFile();
    gamer = new Player();
    rep = new Replay();

    if (!process || !usedData || !gamer || !rep)
    {
        std::cout << "Can not allocate memory!" << std::endl;
    }
}
ui::~ui()
{
    if(process != NULL)
    {
        delete process;
        process = nullptr;
    }
    if(usedData != NULL)
    {
        delete usedData;
        usedData = nullptr;
    }
    if(gamer != NULL)
    {
        delete usedData;
        usedData = nullptr;
    }
    if(rep != NULL)
    {
        delete rep;
        rep = nullptr;
    }
}
void ui::DrawBoard()
{
    std::cout << gamer->getNamePlayer1() << " <X> - " << gamer->getNamePlayer2() << " <0>" << std::endl;
    std::cout << "    ";
        for (int iX = 0; iX < COLUM; iX++)
        {
            if(iX + 1 < 10)
            {
                std::cout << iX + 1 << "   ";
            }
            else
            {
                std::cout << iX + 1 << "  ";
            }
        }
        std::cout << std::endl;
        for (int iY = 0; iY < ROW; iY++){
            if (iY + 1 < 10)
            {
                std::cout << iY + 1 << " ";
            }
            else
            {
                std::cout << iY + 1;
            }
            for (int iX = 0; iX < COLUM; iX++){
                std::cout << "| " << process->getSpot(iX, iY) << " ";
            }
            std::cout << std::endl;
            std::cout << "   ";
            for (int iX = 0; iX < COLUM; iX++){
                std::cout << "----";
            }
            std::cout << std::endl;
        }
}
void ui::GetPlayer1Move()
{
    std::cout << gamer->getNamePlayer1() << " <X> - " << gamer->getNamePlayer2() << " <0>" << std::endl;
    int iX, iY;
    std::cout << gamer->getNamePlayer1() << "'s turn" << std::endl;
    do
    {
        std::cout << "Input x : "; std::cin >> iX;
        std::cout << "Input y : "; std::cin >> iY;
        --iX; --iY;
    } while (((0 > iX) || (COLUM - 1 < iX)) || ((0 > iY) || (ROW - 1 < iY)) || process->checkExist(iX, iY));
    process->Player1Move(iX, iY);
}
void ui::GetPlayer2Move()
{
    std::cout << gamer->getNamePlayer1() << " <X> - " << gamer->getNamePlayer2() << " <0>" << std::endl;
    int iX, iY;
    std::cout << gamer->getNamePlayer2() << "'s turn" << std::endl;
    do
    {
        std::cout << "Input x : "; std::cin >> iX;
        std::cout << "Input y : "; std::cin >> iY;
        --iX; --iY;
    } while (((0 > iX) || (COLUM - 1 < iX)) || ((0 > iY) || (ROW - 1 < iY)) || process->checkExist(iX, iY));
    process->Player2Move(iX, iY);
}
void ui::PlayerInput()
{
    if (process->CheckTurn()) {
        GetPlayer2Move();
    }
    else if (!process->CheckTurn()) {
        GetPlayer1Move();
    }
    system("cls");
}
void ui::InputName1()
{
    char name[100];
    std::cout << "Input player 1's name : ";
    std::cin >> name;
    gamer -> setNamePlayer1(name);
}
void ui::InputName2()
{
    char name[100];
    std::cout << "Input player 2's name : ";
    std::cin >> name;
    gamer -> setNamePlayer2(name);
}
void ui::PlayerEnd()
{
    if(process->checkGameOver() && process->CheckTurn())
    {
        std::cout << gamer->getNamePlayer1() << " win!" << std::endl;
    }
    else if(process->checkGameOver() && !process->CheckTurn())
    {
        std::cout << gamer->getNamePlayer2() << " win!" << std::endl;
    }
}
void ui::Menu()
{
    int choice;
    std::cout << "Welcome to Caro game!!!" << std::endl;
    std::cout << "1. Play New Game" << std::endl;
    std::cout << "2. Open Database" << std::endl;
    std::cout << "3. Replay last game" << std::endl;
    std::cout << "4. Play online" << std::endl;
    std::cout << "0. Exit" << std::endl;
    std::cout << "Enter your option : ";
    std::cin >> choice;
    system("cls");
    switch (choice)
    {
    case PLAY_OFFLINE:
        PlayMode();
        break;
    case DATABASE:
        DataMode();
        break;
    case REPLAY_MODE:
        ReplayMode();
        break;
    case PLAY_ONLINE:break;

    case EXIT: exit(0);
    }
}
void ui::PlayMode()
{
    int choice;
    InputName1();
    InputName2();
    system("cls");
    process->Init();
    DrawBoard();
    do
    {
        PlayerInput();
        process->checkGameOver();
        DrawBoard();
    } while (process->checkGameOver() == false);
    PlayerEnd();
    process->UpdateInfo();
    process->WriteLastGame();
    process->WriteFileReplay();
    std::cout << "Press 1 to return main menu" << std::endl << "Press 0 to exit" << std::endl;
    std::cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1: Menu(); break;
    case 0: exit(0);
    }
}
void ui::DataMode()
{
    int choice;
    usedData -> SortInfo();
    std::cout << "----" << std::endl;
    std::cout << "Type a name to see data and most suitable opponent : ";
    label:
    usedData -> LoadRank();
    std::cout << "----" << std::endl;
    std::cout << "Press 0 to exit " << std::endl;
    std::cout << "Press 1 to find other player data " << std::endl;
    std::cout << "Press 2 to return main menu" << std::endl;
    std::cin >> choice;
    switch (choice)
    {
    case 1 :
        std::cout << "Type player name: " ;
        goto label;
    case 2 :
        system("cls");
        Menu();
        break;
    case 0 : exit(0);
    }
}
void ui::ReplayMode()
{
    int choice;
    int index = 0;
    for (int i = 1; i < usedData->countMatch(); i++){
        std::cout << i << std::endl;
    }
    rep -> ReadFileReplay();
    rep -> SeparateXY();
    rep -> replayInit();
    rep -> replayDrawBoard();
    system("cls");
    while(index != rep -> replayOver())
    {
    rep -> LoadReplay(index);
    rep -> replayDrawBoard();
    index++;
    Sleep(1000);
    }
    std::cout << "Press 1 to return menu" << std::endl;
    std::cout << "Press 0 to exit" << std::endl;
    std::cin >> choice;
    system("cls");
    switch (choice)
    {
    case 1:
        Menu();
        break;
    case 2: exit(0);
    }

}

#endif // UI_CPP
