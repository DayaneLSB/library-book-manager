#ifndef BOOK_H   // Início do bloco de proteção contra inclusão múltipla
#define BOOK_H   // Define que BOOK_H está sendo incluído

#include <iostream>   // Permite usar comandos de entrada e saída como cout e cin
#include <string>     // Permite usar o tipo string (texto)
using namespace std;  // Evita precisar escrever std:: o tempo todo

// Esta classe representa um livro no sistema da biblioteca
class Book {
private:  // Tudo que estiver aqui só pode ser acessado por métodos da própria classe
    string title;       // Armazena o título do livro
    string author;      // Armazena o autor do livro
    string isbn;        // Armazena o código ISBN do livro (identificador único)
    bool available;     // Se true, o livro está disponível; se false, está emprestado

public:   // Os métodos abaixo podem ser acessados de fora da classe

    // Define os detalhes do livro: título, autor, ISBN
    void setBookDetails(string t, string a, string i) {
        title = t;
        author = a;
        isbn = i;
        available = true;  // Sempre que um livro é cadastrado, ele começa como disponível
    }

    // Exibe os detalhes do livro, com uma "flag" indicando se está disponível
    void displayBookDetails() {
        cout << "Title: " << title << endl;
        cout << "Author: " << author << endl;
        cout << "ISBN: " << isbn << endl;

        // Se o livro estiver disponível, mostra uma flag ✅. Se não, mostra ❌.
        if (available) {
            cout << "Availability: Available ✅" << endl;
        } else {
            cout << "Availability: Borrowed ❌" << endl;
        }
    }

    // Tenta emprestar o livro. Só funciona se ele estiver disponível.
    bool borrowBook() {
        if (available) {
            available = false;  // Marca como emprestado
            return true;        // Empréstimo realizado com sucesso
        } else {
            return false;       // Livro já está emprestado, não pode emprestar de novo
        }
    }

    // Devolve o livro e marca como disponível novamente
    void returnBook() {
        available = true;
    }

    // Retorna o ISBN do livro (usado para procurar um livro na lista)
    string getISBN() {
        return isbn;
    }
};

#endif  // Fim da proteção contra múltiplas inclusões
