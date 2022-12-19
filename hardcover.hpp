#ifndef HARDCOVER_HPP
#define HARDCOVER_HPP

#include "books.hpp"

class HardCover : public Books
{
protected:
    string m_bookH;
    string m_authorH;

public:
    HardCover() : m_bookH(""){};
    HardCover(Client *Client, float price, string bookH, string authorH) : Books(Client, price = 40), m_bookH(bookH), m_authorH(authorH){};
    ~HardCover(){};
    string GetBook() const { return m_bookH; };
    string GetAuthor() const { return m_authorH; };
};

#endif