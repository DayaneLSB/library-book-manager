#ifndef BOOK_H   // This prevents the file from being included multiple times in one compilation
#define BOOK_H   // Defines BOOK_H to control this include guard

#include <iostream>   // Allows input and output commands (e.g., cout and cin)
#include <string>     // Enables the use of the string data type
using namespace std;  // So we don't need to write "std::" before string or cout

// This class represents a book in the library system
class Book {
private:  // These variables can only be accessed from inside this class

    string title;       // Stores the title of the book
    string author;      // Stores the author's name
    string isbn;        // Stores the ISBN, which is a unique code for the book
    bool available;     // True if the book is available, false if it's borrowed

public:  // These functions can be accessed from outside the class (for example, from main)

    // This function sets the details of the book (title, author, ISBN)
    void setBookDetails(string t, string a, string i) {
        title = t;        // Assigns the title
        author = a;       // Assigns the author
        isbn = i;         // Assigns the ISBN
        available = true; // When a book is created, it's marked as available
    }

    // ✅ New method to check if the book is available
    bool isAvailable() {
        return available;  // Returns the current availability status
    }

    // This function displays the book's details on the screen
    void displayBookDetails() {
        cout << "Title: " << title << endl;     // Shows the title
        cout << "Author: " << author << endl;   // Shows the author
        cout << "ISBN: " << isbn << endl;       // Shows the ISBN

        // This part checks if the book is available or borrowed and shows a message with a symbol
        if (available) {
            cout << "Availability: Available ✅" << endl;  // If available, show green check
        } else {
            cout << "Availability: Borrowed ❌" << endl;   // If borrowed, show red X
        }
    }

    // This function tries to borrow the book
    bool borrowBook() {
        if (available) {             // If the book is available
            available = false;       // Change its status to borrowed
            return true;             // Return true to show it worked
        } else {
            return false;            // If not available, return false
        }
    }

    // This function marks the book as returned (available again)
    void returnBook() {
        available = true;            // Set the book as available again
    }

    // This function gives access to the ISBN so it can be checked elsewhere
    string getISBN() {
        return isbn;                 // Returns the ISBN for comparison
    }
};

#endif  // This ends the include guard started at the top
