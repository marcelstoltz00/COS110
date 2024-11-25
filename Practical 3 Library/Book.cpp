#include "Book.h"

Book::Book(std::string title, std::string author, int numPages)
{

    this->title = title;
    this->author = author;
    this->numPages = numPages;

    numberOfTimesRead = 0;
};
Book::Book(const Book &other)
{

    title = other.title;
    author = other.author;
    numPages = other.numPages;

    numberOfTimesRead = 0;
};
Book &Book::operator=(const Book &other)
{
    if (this == &other)
    {
    }
    else
    {
        title = other.title;
        author = other.author;
        numPages = other.numPages;
        numberOfTimesRead = other.numberOfTimesRead;
    }
    return *this;
};
Book::~Book() {};
std::string Book::getBookInformation()
{

    std::stringstream oss;

    oss << title;
    oss << ':';
    oss << author << '(' << numPages << ')' << numberOfTimesRead;

    return oss.str();
};
void Book::readBook() { this->numberOfTimesRead++; };