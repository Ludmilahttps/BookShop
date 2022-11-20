#ifndef HARDCOVER_HPP
#define HARDCOVER_HPP

#include "books.hpp"

class HardCover : public Books
{
protected:
    string m_bookH;

public:
    HardCover() : m_bookH(""){};
    HardCover(Client *Client, float price, string bookH) : Books(Client, price = 40), m_bookH(bookH){};
    ~HardCover(){};
    string GetBook() const { return m_bookH; };
};

#endif