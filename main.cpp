#include "book.h.cpp"
#include <iostream>
#include <limits> 

using namespace std;

int findBook(Book books[], int size, const string& isbn) {
    for (int i = 0; i < size; ++i) {
        if (books[i].getIsbn() == isbn) {
            return i; 
        }
    }
    return -1; 
}

void clearInputBuffer() {
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

int main() {
    const int NUM_BOOKS = 5;
    Book library[NUM_BOOKS];

    library[0].setBookDetails("Cien años de soledad", "Gabriel García Márquez", "9788497592208", {10, 1, 1967});
    library[1].setBookDetails("La sombra del viento", "Carlos Ruiz Zafón", "9788408092942", {15, 2, 2001});
    library[2].setBookDetails("El tiempo entre costuras", "María Dueñas", "9788499984922", {1, 3, 2009});
    library[3].setBookDetails("Patria", "Fernando Aramburu", "9788483103211", {20, 4, 2016});
    library[4].setBookDetails("Los renglones torcidos de Dios", "Torcuato Luca de Tena", "9788408000497", {5, 5, 1979});

    string userIsbn;
    int choice;
    int index;

    cout << "--- LIBRARY MANAGEMENT SYSTEM (C++) ---\n";

    do {
        cout << "\n--- MENU ---\n";
        cout << "1. Display all books\n";
        cout << "2. Borrow a book by ISBN\n";
        cout << "3. Return a book by ISBN\n";
        cout << "0. Exit program\n";
        cout << "Select an option: ";
        
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Try again.\n";
            clearInputBuffer();
            continue;
        }

        if (choice == 0) {
            cout << "Program terminated. Goodbye!\n";
            break; 
        }

        if (choice == 1) {
            cout << "\n--- COMPLETE LISTING ---\n";
            for (int i = 0; i < NUM_BOOKS; ++i) {
                library[i].displayBookDetails();
            }
            continue;
        }

        if (choice == 2 || choice == 3) {
            cout << "Enter the book ISBN (or '0' to exit): ";
            cin >> userIsbn;
            
            if (userIsbn == "0") {
                 cout << "Program terminated. Goodbye!\n";
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
                cout << "ERROR: Book with ISBN " << userIsbn << " not found in the library.\n";
            }
        } else {
            cout << "Invalid menu option. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}