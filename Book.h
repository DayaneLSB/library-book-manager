#ifndef BOOK_H   // Header guard to prevent multiple inclusions
#define BOOK_H

#include <iostream>   // Enables use of input/output commands like cout
#include <string>     // Allows use of the string data type
using namespace std;  // Avoids needing std:: prefix

// =============================
// CLASS: Book (Base class)
// Represents a general book with title, author, ISBN, and availability status
// =============================
class Book {
protected:
    string title;       // Title of the book
    string author;      // Author of the book
    string isbn;        // Unique code to identify the book (ISBN)
    bool available;     // True = book is available; False = book is borrowed

public:
    // Constructor to initialize title and author
    Book(string t, string a) {
        title = t;
        author = a;
        isbn = "";
        available = true;  // New books are available by default
    }

    // Default constructor (used when creating book object without initial values)
    Book() {
        title = "";
        author = "";
        isbn = "";
        available = true;
    }

    // FUNCTION: setBookDetails
    // Sets the values for title, author, and ISBN
    void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        available = true;
    }

    // FUNCTION: isAvailable
    // Returns true if the book is not borrowed
    bool isAvailable() {
        return available;
    }

    // FUNCTION: getISBN
    // Returns the book's ISBN so we can search books by this ID
    string getISBN() {
        return isbn;
    }

    // FUNCTION: getTitle
    // Returns the book's title (used for sorting and comparing)
    string getTitle() {
        return title;
    }

    // FUNCTION: borrowBook
    // Marks the book as borrowed if it is available
    bool borrowBook() {
        if (available) {
            available = false;
            return true;
        } else {
            return false;  // Book is already borrowed
        }
    }

    // FUNCTION: returnBook
    // Marks the book as available again
    void returnBook() {
        available = true;
    }

    // FUNCTION: displayBookDetails
    // Displays basic book details; can be overridden by child classes
    virtual void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;
        cout << "Availability: " << (available ? "Available ✅" : "Borrowed ❌") << endl;
    }
};

// =============================
// CLASS: HardcopyBook (Derived from Book)
// Represents a physical book, with number of copies and shelf location
// =============================
class HardcopyBook : public Book {
private:
    int copies;           // How many copies are in the library
    string shelfNumber;   // Shelf location of the book

public:
    // Sets values specific to physical books
    void setHardcopyDetails(int c, string shelf) {
        copies = c;
        shelfNumber = shelf;
    }

    // Overrides base method to show more details for hardcopy books
    void displayBookDetails() override {
        Book::displayBookDetails();  // Show basic details
        cout << "Copies: " << copies << endl;
        cout << "Shelf Number: " << shelfNumber << endl;
    }
};

// =============================
// CLASS: EBook (Derived from Book)
// Represents a digital book with download link and expiration
// =============================
class EBook : public Book {
private:
    string downloadLink;     // URL to download the book
    string endLicenseDate;   // Date when license expires

public:
    // Sets values specific to digital books
    void setEBookDetails(string link, string endDate) {
        downloadLink = link;
        endLicenseDate = endDate;
    }

    // Overrides base method to include eBook-specific information
    void displayBookDetails() override {
        Book::displayBookDetails();  // Show basic details
        cout << "Download Link: " << downloadLink << endl;
        cout << "License Ends On: " << endLicenseDate << endl;
    }
};

#endif  // End of header guard
