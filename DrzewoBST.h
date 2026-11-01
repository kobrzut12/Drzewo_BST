/**
* @file DrzewoBST.h
 * @brief Deklaracja klasy drzewa BST.
 */

#ifndef DRZEWO_BST_H
#define DRZEWO_BST_H

#include <vector>
#include <string>

/**
 * @brief Binarne drzewo poszukiwan liczb calkowitych.
 *
 * Wezly sa przechowywane w kontenerze vector.
 * Dzieci wezla wskazujemy przez indeksy.
 * Indeks -1 oznacza brak wezla.
 */
class DrzewoBST {
private:
    /** @brief Dane pojedynczego wezla drzewa. */
    struct Wezel {
        int wartosc = 0;
        int lewy = -1;
        int prawy = -1;
    };

    /** @brief Kontener przechowujacy wezly drzewa. */
    vector<Wezel> wezly;

    /** @brief Indeks korzenia; -1 oznacza puste drzewo. */
    int korzen = -1;

    public:
    ///Konstruktor pusty klasy DrzewoBST.
    DrzewoBST();
    /**
     * @brief Dodaje liczbe do drzewa.
     * @param wartosc Liczba do dodania.
     * @return true, jezeli dodano liczbe - false, jesli juz istnieje.
     */
    bool dodaj(int wartosc);

    /**
     * @brief Usuwa liczbe z drzewa.
     * @param wartosc Liczba do usuniecia.
     * @return true, jezeli usunieto liczbe; false, jesli jej nie znaleziono.
     */
    bool usun(int wartosc);

    /**
     * @brief Usuwa wszystkie elementy drzewa.
     */
    void wyczysc();

    /**
     * @brief Szuka drogi od korzenia do podanej liczby.
     * @param wartosc Szukana liczba.
     * @return Kolejne liczby na drodze lub pusty vector, jesli brak liczby.
     */
    vector<int> drogaDo(int wartosc) const;

    /**
     * @brief Wyswietla drzewo na ekranie.
     * @param metoda 1 - preorder, 2 - inorder, 3 - postorder.
     */
    void wyswietl(int metoda) const;

    /**
     * @brief Zapisuje rysunek drzewa do pliku tekstowego.
     * @param nazwaPliku Nazwa pliku wynikowego.
     * @param metoda 1 - preorder, 2 - inorder, 3 - postorder.
     */
    void zapiszTekstowo(string nazwaPliku, int metoda) const;


};

#endif