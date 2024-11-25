#include <iostream>
#include "Book.h"
#include "Library.h"

int main() {
    Library lib;

    
    lib.addBook("The Catcher in the Rye", "J.D. Salinger", 277);  
    lib.addBook("The Catcher in the Rye", "J.D. Salinger", 277);
    lib.addBook("To Kill a Mockingbird", "Harper Lee", 281);
    lib.addBook("1984", "George Orwell", 328);

    lib.addBook("Brave New World", "Aldous Huxley", 311);

   
    std::cout <<  lib.booksSummary() << std::endl;

    int pagesRead = lib.readBook("1984", "George Orwell");
    if (pagesRead != -1) {
        std::cout << "Read '1984' by George Orwell. It has " << pagesRead << " pages." << std::endl;
    } else {
        std::cout << "The book '1984' by George Orwell was not found." << std::endl;
    }

   // std::cout  << lib.booksSummary() << std::endl;
   // std::cout  << lib.totalNumberOfTimesRead() << std::endl;

   std::cout<<"    im here    "<<std::endl;
    std::cout  << lib.uniqueAuthors() << std::endl;
    std::cout << lib.uniqueTitles() << std::endl;

    Library libraryCopy(lib);
    std::cout  << libraryCopy.booksSummary() << std::endl;

    Library anotherLibray;
    anotherLibray = lib;
    std::cout  << anotherLibray.booksSummary() << std::endl;

    return 0;
}
