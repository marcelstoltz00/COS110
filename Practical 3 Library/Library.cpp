#include "Library.h"
#include <iostream>
Library::Library()
{

    numBooks = 0;
    books = NULL;
};
Library::Library(const Library &other)
{

    numBooks = other.numBooks;

    books = new Book *[numBooks];

    for (int i = 0; i < numBooks; i++)
    {
        books[i] = new Book(*other.books[i]);
    }
};
Library &Library::operator=(const Library &other)
{
    if (this == &other)
    {
        return *this;
    }

    for (int i = 0; i < numBooks; i++)
    {
        delete books[i];
    }
    delete[] books;

    numBooks = other.numBooks;
    books = new Book *[numBooks];

    for (int i = 0; i < numBooks; i++)
    {
        books[i] = new Book(*other.books[i]);
    }

    return *this;
};
Library::~Library()
{

    for (int i = 0; i < numBooks; i++)
    {
        delete books[i];
    }
    delete[] books;
};
std::string Library::booksSummary()
{

    std::stringstream oss;

    for (int i = 0; i < numBooks; i++)
    {
        oss << books[i]->getBookInformation();
        if (i < numBooks - 1)
        {
            oss << "\n";
        }
    }

    return oss.str();
};
void Library::addBook(std::string title, std::string author, int numPages)
{

    Book **newbooks = new Book *[numBooks + 1];

    for (int i = 0; i < numBooks; i++)
    {

        newbooks[i] = books[i];
    }
    delete[] books;

    newbooks[numBooks] = new Book(title, author, numPages);

    books = newbooks;

    numBooks++;
};
int Library::readBook(std::string title, std::string author)
{
    bool found = false;
    std::string strfind = title + ":" + author;
    std::string str;

    int num = 0;
    for (int i = 0; i < numBooks; i++)
    {
        str = books[i]->getBookInformation();
        if (str.substr(0, strfind.size()) == strfind)
        {
            books[i]->readBook();

            int first = str.find('(') + 1;
            int last = str.find(')', first);
            std::stringstream ss;
            ss << str.substr(first, last - first);
            ss >> num;

            return num; // Return the number of pages
        }
    }

    if (!found)
        return -1;
};
int Library::totalNumberOfTimesRead()
{
    int total = 0;
    std::string str;
    std::stringstream pages;
    int value;
    for (int i = 0; i < numBooks; i++)
    {
        str = books[i]->getBookInformation();
        int j = str.find(')') + 1;
        pages << str.substr(j);
        pages >> value;
        pages.clear();

        total += value;
    }
    return total;
};
std::string Library::uniqueAuthors()
{
   /**/ std::string array = "";
    std::string str, author;
    int begin, final;

    for (int i = 0; i < numBooks; i++)
    {
        str = books[i]->getBookInformation();

        begin = str.find(':') + 1;
        final = str.find('(', begin);
        author = str.substr(begin, final - begin);

        if (array.find("[" + author + "]") == std::string::npos)
        {
            array += "[" + author + "]";
        }
        else
        {
        }
    }
    return array;




};
std::string Library::uniqueTitles()
{

    std::string array = "";
    std::string str, title;
    int begin, final;

    for (int i = 0; i < numBooks; i++)
    {
        str = books[i]->getBookInformation();

        begin = str.find(':');

        title = str.substr(0, begin);

        if (array.find("[" + title + "]") == std::string::npos)
        {
            array += "[" + title + "]";
        }
    }
    return array;
};