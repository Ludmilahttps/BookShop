#ifndef SOFTCOVER_HPP
#define SOFTCOVER_HPP

#include "books.hpp"

class Softcover : public Books
{
protected:
    string m_bookS;

public:
    Softcover() : m_bookS(""){};
    Softcover(Client *client, float price, string bookS) : Books(client, price = 20), m_bookS(bookS){};
    ~Softcover(){};
    string GetBook() const { return m_bookS; };
};

#endif