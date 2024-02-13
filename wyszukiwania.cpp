#include <iostream>
#include <cmath>
using namespace std;

// Algorytm wyszukiwania liniowego
int wyszukiwanieLiniowe(int tab[], int rozmiar, int szukana) {
    for (int i = 0; i < rozmiar; ++i) {
        if (tab[i] == szukana) {
            return i; // Zwraca indeks, jeżeli element został znaleziony
        }
    }
    return -1; // Zwraca -1, jeżeli element nie został znaleziony
}

// Algorytm wyszukiwania liniowego z wartownikiem
int wyszukiwanieLinioweWartownik(int tab[], int rozmiar, int szukana) {
    int ostatniElement = tab[rozmiar - 1]; // Zapamiętaj ostatni element
    tab[rozmiar - 1] = szukana; // Ustaw szukaną wartość na ostatnim miejscu

    int i = 0;
    while (tab[i] != szukana) {
        ++i;
    }

    tab[rozmiar - 1] = ostatniElement; // Przywróć oryginalną wartość na ostatnim miejscu

    if (i < rozmiar - 1 || tab[rozmiar - 1] == szukana) {
        return i; // Zwraca indeks, jeżeli element został znaleziony
    } else {
        return -1; // Zwraca -1, jeżeli element nie został znaleziony
    }
}

// Algorytm wyszukiwania skokowego
int wyszukiwanieSkokowe(int tab[], int rozmiar, int szukana) {
    int skok = sqrt(rozmiar);
    int aktualnyIndeks = 0;

    while (tab[min(skok, rozmiar) - 1] < szukana) {
        aktualnyIndeks = skok;
        skok += sqrt(rozmiar);
        if (aktualnyIndeks >= rozmiar) {
            return -1; // Zwraca -1, jeżeli element nie został znaleziony
        }
    }

    for (int i = aktualnyIndeks; i < min(skok, rozmiar); ++i) {
        if (tab[i] == szukana) {
            return i; // Zwraca indeks, jeżeli element został znaleziony
        }
    }

    return -1; // Zwraca -1, jeżeli element nie został znaleziony
}

// Algorytm wyszukiwania binarnego (dla posortowanej tablicy)
int wyszukiwanieBinarne(int tab[], int lewy, int prawy, int szukana) {
    while (lewy <= prawy) {
        int srodek = lewy + (prawy - lewy) / 2;

        if (tab[srodek] == szukana) {
            return srodek; // Zwraca indeks, jeżeli element został znaleziony
        }

        if (tab[srodek] < szukana) {
            lewy = srodek + 1;
        } else {
            prawy = srodek - 1;
        }
    }

    return -1; // Zwraca -1, jeżeli element nie został znaleziony
}

int main() {
    // Przykładowe użycie algorytmów wyszukiwania
        int tab[] = {10, 20, 30, 40, 50, 60, 70};
    int rozmiar = sizeof(tab) / sizeof(tab[0]);

    int szukana1 = 40;
    int indeks1 = wyszukiwanieLiniowe(tab, rozmiar, szukana1);
    cout << "Wyszukiwanie liniowe: " << indeks1 << endl;

    int szukana2 = 50;
    int indeks2 = wyszukiwanieLinioweWartownik(tab, rozmiar, szukana2);
    cout << "Wyszukiwanie liniowe z wartownikiem: " << indeks2 << endl;

    int szukana3 = 60;
    int indeks3 = wyszukiwanieSkokowe(tab, rozmiar, szukana3);
    cout << "Wyszukiwanie skokowe: " << indeks3 << endl;

    int szukana4 = 20;
    int indeks4 = wyszukiwanieBinarne(tab, 0, rozmiar - 1, szukana4);
    cout << "Wyszukiwanie binarne: " << indeks4 << endl;

    return 0;
}
