#include "Book.h"
#include <iostream>
#include <limits> // Necesario para std::numeric_limits

using namespace std;

// Función para buscar un libro en el array por ISBN
int findBook(Book books[], int size, const string& isbn) {
    for (int i = 0; i < size; ++i) {
        if (books[i].getIsbn() == isbn) {
            return i; // Devuelve el índice del libro encontrado
        }
    }
    return -1; // No encontrado
}

void clearInputBuffer() {
    // Limpia el buffer de entrada para evitar errores de lectura posteriores
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    // 1. Inicializar un array con 5 libros
    const int NUM_BOOKS = 5;
    Book library[NUM_BOOKS];

    // Datos de ejemplo con la estructura Date
    library[0].setBookDetails("C++ Primer", "Stanley B. Lippman", "9780321714114", {10, 1, 2024});
    library[1].setBookDetails("The C++ Programming Language", "Bjarne Stroustrup", "9780321563842", {15, 2, 2024});
    library[2].setBookDetails("Effective Modern C++", "Scott Meyers", "9781491903995", {1, 3, 2024});
    library[3].setBookDetails("Clean Code", "Robert C. Martin", "9780132350884", {20, 4, 2024});
    library[4].setBookDetails("Design Patterns", "Erich Gamma et al.", "9780201633610", {5, 5, 2024});

    string userIsbn;
    int choice;
    int index;

    cout << "--- SISTEMA DE GESTION DE BIBLIOTECA (C++) ---\n";

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Mostrar todos los libros\n";
        cout << "2. Prestar un libro por ISBN\n";
        cout << "3. Devolver un libro por ISBN\n";
        cout << "0. Salir del programa\n";
        cout << "Seleccione una opcion: ";
        
        cin >> choice;

        if (cin.fail()) {
            cout << "Entrada invalida. Intente de nuevo.\n";
            clearInputBuffer();
            continue;
        }

        if (choice == 0) {
            cout << "Programa terminado. ¡Hasta pronto!\n";
            break; // Termina si la opción es 0
        }

        // Si la opción no requiere ISBN, la procesamos
        if (choice == 1) {
            cout << "\n--- LISTADO COMPLETO ---\n";
            for (int i = 0; i < NUM_BOOKS; ++i) {
                library[i].displayBookDetails();
            }
            continue;
        }

        // Lógica para opciones 2 (Prestar) y 3 (Devolver)
        if (choice == 2 || choice == 3) {
            cout << "Ingrese el ISBN del libro (o '0' para salir): ";
            cin >> userIsbn;
            
            // Terminará cuando el usuario ingrese "0"
            if (userIsbn == "0") {
                 cout << "Programa terminado. ¡Hasta pronto!\n";
                 choice = 0;
                 break;
            }
            
            index = findBook(library, NUM_BOOKS, userIsbn);
            
            if (index != -1) {
                if (choice == 2) {
                    library[index].borrowBook(); 
                } else {
                    library[index].returnBook(); 
                }
            } else {
                // Mensaje de error si el libro no está disponible (o no existe) 
                cout << "ERROR: Libro con ISBN " << userIsbn << " no encontrado en la biblioteca.\n";
            }
        } else {
            cout << "Opcion de menu no valida. Intente de nuevo.\n";
        }

    } while (choice != 0);

    return 0;
}