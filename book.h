#ifndef BOOK_H
#define BOOK_H

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>

class Book {
private:
    std::string Title;
    std::string Author;
    std::string Isbn;
    bool Availability;
    std::string DateAdd;

public:
    Book(const std::string& title, const std::string& author, const std::string& isbn)
        : Title(title), Author(author), Isbn(isbn), Availability(true) {
        time_t now = time(0);
        DateAdd = ctime(&now);
        DateAdd.pop_back(); 
    }

    // Destructor virtual requerido para herencia y punteros
    virtual ~Book() = default; 

    // Método 'virtual' para polimorfismo y 'const' para no modificar el objeto
    virtual void displayBookDetails() const {
        std::cout << "\n--- Detalles del Libro ---\n";
        std::cout << std::left << std::setw(15) << "Titulo:" << Title << std::endl;
        std::cout << std::left << std::setw(15) << "Autor:" << Author << std::endl;
        std::cout << std::left << std::setw(15) << "ISBN:" << Isbn << std::endl;
        std::cout << std::left << std::setw(15) << "Disponibilidad:" << (Availability ? "Si" : "No") << std::endl;
        std::cout << std::left << std::setw(15) << "Fecha Agregado:" << DateAdd << std::endl;
    }

    void borrowBook() {
        if (Availability) {
            Availability = false;
            std::cout << Title << " ha sido prestado.\n";
        } else {
            std::cout << Title << " no esta disponible para prestamo.\n";
        }
    }

    void retunBook() {
        Availability = true;
        std::cout << Title << " ha sido devuelto.\n";
    }

    // Getters necesarios para ordenar
    std::string getIsbn() const { return Isbn; }
    std::string getTitle() const { return Title; }
};

class Ebook : public Book {
private:
    std::string LicenseEndDate; 

public:
    Ebook(const std::string& title, const std::string& author, const std::string& isbn, const std::string& licenseEnd)
        : Book(title, author, isbn), LicenseEndDate(licenseEnd) {}
    
    // Usamos 'override' para sobrescribir la función virtual de la clase base
    void displayBookDetails() const override {
        Book::displayBookDetails(); 
        std::cout << std::left << std::setw(15) << "Tipo:" << "E-Book" << std::endl;
        std::cout << std::left << std::setw(15) << "Licencia Expira:" << LicenseEndDate << std::endl;
    }

    void setLicenseEnd(const std::string& date) { LicenseEndDate = date; }
};

class Hardcopy : public Book {
private:
    std::string ShelfLocation; 

public:
    Hardcopy(const std::string& title, const std::string& author, const std::string& isbn, const std::string& location)
        : Book(title, author, isbn), ShelfLocation(location) {}

    // Usamos 'override' para sobrescribir la función virtual de la clase base
    void displayBookDetails() const override {
        Book::displayBookDetails(); 
        std::cout << std::left << std::setw(15) << "Tipo:" << "Copia Fisica" << std::endl;
        std::cout << std::left << std::setw(15) << "Ubicacion:" << ShelfLocation << std::endl;
    }

    void setShelfLocation(const std::string& location) { ShelfLocation = location; }
};

#endif // BOOK_H