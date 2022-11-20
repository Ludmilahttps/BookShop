#include "books.hpp"
#include "employees.hpp"
#include "publishers.hpp"
#include "client.hpp"

Publishers *BookList = new Publishers();
Client *Customer = new Client;
Books *aux = new Books;
vector<Softcover *> SoftcoverBook;
vector<HardCover *> HardCoverBook;
vector<Imported *> ImportedBook;
size_t menu();
void Sale(int qtd);
void SaleSuccess();

int main()
{
    BookList->getBooks();
    size_t option = 0;
    do
    {
        option = menu();
        if (option == 1)
        {
            cout << "1. See All Books" << endl;
            cout << "These are the books available for purchase" << endl;
            BookList->ShowInfo();
            continue;
        }
        if (option == 2)
        {
            int IndexPublisher, IndexBook;
            cout << "2. Add Book to card" << endl;
            cout << "These are the books available for purchase" << endl;
            BookList->ShowInfo();
            cout << "What publisher index do you want? " << endl;
            cin >> IndexPublisher;
            cout << "What book index do you want? " << endl;
            cin >> IndexBook;
            Sale();
            continue;
        }
        if (option == 3)
        {
            cout << "3. Remove book" << endl;
            continue;
        }
        if (option == 4)
        {
            cout << "4. Show cart" << endl;
            continue;
        }
        if (option == 5)
        {
            cout << "5. Checkout" << endl;
            aux->Date(Customer->AddClient());
            SaleSuccess();
            continue;
        }
        if (option == 6)
        {
            cout << "6. Exit" << endl;
            break;
        }
        if (option != 1 || option != 2 || option != 3 || option != 4 || option != 5 || option != 6)
        {
            cout << "Please chose a valid number" << endl;
            continue;
        }
    } while (option != 6);

    int qtd;
    cout << "Enter the number of books to be purchased: " << endl;
    cin >> qtd;
    if (qtd <= 0)
    {
        cout << "Chose a valid number" << endl;
        return 1;
    }
    cin.ignore();

    Sale();
    return 0;
}

size_t menu()
{
    size_t option;

    cout << "---------------------Bookstore-------------------" << endl
         << "1. See All Books" << endl
         << "2. Add Book" << endl
         << "3. Remove book" << endl
         << "4. Show cart" << endl
         << "5. Checkout" << endl
         << "6. Exit" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}

void Sale()
{
    float price;
    string authorS, authorH, authorI, NbookS, NbookH, NbookI;
    int book;
    cout << "--------------------------------------------------- " << endl;
    cout << "Choose the type of book: " << endl;
    cout << "1 - SoftCover" << endl;
    cout << "2 - HardCover" << endl;
    cout << "3 - Imported" << endl;
    cout << "--------------------------------------------------- " << endl;
    cin >> book;
    cin.ignore();

    if (book == 1)
    {
        cout << "--------------------------------------------------- " << endl;
        Books c(Customer, price);
        cout << "Enter the name of the book: " << endl;
        getline(cin, NbookS);
        cout << "Enter the author of the book: " << endl;
        getline(cin, authorS);
        Softcover Soft(Customer, price, NbookS, authorS);
        SoftcoverBook.push_back(new Softcover(Soft));
        cout << "--------------------------------------------------- " << endl;
    }
    if (book == 2)
    {
        cout << "--------------------------------------------------- " << endl;
        Books c(Customer, price);
        cout << "Enter the name of the book: " << endl;
        getline(cin, NbookH);
        cout << "Enter the author of the book: " << endl;
        getline(cin, authorH);
        HardCover Hard(Customer, price, NbookH, authorH);
        HardCoverBook.push_back(new HardCover(Hard));
        cout << "--------------------------------------------------- " << endl;
    }
    if (book == 3)
    {
        cout << "--------------------------------------------------- " << endl;
        Books c(Customer, price);
        cout << "Enter the name of the book: " << endl;
        getline(cin, NbookI);
        cout << "Enter the author of the book:  " << endl;
        getline(cin, authorI);
        Imported Imp(Customer, price, NbookI, authorI);
        ImportedBook.push_back(new Imported(Imp));
        cout << "--------------------------------------------------- " << endl;
    }
    else if (book < 1 || book > 3)
    {
        cout << "Chose a valid number!" << endl;
        for (int i = 0; i < SoftcoverBook.size(); i++)
        {
            delete SoftcoverBook.at(i);
        }
        for (int i = 0; i < HardCoverBook.size(); i++)
        {
            delete HardCoverBook.at(i);
        }
        for (int i = 0; i < ImportedBook.size(); i++)
        {
            delete ImportedBook.at(i);
        }
        delete Customer;
        delete aux;
        return;
    }
}

void SaleSuccess()
{
    cout << "--------------------------------------------------- " << endl;
    cout << "         PURCHASE COMPLETED SUCCESSFULLY!           " << endl;
    cout << "--------------------------------------------------- " << endl;

    float value;
    cout << "Client name:   " << Customer->GetName() << endl;
    cout << "Client CPF:    " << Customer->GetCpf() << endl;
    cout << "Purchase day:  " << aux->GetDate() << endl
         << endl;

    for (int i = 0; i < SoftcoverBook.size(); i++)
    {
        cout << "SoftCover" << endl;
        cout << "Book:      " << SoftcoverBook.at(i)->GetBook() << endl;
        cout << "Author:    " << SoftcoverBook.at(i)->GetAuthor() << endl;
        cout << "Valor:     " << SoftcoverBook.at(i)->GetPrice() << endl;
        value = value + SoftcoverBook.at(i)->GetPrice();
    }
    for (int i = 0; i < HardCoverBook.size(); i++)
    {
        cout << "HardCover" << endl;
        cout << "Book:      " << HardCoverBook.at(i)->GetBook() << endl;
        cout << "Author:    " << HardCoverBook.at(i)->GetAuthor() << endl;
        cout << "Valor:     " << HardCoverBook.at(i)->GetPrice() << endl;
        value = value + HardCoverBook.at(i)->GetPrice();
    }
    for (int i = 0; i < ImportedBook.size(); i++)
    {
        cout << "Imported" << endl;
        cout << "Book:      " << ImportedBook.at(i)->GetBook() << endl;
        cout << "Author:    " << ImportedBook.at(i)->GetAuthor() << endl;
        cout << "Valor:     " << ImportedBook.at(i)->GetPrice() << endl;
        value = value + ImportedBook.at(i)->GetPrice();
    }

    cout << endl
         << "Amount:    " << value << endl;

    for (int i = 0; i < SoftcoverBook.size(); i++)
    {
        delete SoftcoverBook.at(i);
    }
    for (int i = 0; i < HardCoverBook.size(); i++)
    {
        delete HardCoverBook.at(i);
    }
    for (int i = 0; i < ImportedBook.size(); i++)
    {
        delete ImportedBook.at(i);
    }
    delete Customer;
    delete aux;
}
