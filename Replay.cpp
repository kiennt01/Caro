#include "Replay.h"

void Replay::Player1Replay(const int& x, const int& y)
{
    for (int i = 0; i < COLUM; i++)
    {
        for (int j = 0; j < ROW; j++) {
            if (x == i && y == j) {
                replayTable[i][j] = 'X';
            }
        }
    }
}
void Replay::Player2Replay(const int& x, const int& y)
{
    for (int i = 0; i < COLUM; i++)
    {
        for (int j = 0; j < ROW; j++) {
            if (x == i && y == j) {
                replayTable[i][j] = 'O';
            }
        }
    }
}
void Replay::replayInit(){
    for(int i = 0 ; i < COLUM; i++){
        for(int j = 0; j < ROW; j++)
        {
            replayTable[i][j] =' ';
        }
    }
}
void Replay::replayDrawBoard()
{
    std::cout << " <X> - " << " <0>" << std::endl;
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
                std::cout << "| " << replayTable[iX][iY] << " ";
            }
            std::cout << std::endl;
            std::cout << "   ";
            for (int iX = 0; iX < COLUM; iX++){
                std::cout << "----";
            }
            std::cout << std::endl;
        }
}
void Replay::ReadFileReplay()
{
    int line_no = 0;
    std::ifstream read;
    read.open("C:\\Users\\Admin\\Desktop\\cpp\\Reserved\\Reserved 3\\Carozzz\\replay.txt");
    int index;
    std::string sline;
    std::cout << "Choose match to replay ";
    std::cin >> index;
    while (line_no != index && getline(read, sline))
    {
        ++line_no;
    }
    if (line_no == index)
    {
        read >> sline;
    }
   std::stringstream streamNumber(sline);
   std::string reference;
   while(std::getline(streamNumber, reference, ','))
   {
       coordinate.push_back(stoi(reference));
   }
}
void Replay::SeparateXY()
{
    for (int i = 1; i < coordinate.size(); i++)
    {
        if (i % 2 == 1)
        {
            Xposition.push_back(coordinate[i]);
        }
        if(i % 2 == 0)
        {
            Yposition.push_back(coordinate[i]);
        }
    }
}
void Replay::LoadReplay(const int& i)
{
    if (i % 2 == 0)
    {
        Player1Replay(Xposition[i], Yposition[i]);
    }
    else if (i % 2 == 1)
    {
        Player2Replay(Xposition[i], Yposition[i]);
    }
 system("cls");
}
int Replay::replayOver()
{
   return Xposition.size();
}
