#include "books.hpp"
#include "employees.hpp"
#include "historic.hpp"
#include "publishers.hpp"
#include "purchases.hpp"
#include "sales.hpp"

size_t menu();
size_t menu2();

main()
{
    size_t option = 0;
    do
    {
        option = menu();
        if (option == 1)
        {
            cout << "1. Sale" << endl;
            continue;
        }
        if (option == 2)
        {
            cout << "2. Show books" << endl;
            continue;
        }
        if (option == 3)
        {
            cout << "3. Show employees" << endl;
            continue;
        }
        if (option == 4)
        {
            cout << "4. Show historic" << endl;
            continue;
        }
        if (option == 5)
        {
            size_t option2 = 0;
            do
            {
            option2 = menu2();
            if (option2 == 1)
            {
                cout << "1. Buy books" << endl;
                continue;
            }
            if (option2 == 2)
            {
                cout << "2. Register employee" << endl;
                continue;
            }
            if (option2 == 3)
            {
                cout << "3. Register publisher" << endl;
                continue;
            }
            if (option2 == 4)
            {
                cout << "4. Exit to bookstore menu" << endl;
                break;
            }
            if (option2 != 1 || option2 != 2 || option2 != 3 || option2 != 4)
            {
                cout << "Please chose a valid number" << endl;
                continue;
            }
            } while (option2 != 4);
            continue;
        }
        if (option == 6)
        {
            cout << "5. Exit" << endl;
            break;
        }
        if (option != 1 || option != 2 || option != 3 || option != 4 || option != 5 || option != 6)
        {
            cout << "Please chose a valid number" << endl;
            continue;
        }
    } while (option != 6);
    return 0;
}

size_t menu()
{
    size_t option;

    cout << "---------------------Bookstore-------------------" << endl
         << "1. Sale" << endl
         << "2. Show books" << endl
         << "3. Show employees" << endl
         << "4. Show historic" << endl
         << "5. Registration menu" << endl
         << "6. Exit" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}

size_t menu2()
{
    size_t option;

    cout << "----------------Registration menu----------------" << endl
         << "1. Buy books" << endl
         << "2. Register employee" << endl
         << "3. Register publisher" << endl
         << "4. Exit to bookstore menu" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}