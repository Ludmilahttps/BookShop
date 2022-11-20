#ifndef IMPORTED_HPP
#define IMPORTED_HPP

#include "books.hpp"

class Imported : public Books
{
protected:
    string m_bookI;

public:
    Imported() : m_bookI(""){};
    Imported(Client *client, float price, string bookI) : Books(client, price = 60), m_bookI(bookI){};
    ~Imported(){};
    string GetBook() const { return m_bookI; };
};

#endif