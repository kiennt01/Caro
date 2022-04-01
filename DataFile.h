#ifndef DATAFILE_H
#define DATAFILE_H
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include "Global.h"
#include "Replay.h"


class DataFile
{
private:
    Infor Database[100];
    std::vector<Infor> Basedata;
    std::vector<Infor> sortResult;
    char searchName[50];
    std::vector<double> winRate;

public:
    DataFile();
    void WriteFileReplay(int, int);
    void WriteSeparation();
    void WriteFile(std::string name, int win, int lose, int draw);
    void ReadFile(std::ifstream&, Infor[], int&);
    void SortInfo();
    void LoadRank();
    double FindClosest(const double&);
    double WinRate(const int&, const int&, const int&);
    double getClosest(const double&, const double&, const double&);
    void EraseFile();
    void WriteFileReplay1(int, int);
    int countMatch();
    void WriteGameOrder();

};
#endif // DATAFILE_H
