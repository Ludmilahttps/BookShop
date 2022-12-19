#ifndef IMPORTED_HPP
#define IMPORTED_HPP

#include "books.hpp"

class Imported : public Books
{
protected:
    string m_bookI;
    string m_authorI;

public:
    Imported() : m_bookI(""){};
    Imported(Client *client, float price, string bookI, string authorI) : Books(client, price = 60), m_bookI(bookI), m_authorI(authorI){};
    ~Imported(){};
    string GetBook() const { return m_bookI; };
    string GetAuthor() const { return m_authorI; };
};

#endif