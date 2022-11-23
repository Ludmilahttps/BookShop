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
    ~Books(){};

    string operator+()
    {
        return m_date;
    };
    float operator++()
    {
        return m_price;
    };
};

#endif
