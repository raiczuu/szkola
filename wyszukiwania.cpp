#include <iostream>
#include <cmath>
using namespace std;

/////////////////  Algorytm wyszukiwania liniowego
int liniowe(int *t, int size, int key) {
    for (int i = 0; i < size; ++i) {
        if (t[i] == key) {
            return i; // zwraca indeks, jezeli element byl znaleziony
        }
    }
    return -1; // Zwraca -1, jezeli nie byl
}

///////////////// Algorytm wyszukiwania liniowego z wartownikiem
int wartownikiem(int *t, int size, int key) {
    t[size] = key; // ustawia wartownik na koniec tablicy
    int i = 0;
    while (t[i] != key) {
        ++i;
    }

    if (i < size) {
        return i; // zwraca indeks, jezeli element byl znaleziony
    } else {
        return -1; // Zwraca -1, jezeli nie byl
    }
}

///////////////// Algorytm wyszukiwania skokowego


///////////////// Algorytm wyszukiwania binarnego
int binarne(int *t, int size, int key) {
    int lewy = 0;
    int prawy = size - 1;

    while (lewy <= prawy) {
        int srodek = lewy + (prawy - lewy) / 2;

        if (t[srodek] == key) {
            return srodek; // zwraca indeks, jezeli element byl znaleziony
        }

        if (t[srodek] < key) {
            lewy = srodek + 1;
        } else {
            prawy = srodek - 1;
        }
    }

    return -1; // Zwraca -1, jezeli nie byl
}
