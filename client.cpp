#include "client.hpp"
#include <time.h>

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

    time_t mytime;
    mytime = time(NULL);
    struct tm tm = *localtime(&mytime);
    int ano = (tm.tm_year + 1900);
    int mes = (tm.tm_mon + 1);
    int dia = (tm.tm_mday);
    string strA = to_string(dia);
    string strB = to_string(mes);
    string strC = to_string(ano);
    date = strA + "/" + strB + "/" + strC;
    return date;
}
