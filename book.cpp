#include "book.h.cpp"
#include <iostream>
#include <iomanip>

// Implementación del método para asignar valores
void Book::setBookDetails(std::string title, std::string author, std::string isbn, Date date) {
    Title = title;
    Author = author;
    Isbn = isbn;
    DateAdd = date;
    Availability = true; // El libro comienza disponible
}

// Implementación del método para mostrar detalles
void Book::displayBookDetails() const {
    std::cout << "\n--- DETALLES DE " << Title << " ---\n";
    std::cout << "Autor: " << Author << "\n";
    std::cout << "ISBN: " << Isbn << "\n";
    std::cout << "Adquisición: " << DateAdd.day << "/" << DateAdd.month << "/" << DateAdd.year << "\n";
    std::cout << "Estado: " << (Availability ? "DISPONIBLE" : "PRESTADO") << "\n";
    std::cout << "--------------------------------\n";
}

// Inicializamos el resto de los métodos por ahora (Lógica pendiente)
void Book::borrowBook() { 
    if (Availability) {
        Availability = false;
        std::cout << "Libro prestado exitosamente.\n";
    } else {
        std::cout << "ERROR: El libro ya está prestado.\n";
    }
}
void Book::returnBook() { 
    if (!Availability) {
        Availability = true;
        std::cout << "Libro devuelto exitosamente. Ahora está DISPONIBLE.\n";
    } else {
        std::cout << "ERROR: El libro ya estaba disponible.\n";
    }
}
void Book::sortBookData(Book books[], int size) { /* Lógica de ordenamiento pendiente */ }