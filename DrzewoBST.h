/**
* @file DrzewoBST.h
 * @brief Deklaracja klasy drzewa BST.
 */

#ifndef DRZEWO_BST_H
#define DRZEWO_BST_H

#include<vector>
#include<string>
#include<iostream>
/**
 * @brief Binarne drzewo poszukiwań liczb całkowitych.
 * Węzły są przechowywane w kontenerze vector.
 * Dzieci węzła wskazujemy przez indeksy.
 * Indeks -1 oznacza brak węzła.
 */
class DrzewoBST {
private:
    /** @brief Dane pojedyńczego węzła drzewa. */
    struct Wezel {
        int wartosc = 0;
        int lewy = -1;
        int prawy = -1;
    };

    /** @brief Kontener przechowujący węzły drzewa. */
    std::vector<Wezel> wezly;

    /** @brief Indeks korzenia; -1 oznacza puste drzewo. */
    int korzen = -1;
    /**@brief metoda służy do wypisywania rekurencyjnego. */
    void wypiszRekurencyjnie(int aktualny, std::ostream& wyjscie, int metoda, int poziom, char strona) const;

    /**
     * @brief Zbiera wartości z kolejnych węzłów drzewa.
     * @param aktualny Indeks odwiedzanego węzła.
     * @param wynik Wektor, do którego dopisujemy liczby.
     */
    void zbierzWartosci(int aktualny, std::vector<int>& wynik) const;
public:
    ///Konstruktor pusty klasy DrzewoBST.
    DrzewoBST();
    /**
     * @brief Dodaje liczbę do drzewa.
     * @param wartosc Liczba do dodania.
     * @return true, jeżeli dodano liczbę - false, jeśli już istnieje.
     */
    bool dodaj(int wartosc);

    /**
     * @brief Usuwa liczbę z drzewa.
     * @param wartosc Liczba do usunięcia.
     * @return true, jeżeli usunięto liczbę; false, jeśli jej nie znaleziono.
     */
    bool usun(int wartosc);

    /**
     * @brief Usuwa wszystkie elementy drzewa.
     */
    void wyczysc();

    /**
     * @brief Szuka drogi od korzenia do podanej liczby.
     * @param wartosc Szukana liczba.
     * @return Kolejne liczby na drodze lub pusty vector, jeśli brak liczby.
     */
    std::vector<int> drogaDo(int wartosc) const;

    /**
     * @brief Wyświetla drzewo na ekranie.
     * @param metoda 1 - preorder, 2 - inorder, 3 - postorder.
     */
    void wyswietl(int metoda) const;

    /**
     * @brief Zapisuje rysunek drzewa do pliku tekstowego.
     * @param nazwaPliku Nazwa pliku wynikowego.
     * @param metoda 1 - preorder, 2 - inorder, 3 - postorder.
     */
    void zapiszTekstowo(std::string nazwaPliku, int metoda) const;

    /**
     *@brief Wypisuje rysunek drzewa do wskazanego strumienia.
     *@param wyjscie Ekran lub otwarty plik tekstowy.
    * @param metoda 1 - preorder, 2 - inorder, 3 - postorder.
    */
    void wypiszDrzewo(std::ostream& wyjscie, int metoda)const;

    /**
     *@brief Służy do pobrania wartości drzewa
     *@return Wektor licz przygotowanych do zapisu.
     */
    std::vector<int>pobierzWartosci()const;
};
#endif