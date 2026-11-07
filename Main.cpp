/**
 * @file Main.cpp
 * @brief Menu podstawowych operacji drzewa BST.
 */

#include "DrzewoBST.h"
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Wyświetla menu i wykonuje operacje wybrane przez użytkownika.
 * @return 0 po zakończeniu programu.
 */
int main() {
    DrzewoBST drzewo;
    int wybor;
    int wartosc;
    int metoda;
    vector<int> droga;

    do {
        cout << "\n=== Drzewo BST ===\n";
        cout << "1. Dodaj liczbe\n";
        cout << "2. Usun liczbe\n";
        cout << "3. Wyczysc drzewo\n";
        cout << "4. Znajdz droge do liczby\n";
        cout << "5. Wyswietl drzewo\n";
        cout << "0. Wyjscie\n";
        cout << "Wybor: ";
        cin >> wybor;

        if (!cin) {
            cout << "Niepoprawne dane\n";
            return 0;
        }

        switch (wybor) {
            case 1:
                cout << "Liczba do dodania: ";
                cin >> wartosc;
                if (!cin) return 0;

                if (drzewo.dodaj(wartosc)) {
                    cout << "Dodano liczbe\n";
                } else {
                    cout << "Ta liczba juz istnieje\n";
                }
                break;

            case 2:
                cout << "Liczba do usuniecia: ";
                cin >> wartosc;
                if (!cin) return 0;

                if (drzewo.usun(wartosc)) {
                    cout << "Usunieto liczbe\n";
                } else {
                    cout << "Nie znaleziono liczby\n";
                }
                break;

            case 3:
                drzewo.wyczysc();
                cout << "Wyczyszczono drzewo\n";
                break;

            case 4:
                cout << "Szukana liczba: ";
                cin >> wartosc;
                if (!cin) return 0;

                droga = drzewo.drogaDo(wartosc);

                if (droga.empty()) {
                    cout << "Nie znaleziono liczby\n";
                } else {
                    int dlugosc = droga.size();

                    for (int i = 0; i < dlugosc; i++) {
                        if (i > 0) cout << " -> ";
                        cout << droga[i];
                    }

                    cout << '\n';
                }
                break;

            case 5:
                cout << "1 - preorder, 2 - inorder, 3 - postorder\n";
                cout << "Metoda: ";
                cin >> metoda;
                if (!cin) return 0;

                if (metoda >= 1 && metoda <= 3) {
                    drzewo.wyswietl(metoda);
                } else {
                    cout << "Nieprawidlowa metoda\n";
                }
                break;

            case 0:
                cout << "Koniec programu\n";
                break;

            default:
                cout << "Nie ma takiej opcji\n";
                break;
        }

    } while (wybor != 0);

    return 0;
}