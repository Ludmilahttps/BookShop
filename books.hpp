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

#endif
