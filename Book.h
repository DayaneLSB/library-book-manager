#ifndef BOOK_H   // Start of include guard: prevents this file from being included more than once
#define BOOK_H   // Defines BOOK_H so it won’t be included again if already defined

#include <iostream>   // Allows input and output operations (e.g., cout, cin)
#include <string>     // Allows usage of the string data type
using namespace std;  // So we don’t need to write std:: every time

// This class represents a book in the library system
class Book {
private:  // Private attributes – only accessible within this class
    string title;       // Stores the title of the book
    string author;      // Stores the author of the book
    string isbn;        // Stores the unique ISBN identifier of the book
    bool available;     // True if the book is available, false if it’s already borrowed

public:  // Public methods – can be accessed from outside the class

    // Assigns values to the book's attributes
    void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        available = true;  // By default, the book is available when added
    }

    // Displays all the book’s details, including availability status
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;

        // Shows a visual flag depending on availability
        if (available) {
            cout << "Availability: Available ✅" << endl;
        } else {
            cout << "Availability: Borrowed ❌" << endl;
        }
    }

    // Attempts to borrow the book, only if it’s currently available
    bool borrowBook() {
        if (available) {
            available = false;  // Marks the book as borrowed
            return true;        // Borrow successful
        } else {
            return false;       // Book is already borrowed
        }
    }

    // Returns the book and marks it as available again
    void returnBook() {
        available = true;
    }

    // Returns the book’s ISBN – useful for search comparisons
    string getISBN() {
        return isbn;
    }
};

#endif  // End of include guard
