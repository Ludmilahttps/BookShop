#ifndef BOOKS_HPP
#define BOOKS_HPP

#include "client.hpp"
#include "publishers.hpp"

class Books : public Publishers
{
protected:
    float m_price;
    string m_date;
    Client *m_client;
    Publishers *m_publishers;

public:
    Books() : m_client(NULL), m_price(0), m_date(""){};
    Books(Client *client, float price) : m_client(client), m_price(price){};
    void Date(string date);
    string GetDate() const { return m_date; };
    float GetPrice() const { return m_price; };
    ~Books(){};

    string operator-()
    {
        return m_client->GetName();
    };
    string operator--()
    {
        return m_client->GetCpf();
    };
};

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