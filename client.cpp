#include "client.hpp"

void Client::NewClient(string name, string cpf)
{
    m_name = name;
    m_cpf = cpf;
}

string Client::AddClient()
{
    cin.ignore();
    string name, cpf, date;
    cout << "Enter the Customer's name: " << endl;
    getline(cin, name);
    cout << "Enter the CPF of Client " << name << ":" << endl;
    getline(cin, cpf);
    NewClient(name, cpf);
    cout << "Enter the day of purchase:  " << endl;
    getline(cin, date);
    return date;
}
