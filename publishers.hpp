#ifndef PUBLISHERS_HPP
#define PUBLISHERS_HPP

#include <iostream>
#include <sstream>
#include <iostream>
#include <vector>
#include <string>
#include <cstring>
#include <fstream>
#include <sstream>
#include <algorithm>

using namespace std;

class Publishers
{
private:
    vector<pair<string, vector<string>>> m_ListOfBooks;
    pair<string, vector<string>> m_Publishers;
    string m_Publisher;
    vector<string> m_Books;
    vector<string> filenames;

public:
    //Publishers() : {};
    Publishers() : filenames({"Darkside", "Rocco", "Harper_Collins"}){};

    //getters and setters
    void ShowInfo();
    void getBooks();
    bool open_file(string m_Publisher, vector<string> &m_Books);
    
};


#endif