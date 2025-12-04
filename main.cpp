#include "book.h"
#include "sorting.h"
#include <vector>
#include <algorithm> 
#include <string>

void printLibrary(const std::vector<Book*>& library, const std::string& title) {
    std::cout << "\n================================================\n";
    std::cout << title << std::endl;
    std::cout << "================================================\n";
    
    for (const auto& book : library) {
        book->displayBookDetails(); 
        std::cout << "------------------------------------------\n";
    }
}

int main() {
    
    std::cout << "Inicializando Sistema de Biblioteca...\n";
    
    std::vector<Book*> library;

    library.push_back(new Hardcopy("Don Quijote", "Miguel de Cervantes", "978-8424911475", "A-301"));
    library.push_back(new Ebook("Clean Code", "Robert C. Martin", "978-0132350884", "2026-12-31"));
    library.push_back(new Hardcopy("The Great Gatsby", "F. Scott Fitzgerald", "978-0743273565", "B-105"));
    library.push_back(new Ebook("C++ Primer", "Stanley B. Lippman", "978-0321714114", "2027-01-01"));

    printLibrary(library, "Inventario Inicial (Desordenado)");

    std::cout << "\n*** Iniciando Ordenamiento por TITULO ***\n";
    QuickSort(library, 0, library.size() - 1, TITLE);
    printLibrary(library, "Inventario Ordenado por TITULO");

    std::cout << "\n*** Iniciando Ordenamiento por ISBN ***\n";
    QuickSort(library, 0, library.size() - 1, ISBN);
    printLibrary(library, "Inventario Ordenado por ISBN");
    
    // Limpieza de Memoria (Obligatorio en C++ con new)
    for (Book* book : library) {
        delete book; 
    }
    library.clear();
    
    // Documentacion Técnica (Estilo Oscar - Rigor)
    std::cout << "\n\n*** Documentacion Tecnica del Algoritmo ***\n";
    std::cout << "Algoritmo Implementado: Quick Sort\n";
    std::cout << " - Complejidad Promedio: O(n log n)\n";
    std::cout << " - Complejidad Peor Caso: O(n^2)\n";
    std::cout << " - Memoria Auxiliar: O(log n)\n";
    std::cout << " - Estabilidad: No Estable\n";
    
    return 0;
}