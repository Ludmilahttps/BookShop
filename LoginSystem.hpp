#ifndef LOGINSYSTEM_HPP
#define LOGINSYSTEM_HPP

#include "Publishers.hpp"
#include "cypher.hpp"
#include "convTable.hpp"

class LoginSystem {
private:
    std::string loginFile;

public:
    // Construtor
    LoginSystem() {}

    bool login();
    size_t menu();
};

#endif