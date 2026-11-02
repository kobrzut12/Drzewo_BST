/**
* @file ObslugaPlikow.h
 * @brief Deklaracja klasy obsługującej pliki z danymi drzewa.
 */

#ifndef OBSLUGA_PLIKOW_H
#define OBSLUGA_PLIKOW_H

#include <string>
#include "DrzewoBST.h"

using namespace std;

/**
 * @brief Zapisuje i odczytuje dane drzewa BST.
 */
class ObslugaPlikow {
public:
    /**
     * @brief Zapisuje drzewo do pliku binarnego.
     * @param drzewo Drzewo do zapisania.
     * @param nazwaPliku Nazwa pliku wynikowego.
     * @return true po poprawnym zapisie; false przy błędzie.
     */
    bool zapiszBinarnie(
        const DrzewoBST& drzewo,
        string nazwaPliku
    );

    /**
     * @brief Wczytuje drzewo z pliku binarnego.
     * @param drzewo Drzewo, do którego wczytujemy dane.
     * @param nazwaPliku Nazwa pliku wejściowego.
     * @param dolacz true - dołącz; false - zastąp obecne drzewo.
     * @return true po poprawnym odczycie; false przy błędzie.
     */
    bool wczytajBinarnie(
        DrzewoBST& drzewo,
        string nazwaPliku,
        bool dolacz
    );

    /**
     * @brief Wczytuje liczby całkowite z pliku tekstowego.
     * @param drzewo Drzewo, do którego dodajemy liczby.
     * @param nazwaPliku Nazwa pliku zawierającego liczby.
     * @param dolacz true - dołącz; false - zastąp obecne drzewo.
     * @return true po poprawnym odczycie; false przy błędzie.
     */
    bool wczytajTekstowo(
        DrzewoBST& drzewo,
        string nazwaPliku,
        bool dolacz
    );
};

#endif