#include <iostream>       // Allows us to use input/output (cin and cout)
#include "Book.h"         // Includes the Book class we created in Book.h

using namespace std;      // So we don't have to write std:: before cout, cin, string etc.

int main() {
    // Creates an array called 'library' to store 5 books
    Book library[5];

    // Set up the details (title, author, ISBN) for each book in the library
    library[0].setBookDetails("Dom Casmurro", "Machado de Assis", "111");
    library[1].setBookDetails("The Little Prince", "Saint-Exupéry", "222");
    library[2].setBookDetails("Harry Potter", "J.K. Rowling", "333");
    library[3].setBookDetails("1984", "George Orwell", "444");
    library[4].setBookDetails("Captains of the Sands", "Jorge Amado", "555");

    // Optional: simulate some books already borrowed
    library[1].borrowBook();  // The Little Prince is already borrowed
    library[4].borrowBook();  // Captains of the Sands is already borrowed

    string inputISBN;  // A variable to store the ISBN entered by the user

    // This loop keeps running until the user types "0" to exit
    while (true) {
        // Ask the user to type the ISBN of the book they want to borrow
        cout << "\nEnter ISBN to borrow a book (or '0' to exit): ";
        cin >> inputISBN;

        // If the user typed "0", we stop the program
        if (inputISBN == "0") {
            cout << "Exiting system. Thank you!" << endl;
            break;  // Exit the loop and end the program
        }

        bool found = false;  // This will track if we found the book or not

        // Loop through each book in the library
        for (int i = 0; i < 5; i++) {
            // Check if the current book's ISBN matches the one entered
            if (library[i].getISBN() == inputISBN) {
                found = true;  // A matching book was found

                // First, display the book's current status
                library[i].displayBookDetails();

                // Then, try to borrow the book if it's available
                if (library[i].isAvailable()) {
                    library[i].borrowBook();
                    cout << "Book successfully borrowed!" << endl;
                } else {
                    cout << "Sorry, this book is already borrowed." << endl;
                }

                break;  // Stop searching after finding the book
            }
        }

        // If the book wasn't found after checking all 5 books
        if (!found) {
            cout << "Book with ISBN " << inputISBN << " not found in the library." << endl;
        }
    }

    return 0;  // Ends the program successfully
}
