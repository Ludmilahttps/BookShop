#include "cypher.hpp"
#include "convTable.hpp"

ConvTable::ConvTable()
{
}

ConvTable::~ConvTable()
{
    cout << "destructor ConvTable called" << endl;
}

vector<pair<char, char>> ConvTable::CreateTable(int num)
{
    for (size_t i = 0; i < 256; i++)
    {
        pair<char, char> p;
        p.first = i;
        p.second = p.first + num;
        table.push_back(p);
    }
    return table;
}

void ConvTable::ShowInfo(vector<pair<char, char>> Table)
{
    for (size_t i = 0; i < Table.size(); i++)
    {
        orig = Table.at(i).first;
        dest = Table.at(i).second;

        cout << " Orig: " << (char)orig << " - " << (int)orig << " -> "
             << " Destino: " << (char)dest << " - " << (int)dest << endl;
    }
}