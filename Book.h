#ifndef BOOK_H   // Prevent this file from being included more than once
#define BOOK_H

#include <iostream>   // Required for cout and cin
#include <string>     // Allows the use of string data type
using namespace std;  // So we don’t have to write std:: before string, cout, etc.

// -------------------------------------------
// BASE CLASS: Book (general attributes shared by all types of books)
// -------------------------------------------
class Book {
protected:  // 'protected' allows child classes to access these attributes
    string title;         // Book title
    string author;        // Book author
    string isbn;          // Unique ISBN identifier
    bool available;       // True if available, false if borrowed

public:
    // Set the main details of a book
    void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        available = true;  // A new book starts as available
    }

    // Returns the availability status (used in main)
    bool isAvailable() {
        return available;
    }

    // Returns the book's ISBN so it can be compared in main
    string getISBN() {
        return isbn;
    }

    // Borrows the book if available
    bool borrowBook() {
        if (available) {
            available = false;  // Mark as borrowed
            return true;
        } else {
            return false;       // Already borrowed
        }
    }

    // Return the book to make it available again
    void returnBook() {
        available = true;
    }

    // Display the book details (can be overridden by child classes)
    virtual void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;

        if (available) {
            cout << "Availability: Available ✅" << endl;
        } else {
            cout << "Availability: Borrowed ❌" << endl;
        }
    }
};

// -------------------------------------------
// SUBCLASS: HardcopyBook (physical books)
// -------------------------------------------
class HardcopyBook : public Book {
private:
    int copies;             // Number of physical copies
    string shelfNumber;     // Shelf location in the library

public:
    // Set the specific details for a hardcopy book
    void setHardcopyDetails(int c, string shelf) {
        copies = c;
        shelfNumber = shelf;
    }

    // Override the display method to show additional details
    void displayBookDetails() override {
        Book::displayBookDetails();  // Call the base class version first
        cout << "Copies: " << copies << endl;
        cout << "Shelf Number: " << shelfNumber << endl;
    }
};

// -------------------------------------------
// SUBCLASS: EBook (digital books)
// -------------------------------------------
class EBook : public Book {
private:
    string downloadLink;     // Link where the book can be downloaded
    string endLicenseDate;   // When the license for this book expires

public:
    // Set specific details for an e-book
    void setEBookDetails(string link, string endDate) {
        downloadLink = link;
        endLicenseDate = endDate;
    }

    // Override the display method to show additional details
    void displayBookDetails() override {
        Book::displayBookDetails();  // Show the common book info first
        cout << "Download Link: " << downloadLink << endl;
        cout << "License Ends On: " << endLicenseDate << endl;
    }
};

#endif  // End of include guard
