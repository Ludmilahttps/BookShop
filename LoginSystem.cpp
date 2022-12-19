#include "LoginSystem.hpp"

bool LoginSystem::login()
{
    string encrypted;
    string decrypted;
    Cypher *crypter;
    int code;
    crypter = new Cypher(2210);
    // chama a tabela de conversão, se atualizar todas as senhas cadastradas anteriormento entram em desuso

    size_t option;
    do
    {
        option = menu();
        if (option == 1)
        {
            system("cls");
            cout << "1. LogIn" << endl;
            /* DBs */
            fstream nameDB("usernames.bin", ios::in | ios::binary);
            fstream passDB("passwords.bin", ios::in | ios::binary);

            /* user input username & password */
            string uiUsername;
            string uiPassword;
            /* field input username & password */
            string fUsername;
            string fPassword;

            /* bools for usernameCorrect and passwordCorrect */
            bool usernameCorrect, passwordCorrect;

            cout << "Enter your username: " << endl;
            getline(cin >> ws, uiUsername);
            //cin >> uiUsername;

            encrypted = crypter->EncryptText(uiUsername);

            /* Loop over usernames and set username to fUsername */
            while (nameDB >> fUsername)
            {
                if (encrypted == fUsername)
                {
                    usernameCorrect = true;
                    break;
                }
            }

            cout << "Enter your password: " << endl;
            getline(cin >> ws, uiPassword);
            //cin >> uiPassword;

            encrypted = crypter->EncryptText(uiPassword);

            /* Same here */
            while (passDB >> fPassword)
            {
                if (encrypted == fPassword)
                {
                    passwordCorrect = true;
                    break;
                }
            }

            /*
            If username and password are correct, say hi to user,
            else, no.
            */
            if (usernameCorrect && passwordCorrect)
            {
                cout << "Hello, " << uiUsername << "!" << endl;
                return true;
            }
            continue;
        }

        if (option == 2)
        {
            system("cls");
            cout << "2. SignUp" << endl;

            /* databases in append mode */
            fstream nameDB("usernames.bin", ios::out | ios::binary | ios::app);
            fstream passDB("passwords.bin", ios::out | ios::binary | ios::app);

            /* username & password */
            string username;
            string password;

            /* Add account */
            cout << "Register" << endl;

            cout << "Enter a username: " << endl;
            getline(cin >> ws, username);
            //cin >> username;

            encrypted = crypter->EncryptText(username);

            nameDB << endl;
            nameDB.write(encrypted.c_str(), encrypted.length());

            cout << "Enter a password: " << endl;
            getline(cin >> ws, password);
            //cin >> password;
            
            encrypted = crypter->EncryptText(password);

            passDB << endl;
            passDB.write(encrypted.c_str(), encrypted.length());

            continue;
        }
        if (option == 3)
        {
            cout << "3. Exit" << endl;
            return false;
            break;
        }
        if (option != 1 || option != 2 || option != 3)
        {
            cout << "Please chose a valid number" << endl;
            continue;
        }
    } while (option != 3);
}

size_t LoginSystem::menu()
{
    size_t option;
    system("cls");
    cout << "------------Welcome to login system!-------------" << endl
         << "1. LogIn" << endl
         << "2. SignUp" << endl
         << "3. Exit" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}