#include "book.h.cpp"
#include <iostream>
#include <limits> 
#include <string>

using namespace std;

int findBook(Book* books[], int size, const string& isbn) {
    for (int i = 0; i < size; ++i) {
        if (books[i]->getIsbn() == isbn) {
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
    Book* library[NUM_BOOKS];

    // Hardcopy
    library[0] = new Hardcopy;
    ((Hardcopy*)library[0])->setHardcopyDetails("Cien años de soledad", "Gabriel García Márquez", "9788497592208", {10, 1, 1967}, "Chapter 1");

    // Ebook
    library[1] = new Ebook;
    ((Ebook*)library[1])->setEbookDetails("La sombra del viento", "Carlos Ruiz Zafón", "9788408092942", {15, 2, 2001}, "15/2/2001");

    // Hardcopy
    library[2] = new Hardcopy;
    ((Hardcopy*)library[2])->setHardcopyDetails("El tiempo entre costuras", "María Dueñas", "9788499984922", {1, 3, 2009}, "Chapter 2");
    
    // Hardcopy
    library[3] = new Hardcopy;
    ((Hardcopy*)library[3])->setHardcopyDetails("Patria", "Fernando Aramburu", "9788483103211", {20, 4, 2016}, "Chapter 3");

    // Ebook
    library[4] = new Ebook;
    ((Ebook*)library[4])->setEbookDetails("Los renglones torcidos de Dios", "Torcuato Luca de Tena", "9788408000497", {5, 5, 1979}, "5/5/1979");

    int choice;
    string userIsbn;
    int index;

    while (true) {
        cout << "\n--- LIBRARY SYSTEM MENU ---\\n";
        cout << "1. List all books and their details\\n";
        cout << "2. Borrow a book by ISBN\\n";
        cout << "3. Return a book by ISBN\\n";
        cout << "0. Exit program\\n";
        cout << "Select an option: ";
        
        cin >> choice;

        if (cin.fail()) {
            cout << "Invalid input. Try again.\\n";
            clearInputBuffer();
            continue;
        }

        if (choice == 0) {
            cout << "Program terminated. Goodbye!\\n";
            break; 
        }

        if (choice == 1) {
            cout << "\n--- COMPLETE LISTING ---\\n";
            for (int i = 0; i < NUM_BOOKS; ++i) {
                // Polimorfismo: llama al displayBookDetails() correcto (Book, Hardcopy o Ebook)
                library[i]->displayBookDetails();
            }
            continue;
        }

        if (choice == 2 || choice == 3) {
            cout << "Enter the book ISBN (or '0' to exit): ";
            cin >> userIsbn;
            
            if (userIsbn == "0") {
                 cout << "Program terminated. Goodbye!\\n";
                 choice = 0;
                 break;
            }
            
            index = findBook(library, NUM_BOOKS, userIsbn);
            
            if (index != -1) {
                if (choice == 2) {
                    library[index]->borrowBook(); 
                } else {
                    library[index]->returnBook(); 
                }
            } else {
                cout << "ERROR: Book with ISBN " << userIsbn << " not found in the library.\\n";
            }
        } else {
            cout << "Invalid menu option. Try again.\\n";
            clearInputBuffer();
        }
    }
    
    for (int i = 0; i < NUM_BOOKS; ++i) {
        delete library[i];
    }

    return 0;
}