/**
* @file DrzewoBST.cpp
 * @brief Implementacja metod drzewa BST.
 */

#include "DrzewoBST.h"


/// Dodaje liczbe do drzewa BST.
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

///Usuwa liczbe z drzewa.
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

