#ifndef SOFTCOVER_HPP
#define SOFTCOVER_HPP

#include "books.hpp"

class Softcover : public Books
{
protected:
    string m_bookS;
    string m_authorS;

public:
    Softcover() : m_bookS(""){};
    Softcover(Client *client, float price, string bookS, string authorS) : Books(client, price = 20), m_bookS(bookS), m_authorS(authorS){};
    ~Softcover(){};
    string operator&() const { return m_bookS; };
    string GetAuthor() const { return m_authorS; };
};

#endif