/**
 * @file Main.cpp
 * @brief Menu drzewa BST oraz zapisu i odczytu plików.
 */

#include "DrzewoBST.h"
#include "ObslugaPlikow.h"
#include <iostream>
#include <string>
#include <vector>

using namespace std;

/**
 * @brief  Wykonuje operacje wybrane przez użytkownika i wyświetla menu.
 * @return 0 po zakończeniu programu.
 */
int main() {
    DrzewoBST drzewo;
    ObslugaPlikow pliki;

    int wybor;
    int wartosc;
    int metoda;
    int tryb;

    string nazwaPliku;
    vector<int> droga;

    do {
        cout << "\n=== Drzewo BST ===\n";
        cout << "1. Dodaj liczbe\n";
        cout << "2. Usun liczbe\n";
        cout << "3. Wyczysc drzewo\n";
        cout << "4. Znajdz droge do liczby\n";
        cout << "5. Wyswietl drzewo\n";
        cout << "6. Zapisz rysunek drzewa do pliku tekstowego\n";
        cout << "7. Zapisz drzewo binarnie\n";
        cout << "8. Wczytaj drzewo binarnie\n";
        cout << "9. Wczytaj liczby z pliku tekstowego\n";
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

            case 6:
                cout << "Nazwa pliku tekstowego (bez spacji): ";
                cin >> nazwaPliku;
                if (!cin) return 0;

                cout << "1 - preorder, 2 - inorder, 3 - postorder\n";
                cout << "Metoda: ";
                cin >> metoda;
                if (!cin) return 0;

                drzewo.zapiszTekstowo(nazwaPliku, metoda);
                break;

            case 7:
                cout << "Nazwa pliku binarnego (bez spacji): ";
                cin >> nazwaPliku;
                if (!cin) return 0;

                if (pliki.zapiszBinarnie(drzewo, nazwaPliku)) {
                    cout << "Zapisano drzewo binarnie\n";
                }
                break;

            case 8:
                cout << "Nazwa pliku binarnego (brak spacji): ";
                cin >> nazwaPliku;
                if (!cin) return 0;

                cout << "0 - zastap drzewo, 1 - dolacz dane: ";
                cin >> tryb;
                if (!cin) return 0;

                if (tryb == 0 || tryb == 1) {
                    if (pliki.wczytajBinarnie(
                        drzewo, nazwaPliku, tryb == 1
                    )) {
                        cout << "Wczytano drzewo binarnie\n";
                    }
                } else {
                    cout << "Nieprawidlowy tryb\n";
                }
                break;

            case 9:
                cout << "Nazwa pliku z liczbami (bez spacji): ";
                cin >> nazwaPliku;
                if (!cin) return 0;

                cout << "0 - zastap drzewo, 1 - dolacz dane: ";
                cin >> tryb;
                if (!cin) return 0;

                if (tryb == 0 || tryb == 1) {
                    if (pliki.wczytajTekstowo(
                        drzewo, nazwaPliku, tryb == 1
                    )) {
                        cout << "Wczytano liczby z pliku\n";
                    }
                } else {
                    cout << "Nieprawidlowy tryb\n";
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