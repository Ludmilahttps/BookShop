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

using namespace std; // ¯\(°_o)/¯

class Publishers
{
private:
    vector<pair<string, vector<string>>> m_ListOfBooks;
    pair<string, vector<string>> m_Publishers;
    string m_Publisher;
    vector<string> m_Books;
    vector<string> m_Authors;

public: 
    vector<string> filenames;
    Publishers();

    //getters and setters
    void ShowInfo();
    void getBooks();
    void getPublishers();
    bool open_file(string m_Publisher, vector<string> &m_Books, vector<string> &m_Authors);
    void addFile(string newFile);
    void addBook(string publisher);
    pair<string, string> GetInfo(int IPublisher, int IBook);
};

#endif