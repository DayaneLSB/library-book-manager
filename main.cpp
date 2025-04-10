#include <iostream>       // Required for input and output (cin, cout)
#include "Book.h"         // Includes the Book class from the header file

using namespace std;

int main() {
    // Creates an array of 5 Book objects to represent the library's collection
    Book library[5];

    // Sets the details (title, author, ISBN) for each book in the library
    library[0].setBookDetails("Dom Casmurro", "Machado de Assis", "111");
    library[1].setBookDetails("The Little Prince", "Saint-Exupéry", "222");
    library[2].setBookDetails("Harry Potter", "J.K. Rowling", "333");
    library[3].setBookDetails("1984", "George Orwell", "444");
    library[4].setBookDetails("Captains of the Sands", "Jorge Amado", "555");

    string inputISBN;  // Variable to store user input (ISBN to search)

    while (true) {
        // Prompts the user to enter an ISBN or 0 to exit
        cout << "\nEnter ISBN to borrow a book (or '0' to exit): ";
        cin >> inputISBN;

        if (inputISBN == "0") {
            // If user enters 0, exit the loop/program
            cout << "Exiting system. Thank you!" << endl;
            break;
        }

        bool found = false;  // Tracks whether the book was found in the array

        // Search through the array of books
        for (int i = 0; i < 5; i++) {
            // Compare the input ISBN with each book's ISBN
            if (library[i].getISBN() == inputISBN) {
                found = true;  // Book was found

                // Try to borrow the book
                if (library[i].borrowBook()) {
                    cout << "Book successfully borrowed!" << endl;
                } else {
                    cout << "Sorry, this book is already borrowed." << endl;
                }

                // Display the current status of the book
                library[i].displayBookDetails();
                break;  // Exit the loop since book was found
            }
        }

        // If no book matched the entered ISBN
        if (!found) {
            cout << "Book with ISBN " << inputISBN << " not found in the library." << endl;
        }
    }

    return 0;  // End of program
}
