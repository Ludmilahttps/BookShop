#include "books.hpp"
#include "publishers.hpp"
#include "client.hpp"
#include "softcover.hpp"
#include "hardcover.hpp"
#include "imported.hpp"
#include "LoginSystem.hpp"

Publishers *BookList = new Publishers();
Client *Customer = new Client;
Books *aux = new Books;
LoginSystem *login = new LoginSystem();

vector<Softcover *> SoftcoverBook;
vector<HardCover *> HardCoverBook;
vector<Imported *> ImportedBook;

size_t SalesDepartment();
size_t menu();
size_t Register();
void UpdateStock();
void UpdatePublisher();
void Sale(pair<string, string>);
void ShowCart();
void DeleteItem(int, int);
void SaleSuccess();

int main()
{
    bool validation = login->login();

    if(validation)
    {
        BookList->getBooks();
        size_t option = 0;
        do
        {
            option = menu();
            if (option == 1)
            {
                cout << "1. Sales department" << endl;
                do
                {
                option = SalesDepartment();
                if (option == 1)
                {
                    cout << "1. See All Books" << endl;
                    cout << "These are the books in the stock" << endl;
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

                    Sale(BookList->GetInfo(IndexPublisher, IndexBook));
                    continue;
                }
                if (option == 3)
                {
                    int Type, NameB;
                    cout << "3. Remove book" << endl;
                    cout << "These are the books in your cart" << endl;
                    void ShowCart();

                    cout << "What type of book do you want to delete? 1.SoftCover 2.HardCover 3.Imported" << endl;
                    cin >> Type;
                    if (Type < 1 || Type > 3)
                    {
                        cout << "Chose a valid number" << endl;
                        continue;
                    }
                    cout << "What book index do you want delete? " << endl;
                    cin >> NameB;

                    DeleteItem(Type, NameB);
                    continue;
                }
                if (option == 4)
                {
                    cout << "4. Show cart" << endl;
                    ShowCart();
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
                    for (int i = 0; i < SoftcoverBook.size(); i++)
                    {
                        delete SoftcoverBook.at(i);
                        SoftcoverBook.erase(remove(SoftcoverBook.begin(), SoftcoverBook.end(), SoftcoverBook.at(i)));
                    }
                    for (int i = 0; i < HardCoverBook.size(); i++)
                    {
                        delete HardCoverBook.at(i);
                        HardCoverBook.erase(remove(HardCoverBook.begin(), HardCoverBook.end(), HardCoverBook.at(i)));
                    }
                    for (int i = 0; i < ImportedBook.size(); i++)
                    {
                        delete ImportedBook.at(i);
                        ImportedBook.erase(remove(ImportedBook.begin(), ImportedBook.end(), ImportedBook.at(i)));
                    }
                    delete Customer;
                    delete aux;
                    break;
                }
                if (option != 1 || option != 2 || option != 3 || option != 4 || option != 5 || option != 6)
                {
                    cout << "Please chose a valid number" << endl;
                    continue;
                }
                } while (option != 6);
                continue;
            }
            if (option == 2)
            {
                cout << "2. Register" << endl;
                do
                {
                option = Register();
                if (option == 1)
                {
                    cout << "1. Register Employee" << endl;
                    continue;
                }
                if (option == 2)
                {
                    cout << "2. Register Publisher" << endl;
                    UpdatePublisher();
                    continue;
                }
                if (option == 3)
                {
                    cout << "3. Register Book" << endl;
                    void UpdateStock();
                    continue;
                }
                if (option == 4)
                {
                    cout << "4. Exit" << endl;
                    break;
                }
                if (option != 1 || option != 2 || option != 3 || option != 4)
                {
                    cout << "Please chose a valid number" << endl;
                    continue;
                }
                } while (option != 4);
                continue;
            }
            if (option == 3)
            {
                cout << "3. Historical(historico de compra e venda)" << endl;
                continue;
            }
            if (option == 4)
            {
                cout << "4. Exit" << endl;
                break;
            }
            if (option != 1 || option != 2 || option != 3 || option != 4 )
            {
                cout << "Please chose a valid number" << endl;
                continue;
            }
        } while (option != 4);
    }
    else
    {
        cout << "I couldn't find that account." << endl;
    }
    delete Customer;
    delete aux;
    return 0;
}

size_t menu()
{
    size_t option;

    cout << "---------------------Bookstore-------------------" << endl
         << "1. Sales department(tela do vendedor)" << endl
         << "2. Register(cadastro de funcionarios e editoras e livros)" << endl
         << "3. Historical(historico de compra e venda)" << endl
         << "4. Exit" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}

size_t SalesDepartment()
{
    size_t option;

    cout << "----------------Sales Department-----------------" << endl
         << "1. See All Books" << endl
         << "2. Add Book in cart" << endl
         << "3. Remove book from cart" << endl
         << "4. Show cart" << endl
         << "5. Checkout" << endl
         << "6. Exit" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}

size_t Register()
{
    size_t option;

    cout << "---------------------Register-------------------" << endl
         << "1. Register Employee" << endl
         << "2. Register Publisher" << endl
         << "3. Register Book" << endl
         << "4. Exit" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}

void Sale(pair<string, string> element)
{
    string publisherName = element.first, bookName = element.second;
    float price;
    int type;

    cout << "--------------------------------------------------- " << endl;
    cout << "Choose the type of " << bookName << " : " << endl;
    cout << "1 - SoftCover" << endl;
    cout << "2 - HardCover" << endl;
    cout << "3 - Imported" << endl;
    cout << "--------------------------------------------------- " << endl;
    cin >> type;
    cin.ignore();

    if (type == 1)
    {
        //Books c(Customer, price);
        Softcover Soft(Customer, price, bookName);
        SoftcoverBook.push_back(new Softcover(Soft));
    }
    if (type == 2)
    {
        //Books c(Customer, price);
        HardCover Hard(Customer, price, bookName);
        HardCoverBook.push_back(new HardCover(Hard));
    }
    if (type == 3)
    {
        //Books c(Customer, price);
        Imported Imp(Customer, price, bookName);
        ImportedBook.push_back(new Imported(Imp));
    }
    else if (type < 1 || type > 3)
    {
        cout << "Chose a valid number!" << endl;
        return;
    }
    return;
}

void ShowCart()
{
    for (int i = 0; i < SoftcoverBook.size(); i++)
    {
        if(SoftcoverBook.at(i) != nullptr)
        {
        cout << "SoftCover" << i << endl;
        cout << "Book:      " << SoftcoverBook.at(i)->operator&() << endl;
        cout << "Valor:     " << SoftcoverBook.at(i)->operator++() << endl;
        }
    }
    for (int i = 0; i < HardCoverBook.size(); i++)
    {
        if(HardCoverBook.at(i) != nullptr)
        {
        cout << "HardCover" << i << endl;
        cout << "Book:      " << HardCoverBook.at(i)->GetBook() << endl;
        cout << "Valor:     " << HardCoverBook.at(i)->operator++() << endl;
        }
    }
    for (int i = 0; i < ImportedBook.size(); i++)
    {
        if(ImportedBook.at(i) != nullptr)
        {
        cout << "Imported" << i << endl;
        cout << "Book:      " << ImportedBook.at(i)->GetBook() << endl;
        cout << "Valor:     " << ImportedBook.at(i)->operator++() << endl;
        }
    }
    return;
}

void DeleteItem(int Type, int NameB)
{
    if (Type == 1)
    {
        delete SoftcoverBook.at(NameB);
        SoftcoverBook.erase(remove(SoftcoverBook.begin(), SoftcoverBook.end(), SoftcoverBook.at(NameB)));
        cout << "deleted" << endl;
    }
    if (Type == 2)
    {
        delete HardCoverBook.at(NameB);
        HardCoverBook.erase(remove(HardCoverBook.begin(), HardCoverBook.end(), HardCoverBook.at(NameB)));
        cout << "deleted" << endl;
    }
    if (Type == 3)
    {
        delete ImportedBook.at(NameB);
        ImportedBook.erase(remove(ImportedBook.begin(), ImportedBook.end(), ImportedBook.at(NameB)));
        cout << "deleted" << endl;
    }
    return;
}

void SaleSuccess()
{
    cout << "--------------------------------------------------- " << endl;
    cout << "         PURCHASE COMPLETED SUCCESSFULLY!           " << endl;
    cout << "--------------------------------------------------- " << endl;

    float value;
    cout << "Client name:   " << Customer->operator-() << endl;
    cout << "Client CPF:    " << Customer->operator--() << endl;
    cout << "Purchase day:  " << aux->operator+() << endl
         << endl;

    for (int i = 0; i < SoftcoverBook.size(); i++)
    {
        if(SoftcoverBook.at(i) != nullptr)
        {
        cout << "SoftCover" << endl;
        cout << "Book:      " << SoftcoverBook.at(i)->operator&() << endl;
        cout << "Valor:     " << SoftcoverBook.at(i)->operator++() << endl;
        value = value + SoftcoverBook.at(i)->operator++();
        }
    }
    for (int i = 0; i < HardCoverBook.size(); i++)
    {
        if(HardCoverBook.at(i) != nullptr)
        {
        cout << "HardCover" << endl;
        cout << "Book:      " << HardCoverBook.at(i)->GetBook() << endl;
        cout << "Valor:     " << HardCoverBook.at(i)->operator++() << endl;
        value = value + HardCoverBook.at(i)->operator++();
        }
    }
    for (int i = 0; i < ImportedBook.size(); i++)
    {
        if(ImportedBook.at(i) != nullptr)
        {
        cout << "Imported" << endl;
        cout << "Book:      " << ImportedBook.at(i)->GetBook() << endl;
        cout << "Valor:     " << ImportedBook.at(i)->operator++() << endl;
        value = value + ImportedBook.at(i)->operator++();
        }
    }

    cout << endl
         << "Amount:    " << value << endl;

    //Deleto os itens do carrinho
    for (int i = 0; i < SoftcoverBook.size(); i++)
    {
        delete SoftcoverBook.at(i);
        SoftcoverBook.erase(remove(SoftcoverBook.begin(), SoftcoverBook.end(), SoftcoverBook.at(i)));
    }
    for (int i = 0; i < HardCoverBook.size(); i++)
    {
        delete HardCoverBook.at(i);
        HardCoverBook.erase(remove(HardCoverBook.begin(), HardCoverBook.end(), HardCoverBook.at(i)));
    }
    for (int i = 0; i < ImportedBook.size(); i++)
    {
        delete ImportedBook.at(i);
        ImportedBook.erase(remove(ImportedBook.begin(), ImportedBook.end(), ImportedBook.at(i)));
    }
    return;
}

void UpdateStock()
{
    string addBook;
    cout << "The book you want to add to stock is from which publisher?" << endl;
    BookList->getPublishers();
    cout << "0 to back menu to add new publisher" << endl;
    cin >> addBook;
    do
    {
        BookList->addBook(addBook);
        return;

    } while (addBook != "0");
    return;
}

void UpdatePublisher()
{
    string NewPublisher;
    cout << "To add a new publisher type a name" << endl;
    cin >> NewPublisher;
    BookList->addFile(NewPublisher);
    return;
}