/**
 * @file ObslugaPlikow.cpp
 * @brief Zapis binarny oraz odczyt danych drzewa z plików.
 */

#include "ObslugaPlikow.h"
#include <fstream>
#include <iostream>
#include <vector>

using namespace std;

/**
 * @brief Zapisuje liczbę węzłów i ich wartości w kolejności preorder.
 * @param drzewo Drzewo do zapisania.
 * @param nazwaPliku Nazwa pliku wynikowego.
 * @return true po poprawnym zapisie; false przy błędzie.
 */
bool ObslugaPlikow::zapiszBinarnie(
    const DrzewoBST& drzewo,
    string nazwaPliku
) {
    vector<int> wartosci = drzewo.pobierzWartosci();
    int liczba = wartosci.size();

    ofstream plik(nazwaPliku, ios::binary);

    if (!plik) {
        cout << "Nie mozna otworzyc pliku do zapisu\n";
        return false;
    }

    plik.write((char*)&liczba, sizeof(liczba));

    for (int i = 0; i < liczba; i++) {
        int wartosc = wartosci[i];

        plik.write((char*)&wartosc, sizeof(wartosc));
    }

    plik.close();

    if (!plik) {
        cout << "Blad zapisu pliku binarnego\n";
        return false;
    }

    return true;
}

/**
 * @brief Wczytuje drzewo z pliku binarnego.
 * @param drzewo To drzewo docelowe.
 * @param nazwaPliku Nazwa pliku wejściowego.
 * @param dolacz true - dołącz dane; false - zastąp obecne drzewo.
 * @return true po poprawnym odczycie; false przy błędzie.
 */
bool ObslugaPlikow::wczytajBinarnie(
    DrzewoBST& drzewo,
    string nazwaPliku,
    bool dolacz
) {
    ifstream plik(nazwaPliku, ios::binary);

    if (!plik) {
        cout << "Nie otworzyc pliku do odczytu\n";
        return false;
    }

    int liczba;

    plik.read((char*)&liczba, sizeof(liczba));

    if (!plik || liczba < 0) {
        cout << "Nieprawidlowy naglowek pliku binarnego\n";
        return false;
    }

    DrzewoBST wynik;

    if (dolacz) {
        wynik = drzewo;
    }

    for (int i = 0; i < liczba; i++) {
        int wartosc;

        plik.read((char*)&wartosc, sizeof(wartosc));

        if (!plik) {
            cout << "Brakuje danych w pliku binarnym\n";
            return false;
        }

        wynik.dodaj(wartosc);
    }

    char dodatkowy;

    if (plik.get(dodatkowy)) {
        cout << "Plik binarny zawiera nadmiarowe dane\n";
        return false;
    }

    if (!plik.eof()) {
        cout << "Blad odczytu pliku binarnego\n";
        return false;
    }

    plik.close();

    drzewo = wynik;

    return true;
}

/**
 * @brief Wczytuje liczby całkowite z pliku tekstowego.
 * @param drzewo Drzewo docelowe.
 * @param nazwaPliku Nazwa pliku zawierającego liczby.
 * @param dolacz true - dołącz dane; false - zastąp obecne drzewo.
 * @return true po poprawnym odczycie; false przy błędzie.
 */
bool ObslugaPlikow::wczytajTekstowo(
    DrzewoBST& drzewo,
    string nazwaPliku,
    bool dolacz
) {
    ifstream plik(nazwaPliku);

    if (!plik) {
        cout << "Nie mozna otworzyc pliku tekstowego\n";
        return false;
    }

    DrzewoBST wynik;

    if (dolacz) {
        wynik = drzewo;
    }

    while (true) {
        plik >> ws;

        if (plik.eof()) {
            break;
        }

        int wartosc;
        plik >> wartosc;

        if (!plik) {
            cout << "Plik zawiera niepoprawna liczbe calkowita\n";
            return false;
        }

        wynik.dodaj(wartosc);
    }

    if (plik.bad()) {
        cout << "Blad odczytu pliku tekstowego\n";
        return false;
    }

    plik.close();

    drzewo = wynik;

    return true;
}