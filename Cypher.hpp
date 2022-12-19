#ifndef CYPHER_HPP
#define CYPHER_HPP

#include <iostream>
#include <vector>
#include <string>
#include <strings.h>
#include <cstring>
#include "convTable.hpp"

using namespace std;

class Cypher
{
private:
    string *m_input;
    vector<pair<char, char>> Table;
    string *encrypted;
    string *decrypted;
    ConvTable *ConvertTable;
    int *m_num;

protected:
public:
    Cypher() : ConvertTable(NULL) {};
    Cypher(int imp);
    ~Cypher();

    void ShowInfo();
    void NewConversionTable(int code);
    string EncryptText(string);
    string DecryptText(string);
    // string callEncryptText();
};

#endif