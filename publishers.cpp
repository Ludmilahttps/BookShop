#include "publishers.hpp"
Publishers::Publishers()
{
    ifstream infile("filenames"); // abre o arquivo em questão para pegar as strings
    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            if (line.size() != 0)
            {
                filenames.push_back(line);
            }
        }
        infile.close(); // fecha o arquivo
    }
}

void Publishers::getBooks()
{
    for (int i = 0; i < filenames.size(); i++)
    {
        m_Publisher = filenames[i];
        if (open_file(m_Publisher, m_Books, m_Authors))
        {
            m_Publishers.first = m_Publisher;
            m_Publishers.second = m_Books;
            m_ListOfBooks.push_back(m_Publishers);
            m_Books.clear();
        }
    }
}

bool Publishers::open_file(string m_Publisher, vector<string> &m_Books, vector<string> &m_Authors)
{
    ifstream infile(m_Publisher); // abre o arquivo em questão para pegar as strings

    if (infile.is_open())
    {
        string line;
        int aux = 0;
        while (getline(infile, line))
        {
            if (line.size() != 0)
            {
                if (aux % 2 == 0)
                {
                    m_Books.push_back(line);
                }
                else
                {
                    m_Authors.push_back(line);
                }
            }
            aux++;
        }
        infile.close(); // fecha o arquivo
        return true;
    }
    else
    {
        cout << "File not found" << endl;
        return false;
    }
};

void Publishers::ShowInfo()
{
    for (size_t i = 0; i < m_ListOfBooks.size(); i++)
    {
        for (size_t j = 0; j < m_ListOfBooks.at(i).second.size(); j++)
        {
            cout << "Publisher " << i << " : \t" << m_ListOfBooks.at(i).first << "\t   Book " << j << " : " << m_ListOfBooks.at(i).second.at(j)
                 << endl;
        }
    }
}

pair<string, string> Publishers::GetInfo(int IPublisher, int IBook)
{
    pair<string, string> aux;

    aux.first = m_ListOfBooks.at(IPublisher).first;
    aux.second = m_ListOfBooks.at(IPublisher).second.at(IBook);

    return aux;
}

void Publishers::addFile(string newFile)
{
    filenames.push_back(newFile);
    ofstream outfile(newFile);
    if (outfile.is_open())
    {
        outfile.close();
    }
    ofstream out;
    out.open("filenames", ios_base::app);
    if (out.is_open())
    {
        out << endl << newFile ;
    }
    else
    {
        cout << "File not found" << endl;
    }
    newFile.clear();
}

void Publishers::getPublishers()
{
    for (int i = 0; i < filenames.size(); i++)
    {
        cout << i + 1 << "  " << filenames[i] << endl;
    }
}

void Publishers::addBook(string publisher)
{
    //cout << "HERE" << endl;
    string NBook, NAuthor;
    int num = stoi(publisher);
    
    for (int i = 0; i < filenames.size(); i++)
    {
        if ((i + 1) == num)
        {
            ofstream OutFile;
            OutFile.open(filenames[i], ios_base::app);
            if (OutFile.is_open())
            {
                cout << "type a name of book" << endl;
                cin.ignore();
                getline(cin, NBook);
                OutFile << endl << NBook << endl ;
                cout << "type a name of Author book" << endl;
                getline(cin, NAuthor);
                OutFile  << NAuthor;
                OutFile.close();
            }
            else
            {
                cout << "File not found" << endl;
            }
        }
    }
}