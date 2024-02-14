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

int main() {
    // Przykladowe uzycie sortowania wyszukiwania
    int tablica[] = {10, 20, 30, 40, 50, 60, 70, 80, 90, 100, 110, 120};
    int rozmiar = sizeof(tablica) / sizeof(tablica[0]);

    // liniowe
    int klucz1 = 40;
    int indeks1 = liniowe(tablica, rozmiar, klucz1);
    cout << "Liniowe wyszukiwanie: " << indeks1 << endl;

    // Liniowe z wartownikem
    int klucz2 = 50;
    int indeks2 = wartownikiem(tablica, rozmiar, klucz2);
    cout << "Liniowe wyszukiwanie z wartownikiem: " << indeks2 << endl;

    // skokowe
    int klucz3 = 60;
    int indeks3 = skokowe(tablica, rozmiar, klucz3);
    cout << "Skokowe wyszukiwanie: " << indeks3 << endl;

    // binarne
    int klucz4 = 20;
    int indeks4 = binarne(tablica, rozmiar, klucz4);
    cout << "Binarne wyszukiwanie: " << indeks4 << endl;
    return 0;
}
