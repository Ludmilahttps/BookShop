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
size_t MenuHistoric();
void saveInfo();
void Historic();
void UpdateStock();
void UpdatePublisher();
void Sale(pair<string, string>);
void ShowCart();
void DeleteItem(int, int);
void SaleSuccess();

int main()
{
    bool validation = login->login();

    if (validation)
    {
        BookList->getBooks();
        size_t option = 0;
        do
        {
            option = menu();
            if (option == 1)
            {
                system("cls");
                cout << "1. Sales department" << endl;
                do
                {
                    option = SalesDepartment();
                    if (option == 1)
                    {
                        system("cls");
                        cout << "1. See All Books" << endl;
                        cout << "These are the books in the stock" << endl;
                        BookList->ShowInfo();
                        continue;
                    }
                    if (option == 2)
                    {
                        int IndexPublisher, IndexBook;
                        system("cls");
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
                        system("cls");
                        cout << "3. Remove book" << endl;
                        cout << "These are the books in your cart" << endl;
                        ShowCart();

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
                        system("cls");
                        cout << "4. Show cart" << endl;
                        ShowCart();
                        continue;
                    }
                    if (option == 5)
                    {
                        system("cls");
                        cout << "5. Checkout" << endl;
                        aux->Date(Customer->AddClient());
                        SaleSuccess();
                        continue;
                    }
                    if (option == 6)
                    {
                        system("cls");
                        cout << "6. Back Menu" << endl;
                        break;
                    }
                    if (option != 1 || option != 2 || option != 3 || option != 4 || option != 5 || option != 6)
                    {
                        system("cls");
                        cout << "Please chose a valid number" << endl;
                        continue;
                    }
                } while (option != 6);
                continue;
            }
            if (option == 2)
            {
                system("cls");
                size_t opc;
                cout << "2. Register" << endl;
                do
                {
                    opc = Register();
                    if (opc == 1)
                    {
                        system("cls");
                        cout << "1. Register Employee" << endl;
                        string encrypted;
                        string decrypted;
                        Cypher *crypter;
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
                        // cin >> username;

                        encrypted = crypter->EncryptText(username);

                        nameDB << endl;
                        nameDB.write(encrypted.c_str(), encrypted.length());

                        cout << "Enter a password: " << endl;
                        getline(cin >> ws, password);
                        // cin >> password;

                        encrypted = crypter->EncryptText(password);

                        passDB << endl;
                        passDB.write(encrypted.c_str(), encrypted.length());
                        continue;
                    }
                    if (opc == 2)
                    {
                        system("cls");
                        cout << "2. Register Publisher" << endl;
                        UpdatePublisher();
                        BookList->deleteBooks();
                        BookList->getBooks();
                        continue;
                    }
                    if (opc == 3)
                    {
                        system("cls");
                        cout << "3. Register Book" << endl;
                        UpdateStock();
                        BookList->deleteBooks();
                        BookList->getBooks();
                        continue;
                    }
                    if (opc == 4)
                    {
                        system("cls");
                        cout << "4. Exit" << endl;
                        break;
                    }
                    if (opc != 1 || opc != 2 || opc != 3 || opc != 4)
                    {
                        system("cls");
                        cout << "Please chose a valid number" << endl;
                        continue;
                    }
                } while (opc != 4);
                continue;
            }
            if (option == 3)
            {
                system("cls");
                size_t opt;
                cout << "3. Historical (historico de vendas)" << endl;
                do
                {
                    opt = MenuHistoric();
                    if (opt == 1)
                    {
                        system("cls");
                        cout << "1. See Sales History" << endl;
                        Historic();
                        continue;
                    }
                    if (opt == 2)
                    {
                        system("cls");
                        cout << "2. Reset history" << endl;
                        ofstream out("Historic.txt", ofstream::out | ofstream::trunc);
                        continue;
                    }
                    if (opt == 3)
                    {
                        system("cls");
                        cout << "3. Export history to PDF" << endl;
                        // //Cria um novo documento PDF
                        //                                           HPDF_Doc pdf = HPDF_New(NULL, NULL);
                        // if (!pdf)
                        // {
                        //     std::cerr << "Erro ao criar documento PDF" << std::endl;
                        //     return 1;
                        // }

                        // // Abre o arquivo de texto para leitura
                        // std::ifstream txt_file("texto.txt");
                        // if (!txt_file.is_open())
                        // {
                        //     std::cerr << "Erro ao abrir arquivo de texto" << std::endl;
                        //     return 1;
                        // }

                        // // Lê o conteúdo do arquivo de texto
                        // std::string text;
                        // std::string line;
                        // while (std::getline(txt_file, line))
                        // {
                        //     text += line + "\n";
                        // }

                        // // Cria uma nova página no documento PDF
                        // HPDF_Page page = HPDF_AddPage(pdf);

                        // // Define o tamanho da fonte e o estilo
                        // HPDF_Font font = HPDF_GetFont(pdf, "Helvetica", NULL);
                        // HPDF_Page_SetFontAndSize(page, font, 12);

                        // // Adiciona o conteúdo do arquivo de texto à página
                        // HPDF_Page_BeginText(page);
                        // HPDF_Page_TextOut(page, 50, 500, text.c_str());
                        // HPDF_Page_EndText(page);

                        // // Salva o documento PDF em um arquivo
                        // HPDF_SaveToFile(pdf, "documento.pdf");

                        // // Finaliza o documento e libera a memória alocada
                        // HPDF_Free(pdf);
                        continue;
                    }
                    if (opt == 4)
                    {
                        system("cls");
                        cout << "4. Exit" << endl;
                        break;
                    }
                    if (opt != 1 || opt != 2 || opt != 3 || opt != 4)
                    {
                        system("cls");
                        cout << "Please chose a valid number" << endl;
                        continue;
                    }
                } while (opt != 4);
                continue;
            }
            if (option == 4)
            {
                system("cls");
                cout << "4. Exit" << endl;
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
                break;
            }
            if (option != 1 || option != 2 || option != 3 || option != 4)
            {
                system("cls");
                cout << "Please chose a valid number" << endl;
                continue;
            }
        } while (option != 4);
    }
    else
    {
        cout << "bye bye" << endl;
    }
    delete Customer;
    delete aux;
    delete BookList;
    return 0;
}

size_t menu()
{
    size_t option;
    system("cls");
    cout << "---------------------Bookstore-------------------" << endl
         << "1. Sales department(tela do vendedor)" << endl
         << "2. Register(cadastro de funcionarios e editoras e livros)" << endl
         << "3. Historical(historico de vendas)" << endl
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
         << "6. Back menu" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}

size_t MenuHistoric()
{
    size_t option;
    cout << "----------------Historic-----------------" << endl
         << "1. See sales history" << endl
         << "2. Reset history" << endl
         << "3. Export history to PDF" << endl
         << "4. Back menu" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}

size_t Register()
{
    size_t option;
    system("cls");
    cout << "---------------------Register-------------------" << endl
         << "1. Register Employee" << endl
         << "2. Register Publisher" << endl
         << "3. Register Book" << endl
         << "4. Back menu" << endl
         << "-------------------------------------------------" << endl
         << "Option:";
    cin >> option;

    return option;
}

void Sale(pair<string, string> element)
{
    string authorName = element.first, bookName = element.second;
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
        // Books c(Customer, price);
        Softcover Soft(Customer, price, bookName, authorName);
        SoftcoverBook.push_back(new Softcover(Soft));
    }
    if (type == 2)
    {
        // Books c(Customer, price);
        HardCover Hard(Customer, price, bookName, authorName);
        HardCoverBook.push_back(new HardCover(Hard));
    }
    if (type == 3)
    {
        // Books c(Customer, price);
        Imported Imp(Customer, price, bookName, authorName);
        ImportedBook.push_back(new Imported(Imp));
    }
    else if (type < 1 || type > 3)
    {
        cout << "Chose a valid number!" << endl;
        return;
    }
    system("cls");
    return;
}

void ShowCart()
{
    for (int i = 0; i < SoftcoverBook.size(); i++)
    {
        if (SoftcoverBook.at(i) != nullptr)
        {
            cout << "SoftCover" << i << endl;
            cout << "Book:      " << SoftcoverBook.at(i)->operator&() << endl;
            cout << "Author:    " << SoftcoverBook.at(i)->GetAuthor() << endl;
            cout << "Valor:     " << SoftcoverBook.at(i)->operator++() << endl;
        }
    }
    for (int i = 0; i < HardCoverBook.size(); i++)
    {
        if (HardCoverBook.at(i) != nullptr)
        {
            cout << "HardCover" << i << endl;
            cout << "Book:      " << HardCoverBook.at(i)->GetBook() << endl;
            cout << "Author:    " << HardCoverBook.at(i)->GetAuthor() << endl;
            cout << "Valor:     " << HardCoverBook.at(i)->operator++() << endl;
        }
    }
    for (int i = 0; i < ImportedBook.size(); i++)
    {
        if (ImportedBook.at(i) != nullptr)
        {
            cout << "Imported" << i << endl;
            cout << "Book:      " << ImportedBook.at(i)->GetBook() << endl;
            cout << "Author:    " << ImportedBook.at(i)->GetAuthor() << endl;
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
        if (SoftcoverBook.at(i) != nullptr)
        {
            cout << "SoftCover" << endl;
            cout << "Book:      " << SoftcoverBook.at(i)->operator&() << endl;
            cout << "Author:    " << SoftcoverBook.at(i)->GetAuthor() << endl;
            cout << "Valor:     " << SoftcoverBook.at(i)->operator++() << endl;
            value = value + SoftcoverBook.at(i)->operator++();
        }
    }
    for (int i = 0; i < HardCoverBook.size(); i++)
    {
        if (HardCoverBook.at(i) != nullptr)
        {
            cout << "HardCover" << endl;
            cout << "Book:      " << HardCoverBook.at(i)->GetBook() << endl;
            cout << "Author:    " << HardCoverBook.at(i)->GetAuthor() << endl;
            cout << "Valor:     " << HardCoverBook.at(i)->operator++() << endl;
            value = value + HardCoverBook.at(i)->operator++();
        }
    }
    for (int i = 0; i < ImportedBook.size(); i++)
    {
        if (ImportedBook.at(i) != nullptr)
        {
            cout << "Imported" << endl;
            cout << "Book:      " << ImportedBook.at(i)->GetBook() << endl;
            cout << "Author:    " << ImportedBook.at(i)->GetAuthor() << endl;
            cout << "Valor:     " << ImportedBook.at(i)->operator++() << endl;
            value = value + ImportedBook.at(i)->operator++();
        }
    }

    cout << endl
         << "Amount:    " << value << endl;

    saveInfo();

    // Deleto os itens do carrinho
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

void saveInfo()
{
    cout << "here";
    ofstream OutFile;
    OutFile.open("Historic.txt", ios_base::app);
    if (OutFile.is_open())
    {
        OutFile << endl
                << endl;
        OutFile << "--------------------------------------------------- " << endl;
        OutFile << " " << aux->operator+() << "  " << Customer->operator-() << "  " << Customer->operator--() << endl;
        OutFile << "--------------------------------------------------- " << endl;

        float value;

        for (int i = 0; i < SoftcoverBook.size(); i++)
        {
            if (SoftcoverBook.at(i) != nullptr)
            {
                OutFile << "SoftCover" << endl;
                OutFile << "Book: " << SoftcoverBook.at(i)->operator&() << " by " << SoftcoverBook.at(i)->GetAuthor() << endl;
                OutFile << "Valor: " << SoftcoverBook.at(i)->operator++() << endl;
                value = value + SoftcoverBook.at(i)->operator++();
            }
        }
        for (int i = 0; i < HardCoverBook.size(); i++)
        {
            if (HardCoverBook.at(i) != nullptr)
            {
                OutFile << "HardCover" << endl;
                OutFile << "Book: " << HardCoverBook.at(i)->GetBook() << " by " << HardCoverBook.at(i)->GetAuthor() << endl;
                OutFile << "Valor: " << HardCoverBook.at(i)->operator++() << endl;
                value = value + HardCoverBook.at(i)->operator++();
            }
        }
        for (int i = 0; i < ImportedBook.size(); i++)
        {
            if (ImportedBook.at(i) != nullptr)
            {
                OutFile << "Imported" << endl;
                OutFile << "Book: " << ImportedBook.at(i)->GetBook() << " by " << ImportedBook.at(i)->GetAuthor() << endl;
                OutFile << "Valor: " << ImportedBook.at(i)->operator++() << endl;
                value = value + ImportedBook.at(i)->operator++();
            }
        }
        OutFile << endl
                << "Amount: " << value << endl;
        OutFile.close();
    }
    else
    {
        cout << "File not found" << endl;
    }
}

void Historic()
{
    ifstream infile("Historic.txt"); // abre o arquivo em questão para pegar as strings

    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            cout << line << endl;
        }
        infile.close(); // fecha o arquivo
        return;
    }
    cout << "Historic is empty" << endl;

    return;
}