#ifndef CLIENTE_HPP
#define CLIENTE_HPP

#include <iostream>
#include <string>
#include <vector>
#include <fstream>

using namespace std;

class Client
{
private:
    string m_name;
    string m_cpf;

public:
    Client() : m_name(""), m_cpf(""){};
    Client(string name, string cpf) : m_name(name), m_cpf(cpf){};
    ~Client(){};

    void NewClient(string name, string cpf); 
    string AddClient();
    string GetName() const { return m_name; };
    string GetCpf() const { return m_cpf; };
};

#endif