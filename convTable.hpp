#ifndef CONVTABLE_HPP
#define CONVTABLE_HPP

#include "convTable.hpp"
#include "Publishers.hpp"

using namespace std;

class ConvTable
{
private:
    vector<pair<char, char>> table;
    char orig;
    char dest;

public:
    ConvTable();
    ~ConvTable();

    void ShowInfo(vector<pair<char, char>>);
    vector<pair<char, char>> CreateTable(int);
};

#endif