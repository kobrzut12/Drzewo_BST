/**
 * @file main.cpp
 * @brief Program testujący podstawowe operacje drzewa BST.
 */

#include "DrzewoBST.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Sprawdza działanie metod klasy DrzewoBST.
 * @return 0 po zakończeniu programu testowego.
 */
int main() {
    DrzewoBST drzewo;

    cout << " 1. Puste drzewo \n";
    drzewo.wyswietl(1);

    int liczby[] = {8, 3, 10, 1, 6, 14, 4, 7, 13};

    for (int i = 0; i < 9; i++) {
        drzewo.dodaj(liczby[i]);
    }

    cout << "\n 2. Preorder \n";
    drzewo.wyswietl(1);

    cout << "\n 3. Inorder \n";
    drzewo.wyswietl(2);

    cout << "\n 4. Postorder \n";
    drzewo.wyswietl(3);

    cout << "\n 5. Droga do liczby 7 \n";

    vector<int> droga = drzewo.drogaDo(7);
    int dlugosc = droga.size();

    for (int i = 0; i < dlugosc; i++) {
        if (i > 0) {
            cout << " -> ";
        }

        cout << droga[i];
    }

    cout << '\n';

    cout << "\n 6. Szukanie liczby 99 \n";

    droga = drzewo.drogaDo(99);

    if (droga.empty()) {
        cout << "OK: liczby 99 nie ma w drzewie\n";
    } else {
        cout << "BLAD: znaleziono liczbe 99\n";
    }

    cout << "\n 7. Ponowne dodanie liczby 6 \n";

    if (drzewo.dodaj(6)) {
        cout << "BLAD: dodano duplikat\n";
    } else {
        cout << "OK: duplikat zostal pominiety\n";
    }

    cout << "\n 8. Zapis drzewa do pliku \n";
    drzewo.zapiszTekstowo("drzewo_test.txt", 1);

    cout << "\n 9. Usuniecie liscia 1 \n";
    drzewo.usun(1);
    drzewo.wyswietl(1);

    cout << "\n 10. Usuniecie wezla 14 z jednym dzieckiem \n";
    drzewo.usun(14);
    drzewo.wyswietl(1);

    cout << "\n11. Usuniecie korzenia 8 z dwojgiem dzieci \n";
    drzewo.usun(8);
    drzewo.wyswietl(1);

    cout << "\n 12. Usuniecie nieistniejacej liczby 99 \n";

    if (drzewo.usun(99)) {
        cout << "BLAD: usunieto nieistniejaca liczbe\n";
    } else {
        cout << "OK: brak liczby do usuniecia\n";
    }

    cout << "\n13. Wyczyszczenie drzewa \n";
    drzewo.wyczysc();
    drzewo.wyswietl(1);

    cout << "\n 14. Dodawanie po wyczyszczeniu \n";
    drzewo.dodaj(5);
    drzewo.wyswietl(1);

    return 0;
}