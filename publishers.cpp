#include "publishers.hpp"

void Publishers::getBooks()
{
    for(int i=0;i<filenames.size();i++)
    {
        m_Publisher = filenames[i];
        if (open_file(m_Publisher, m_Books))
        {
            m_Publishers.first = m_Publisher;
            m_Publishers.second = m_Books;
            m_ListOfBooks.push_back(m_Publishers);
            m_Books.clear();
        }
    }
    
}

bool Publishers::open_file(string m_Publisher, vector<string> &m_Books)
{
    ifstream infile(m_Publisher); // abre o arquivo em questão para pegar as strings

    vector<string> newfile;

    if (infile.is_open())
    {
        string line;
        while (getline(infile, line))
        {
            istringstream ss_line(line);
            if (line.size() != 0)
            {
                m_Books.push_back(line);
            }
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
    for(int i=0;i<filenames.size();i++)
    {
        cout << "Filename: " << filenames[i] << endl;
    }

    for (size_t i = 0; i < m_ListOfBooks.size(); i++)
    {
        for (size_t j = 0; j < m_ListOfBooks.at(i).second.size(); j++)
        {
            cout <<"Publisher: "<<  m_ListOfBooks.at(i).first << "    Book: " << m_ListOfBooks.at(i).second.at(j) << endl;
        }
    }
    
}