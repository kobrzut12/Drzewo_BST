/**
* @file DrzewoBST.cpp
 * @brief Implementacja metod drzewa BST.
 */

#include "DrzewoBST.h"
#include<vector>
#include<iostream>
#include<string>
#include<fstream>
using namespace std;
///Konstruktor pusty
DrzewoBST::DrzewoBST() {}

/// Dodaje liczbę do drzewa BST.
bool DrzewoBST::dodaj(int wartosc) {
 int aktualny = korzen;
 int rodzic = -1;

 while (aktualny != -1) {
  if (wartosc == wezly[aktualny].wartosc) {
   return false;
  }

  rodzic = aktualny;

  if (wartosc < wezly[aktualny].wartosc) {
   aktualny = wezly[aktualny].lewy;
  } else {
   aktualny = wezly[aktualny].prawy;
  }
 }

 Wezel nowy;
 nowy.wartosc = wartosc;
 wezly.push_back(nowy);

 int indeksNowego = wezly.size() - 1;

 if (rodzic == -1) {
  korzen = indeksNowego;
 } else if (wartosc < wezly[rodzic].wartosc) {
  wezly[rodzic].lewy = indeksNowego;
 } else {
  wezly[rodzic].prawy = indeksNowego;
 }

 return true;
}

///Usuwa liczbę z drzewa.
bool DrzewoBST::usun(int wartosc) {
 int aktualny = korzen;
 int rodzic = -1;
 while (aktualny != -1 && wezly[aktualny].wartosc != wartosc) {
  rodzic = aktualny;
  if (wartosc < wezly[aktualny].wartosc) {
   aktualny = wezly[aktualny].lewy;
  } else {
   aktualny = wezly[aktualny].prawy;
  }
 }
 if (aktualny == -1) {
  return false;
 }
if (wezly[aktualny].lewy!=-1 && wezly[aktualny].prawy!=-1) {
 int nastepnik=wezly[aktualny].prawy;
 int rodzicNastepnika=aktualny;

 while (wezly[nastepnik].lewy!=-1) {
  rodzicNastepnika=nastepnik;
  nastepnik=wezly[nastepnik].lewy;
 }
 wezly[aktualny].wartosc=wezly[nastepnik].wartosc;
 aktualny=nastepnik;
 rodzic=rodzicNastepnika;
}

 int dziecko = wezly[aktualny].lewy;

 if (dziecko == -1) {
  dziecko = wezly[aktualny].prawy;
 }

 if (rodzic == -1) {
  korzen = dziecko;
 } else if (wezly[rodzic].lewy == aktualny) {
  wezly[rodzic].lewy = dziecko;
 } else {
  wezly[rodzic].prawy = dziecko;
 }

 wezly.erase(wezly.begin() + aktualny);

 if (korzen > aktualny) {
  korzen--;
 }

 int liczbaWezlow = wezly.size();

 for (int i = 0; i < liczbaWezlow; i++) {
  if (wezly[i].lewy > aktualny) {
   wezly[i].lewy--;
  }

  if (wezly[i].prawy > aktualny) {
   wezly[i].prawy--;
  }
 }

 return true;
}


/// Usuwa wszystkie węzły drzewa.
void DrzewoBST::wyczysc() {
 wezly.clear();
 korzen=-1;
}


 /// Metoda szuka drogi od korzenia do podanej liczby.
vector<int> DrzewoBST::drogaDo(int wartosc) const {
 vector<int>droga;
 int aktualny=korzen;

 while (aktualny!=-1) {
  droga.push_back(wezly[aktualny].wartosc);
  if (wartosc==wezly[aktualny].wartosc) {
   return droga;
  }
  if (wartosc<wezly[aktualny].wartosc) {
   aktualny=wezly[aktualny].lewy;
  }
  else {
   aktualny=wezly[aktualny].prawy;
  }
 }
 droga.clear();
 return droga;
}


void DrzewoBST::wypiszDrzewo(ostream& wyjscie, int metoda) const {
 if (metoda < 1 || metoda > 3) return;
 if (korzen == -1) {
  wyjscie << "puste drzewo\n";
  return;
 }

 if (metoda == 1) wyjscie << "Preorder\n";
 if (metoda == 2) wyjscie << "Inorder\n";
 if (metoda == 3) wyjscie << "Postorder\n";
 wyjscie << "K - korzen, L - lewe dziecko, P - prawe dziecko\n";

 wypiszRekurencyjnie(korzen, wyjscie, metoda, 0, 'K');
}
///Metoda do wypisywania rekurencyjnie węzłów drzewa.
void DrzewoBST::wypiszRekurencyjnie(int aktualny, ostream& wyjscie, int metoda, int poziom, char strona) const {
 if (aktualny == -1) {
  return;
 }

 if (metoda == 1) {
  for (int i = 0; i < poziom; i++) wyjscie << "    ";
  wyjscie << '[' << strona << "] " << wezly[aktualny].wartosc << '\n';
 }

 wypiszRekurencyjnie(wezly[aktualny].lewy, wyjscie, metoda, poziom + 1, 'L');

 if (metoda == 2) {
  for (int i = 0; i < poziom; i++) wyjscie << "    ";
  wyjscie << '[' << strona << "] " << wezly[aktualny].wartosc << '\n';
 }

 wypiszRekurencyjnie(wezly[aktualny].prawy, wyjscie, metoda, poziom + 1, 'P');

 if (metoda == 3) {
  for (int i = 0; i < poziom; i++) wyjscie << "    ";
  wyjscie << '[' << strona << "] " << wezly[aktualny].wartosc << '\n';
 }
}

///Metoda wyświetla drzewo w terminalu.
void DrzewoBST::wyswietl(int metoda) const {
 wypiszDrzewo(cout,metoda);
}

///Metoda zapisuje tekstowo drzewo w pliku.
void DrzewoBST::zapiszTekstowo(string nazwaPliku, int metoda) const {
 if (metoda<1 || metoda>3) {
  cout<<"Nieprawidlowa metoda\n";
  return;
 }
 ofstream plik(nazwaPliku);
 if (!plik) {
  cout<<"Nie mozna otworzyc pliku do zapisu\n";
  return;
 }
 wypiszDrzewo(plik,metoda);
 plik.close();
 if (!plik) {
  cout<<"Blad zapisu do pliku\n";
  return;
 }else{
  cout<<"Zapisano drzewo do pliku\n";
 return;
}
}
///Służy do tworzenia  wektora wynikowego.
vector<int> DrzewoBST::pobierzWartosci() const {
 vector<int> wynik;
 zbierzWartosci(korzen, wynik);
 return wynik;
}

///Służy do zbierania wartośći drzewa.
void DrzewoBST::zbierzWartosci(int aktualny,vector<int>& wynik) const {
 if (aktualny == -1) {
  return;
 }

 wynik.push_back(wezly[aktualny].wartosc);

 zbierzWartosci(wezly[aktualny].lewy, wynik);
 zbierzWartosci(wezly[aktualny].prawy, wynik);
}



