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
    int ok = 0;
    cout << "Enter the Customer's name: " << endl;
    getline(cin, name);

    do
    {
        cout << "Enter the CPF of Client " << name << ":" << endl;
        getline(cin, cpf);
        if (cpf.size() == 11)
        {
            cpf.insert(3, ".");
            cpf.insert(7, ".");
            cpf.insert(11, "-");
            NewClient(name, cpf);
            ok = 1;
        }
        else
        {
            // O CPF não tem exatamente 11 dígitos, então é inválido
            cout << "Your CPF is invalid. Please enter a valid 11-digit CPF." << endl;
            ok = 0;
        }
    } while (ok != 1);

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
