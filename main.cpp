#include <iostream>
#include "Book.h"
using namespace std;

int main() {
    Book library[5];  // Array of 5 Book objects

    // Initialize each book with title, author, and ISBN
    library[0].setBookDetails("Dom Casmurro", "Machado de Assis", "111");
    library[1].setBookDetails("The Little Prince", "Saint-Exupéry", "222");
    library[2].setBookDetails("Harry Potter", "J.K. Rowling", "333");
    library[3].setBookDetails("1984", "George Orwell", "444");
    library[4].setBookDetails("Captains of the Sands", "Jorge Amado", "555");

    string inputISBN;
    while (true) {
        // Ask user for the ISBN of the book to borrow
        cout << "\nEnter ISBN to borrow a book (or '0' to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            cout << "Exiting system. Thank you!" << endl;
            break;
        }

        bool found = false;

        // Search for the book in the library
        for (int i = 0; i < 5; i++) {
            if (library[i].getISBN() == inputISBN) {
                found = true;
                if (library[i].borrowBook()) {
                    cout << "Book successfully borrowed!" << endl;
                } else {
                    cout << "Sorry, this book is already borrowed." << endl;
                }
                library[i].displayBookDetails();
                break;
            }
        }

        if (!found) {
            cout << "Book with ISBN " << inputISBN << " not found in the library." << endl;
        }
    }

    return 0;
}
