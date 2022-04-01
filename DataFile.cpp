#include "DataFile.h"
#include <string.h>
#include <vector>
#include <fstream>
#include <regex>
#include <cmath>
#include <unordered_set>


DataFile::DataFile()
{

}
void DataFile::WriteFile(std::string name, int win, int lose, int draw)
{
    std::ofstream input;
    input.open("C:\\Users\\Admin\\Desktop\\cpp\\Reserved\\Reserved 3\\Carozzz\\Data.ini", std::ios::app);
    if (input.fail())
    {
        std::cout << "Can not open file." << std::endl;
    }
    else
    {
        input << name << " ";
        input << win << " ";
        input << lose << " ";
        input << draw << " ";
        input << std::endl;
        input.close();
    }
}
void DataFile::ReadFile(std::ifstream& read, Infor gameInfo[], int& count)
{
        count = 0;
        while (!read.eof())
        {
            read >> gameInfo[count].name >> gameInfo[count].win >> gameInfo[count].lose >> gameInfo[count].draw;
            count++;
        }
}
void DataFile::SortInfo()
{
    int count;
    std::ifstream readFile("C:\\Users\\Admin\\Desktop\\cpp\\Reserved\\Reserved 3\\Carozzz\\Data.ini");
    ReadFile(readFile, Database, count);
    for (int i = 0; i < count - 1; i++)
    {
        Basedata.push_back(Database[i]);
    }
    std::unordered_map<std::string, Infor> mapInfo;
    for (const auto& t : Basedata)
    {
        if(mapInfo.count(t.name) == 0)
        {
            mapInfo[t.name] = t;
        }
        else
        {
           mapInfo[t.name].win += t.win;
           mapInfo[t.name].lose += t.lose;
           mapInfo[t.name].draw += t.draw;
        }
    }
    for (const auto&[key, val] : mapInfo)
    {
        sortResult.push_back(val);
    }
    for (int i = 0; i < sortResult.size(); i++)
    {
        std::cout << "Name: " << sortResult[i].name << std::endl;
        std::cout << "Win : " << sortResult[i].win << std::endl;
        std::cout << "Lose: " << sortResult[i].lose << std::endl;
        std::cout << "Draw: " << sortResult[i].draw << std::endl;
    }
    for (int i = 0; i < sortResult.size(); i++)
    {
        double check = WinRate(sortResult[i].win, sortResult[i].lose, sortResult[i].draw);
        winRate.push_back(check);
    }
    sort(winRate.begin(), winRate.end());
    readFile.close();
}
void DataFile::LoadRank()
{
    double target;
    std::cin >> searchName;
    for (int i = 0; i < sortResult.size(); i++)
    {
        if(strcmp(searchName, sortResult[i].name) == 0)
        {
         std::cout << "Name: " << sortResult[i].name << std::endl;
         target = WinRate(sortResult[i].win, sortResult[i].lose, sortResult[i].draw);
         std::cout << "Win rate : " << target << "%" << std::endl;
        }
    }
    std::cout << "----" << std::endl;
   double opponent = FindClosest(target);
   for (int i = 0; i < sortResult.size(); i++)
   {
       if (opponent == WinRate(sortResult[i].win, sortResult[i].lose, sortResult[i].draw))
       {
           std::cout << "Suitable opponent: " << sortResult[i].name << std::endl;
           std::cout << "Win rate: " << opponent <<  "%" << std::endl;
       }
   }
}
double DataFile::FindClosest(const double& target)
{
    if (target == winRate.front()) return winRate[1];
    else if(target == winRate.back()) return winRate[winRate.size() - 2];
    else
    {
        for (int i = 1; i < winRate.size() - 1; i++)
        {
            double previous = winRate[i - 1];
            double after = winRate[i + 1];
            return getClosest(previous, after, target);
        }
    }
}
double DataFile::WinRate(const int& win, const int& lose, const int& draw)
{
    return (100 * win)/(win + lose + draw);
}
double DataFile::getClosest(const double& var1, const double& var2, const double& target)
{
    if ((target - var1) >= (var2 - target))
        return var2;
    else
        return var1;
}
void DataFile::EraseFile()
{
    std::ofstream input;
    input.open("C:\\Users\\Admin\\Desktop\\cpp\\Reserved\\Reserved 3\\Carozzz\\lastgame.text", std::ios::trunc);
    input.close();
}
void DataFile::WriteFileReplay(int x, int y)
{
    std::ofstream input;
    input.open("C:\\Users\\Admin\\Desktop\\cpp\\Reserved\\Reserved 3\\Carozzz\\lastgame.text", std::ios::app);
    input << x << " " << y << std::endl;
    input.close();
}

void DataFile::WriteSeparation()
{
    std::ofstream input;
    input.open("C:\\Users\\Admin\\Desktop\\cpp\\Reserved\\Reserved 3\\Carozzz\\replay.txt", std::ios::app);
    input << std::endl;
    input.close();
}
int DataFile::countMatch()
{
    std::string line;
    int count = 0;
    std::ifstream inFile("C:\\Users\\Admin\\Desktop\\cpp\\Reserved\\Reserved 3\\Carozzz\\replay.txt");
    while (inFile.peek() != EOF)
    {
        std::getline(inFile, line);
        count++;
    }
    inFile.close();
    return count;
}
void DataFile::WriteFileReplay1(int x, int y)
{
    std::ofstream input;
    input.open("C:\\Users\\Admin\\Desktop\\cpp\\Reserved\\Reserved 3\\Carozzz\\replay.txt", std::ios::app);
    input << "," << x << "," << y;
    input.close();
}
void DataFile::WriteGameOrder()
{
    std::ofstream input;
    input.open("C:\\Users\\Admin\\Desktop\\cpp\\Reserved\\Reserved 3\\Carozzz\\replay.txt", std::ios::app);
    input << countMatch();
}

