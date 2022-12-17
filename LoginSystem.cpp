#include "LoginSystem.hpp"

bool LoginSystem::login()
{
    size_t option;
    do
    {
        option = menu();
        if (option == 1)
        {
            cout << "1. LogIn" << endl;
            /* DBs */
            std::ifstream nameDB("usernames.txt");
            std::ifstream passDB("passwords.txt");

            /* user input username & password */
            string uiUsername;
            string uiPassword;

            /* field input username & password */
            string fUsername;
            string fPassword;

            /* bools for usernameCorrect and passwordCorrect */
            bool usernameCorrect, passwordCorrect;

            /* Login */
            cout << "Login" << endl;

            cout << "Enter your username: " << endl;
            cin >> uiUsername;
            cout << "Enter your password: " << endl;
            cin >> uiPassword;

            /* Loop over usernames and set username to fUsername */
            while (std::getline(nameDB, fUsername))
            {
                /* Sets username to correct/incorrect */
                if (uiUsername == fUsername)
                {
                    usernameCorrect = true;
                    break;
                }
                else
                {
                    usernameCorrect = false;
                }
            }

            /* Same here */
            while (std::getline(passDB, fPassword))
            {
                if (uiPassword == fPassword)
                {
                    passwordCorrect = true;
                    break;
                }
                else
                {
                    passwordCorrect = false;
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
            else
            {
                return false;
            }
            continue;
        }
        
    
        if (option == 2)
        {
            cout << "2. SignUp" << endl;

            /* databases in append mode */
            ofstream nameDB("usernames.txt", ios_base::app);
            ofstream passDB("passwords.txt", ios_base::app);

            /* username & password */
            string username;
            string password;

            /* Add account */
            cout << "Register" << endl;

            cout << "Enter a username: " << endl;
            cin >> username;
            cout << "Enter a password: " << endl;
            cin >> password;

            /* Write to DBs */
            nameDB << endl << username;
            passDB << endl << password;

            continue;
        }
        if (option == 3)
        {
            cout << "3. Exit" << endl;
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

    cout << "------------Welcome to login system!-------------" << endl
         << "1. LogIn" << endl
         << "2. SignUp" << endl
         << "3. Exit" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}