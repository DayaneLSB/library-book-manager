#include <iostream>
#include "Book.h"  // deve incluir a classe Book com o construtor adequado

using namespace std;

int main() {
    cout << "=== CORRECT BOOK INFORMATION ===\n";

    // Instâncias corretas
    Book book1("Dom Casmurro", "Machado de Assis", 111, "Available", "20/01/2024");
    Book book2("The Little Prince", "Saint-Exupéry", 222, "Available", "25/08/2023");
    Book book3("Harry Potter", "J.K. Rowling", 333, "Borrowed", "15/06/2021");

    book1.display(); // você precisa ter uma função display() na sua classe
    book2.display();
    book3.display();

    cout << "\n=== INCORRECT BOOK INFORMATION ===\n";

    // Instâncias incorretas (mesmo que o código compile, os dados estão errados)
    Book wrong1("Casmurro", "Machad", 0101, "No-available", "01/02/2024");
    Book wrong2("The Prince", "Saint", 0202, "Borrowed", "25/08/2000");
    Book wrong3("Mr Harry", "Rowling", 0303, "Available", "15/07/2020");

    wrong1.display();
    wrong2.display();
    wrong3.display();

    return 0;
}

