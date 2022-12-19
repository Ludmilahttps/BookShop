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
#include <time.h>
#include <cstdlib>
//#include <hpdf.h>

using namespace std; // ¯\(°_o)/¯

class Publishers
{
private:
    vector<pair<string, vector<pair<string, string>>>> m_ListOfBooks;
    pair<string, vector<pair<string, string>>> m_Publishers;
    string m_Publisher;
    vector<pair<string, string>> m_Books;

public: 
    vector<string> filenames;
    Publishers();

    //getters and setters
    void ShowInfo();
    void getBooks();
    void getPublishers();
    bool open_file(string m_Publisher, vector<pair<string, string>> &m_Books);
    void addFile(string newFile);
    void addBook(string publisher);
    pair<string, string> GetInfo(int IPublisher, int IBook);
};

#endif