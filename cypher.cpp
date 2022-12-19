#include "cypher.hpp"
#include "convTable.hpp"

Cypher::Cypher(int code) : Cypher()
{
    ConvertTable = new ConvTable();

    int sum = 0, x = code;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    } // soma todos os numeros da matricula
    code = sum - 10;

    Table = ConvertTable->CreateTable(code);
    // ConvertTable->ShowInfo(Table);
}

Cypher::~Cypher()
{
    cout << "destructor Cypher called" << endl;

    if (m_input)
        delete m_input;
    if (ConvertTable)
        delete ConvertTable;
}

void Cypher::ShowInfo()
{
    ConvertTable->ShowInfo(Table);
    return;
}

void Cypher::NewConversionTable(int code)
{
    ConvertTable = new ConvTable();

    int sum = 0, x = code;
    while (x > 0)
    {
        sum += x % 10;
        x /= 10;
    } // soma todos os numeros da matricula
    code = sum - 10;

    Table = ConvertTable->CreateTable(code);
    // ConvertTable->ShowInfo(Table);

}

string Cypher::EncryptText(string input)
{
    this->m_input = new string;
    *this->m_input = input;

    string result;
    for (size_t i = 0; i < input.length(); i++)
    {
        char chi = input.at(i);                // input character
        char cho = this->Table.at(chi).second; // output character
        result += cho;
    }
    return result;
};

string Cypher::DecryptText(string input)
{
    string result;
    for (size_t i = 0; i < input.length(); i++)
    {
        char chi = input.at(i); // input character
        for (size_t j = 0; j < Table.size(); j++)
        {
            if (chi == Table.at(j).second)
            {
                result += Table.at(j).first;
                break;
            }
        }
    }
    return result;
}