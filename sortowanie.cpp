#include <iostream>
using namespace std;

/////////////////////// Algorytm sortowania bąbelkowego
void sortowanieBabelkowe(int tab[], int rozmiar) {
    for (int i = 0; i < rozmiar - 1; ++i) {
        for (int j = 0; j < rozmiar - i - 1; ++j) {
            if (tab[j] > tab[j + 1]) {
                // Zamień miejscami elementy, jeżeli są w złej kolejności
                swap(tab[j], tab[j + 1]);
            }
        }
    }
}

/////////////////////// Algorytm sortowania koktajlowy
void sortowanieKoktajlowe(int tab[], int rozmiar) {
    bool zamienione = true;
    int poczatek = 0;
    int koniec = rozmiar - 1;

    while (zamienione) {
        zamienione = false;

        // Przechodzenie od lewej do prawej strony
        for (int i = poczatek; i < koniec; ++i) {
            if (tab[i] > tab[i + 1]) {
                swap(tab[i], tab[i + 1]);
                zamienione = true;
            }
        }

        // Jeżeli nie było zamiany, to zakończ pętlę
        if (!zamienione) {
            break;
        }

        // Zmniejsz zakres o 1, bo ostatni element jest już na swoim miejscu
        --koniec;

        // Przechodzenie od prawej do lewej strony
        for (int i = koniec - 1; i >= poczatek; --i) {
            if (tab[i] > tab[i + 1]) {
                swap(tab[i], tab[i + 1]);
                zamienione = true;
            }
        }

        // Zwiększ zakres o 1, bo pierwszy element jest już na swoim miejscu
        ++poczatek;
    }
}

/////////////////////// Algorytm sortowania przez scalanie
void scalanie(int tab[], int lewy, int srodek, int prawy) {
    int a = srodek - lewy + 1;
    int b = prawy - srodek;

    int *lewaTablica = new int[a];
    int *prawaTablica = new int[b];

    // Skopiuj dane do tymczasowych tablic
    for (int i = 0; i < a; ++i) {
        lewaTablica[i] = tab[lewy + i];
    }
    for (int j = 0; j < b; ++j) {
        prawaTablica[j] = tab[srodek + 1 + j];
    }

    // Scalanie dwóch tymczasowych tablic w jedną posortowaną
    int i = 0;
    int j = 0;
    int k = lewy;
    while (i < a && j < b) {
        if (lewaTablica[i] <= prawaTablica[j]) {
            tab[k] = lewaTablica[i];
            ++i;
        } else {
            tab[k] = prawaTablica[j];
            ++j;
        }
        ++k;
    }

    // Skopiuj pozostałe elementy z lewej tablicy (jeżeli są)
    while (i < a) {
        tab[k] = lewaTablica[i];
        ++i;
        ++k;
    }

    // Skopiuj pozostałe elementy z prawej tablicy (jeżeli są)
    while (j < b ) {
        tab[k] = prawaTablica[j];
        ++j;
        ++k;
    }

    delete[] lewaTablica;
    delete[] prawaTablica;
}

void sortowaniePrzezScalanie(int tab[], int lewy, int prawy) {
    if (lewy < prawy) {
        int srodek = lewy + (prawy - lewy) / 2;

        // Sortuj lewą i prawą część
        sortowaniePrzezScalanie(tab, lewy, srodek);
        sortowaniePrzezScalanie(tab, srodek + 1, prawy);

        // Scal posortowane części
        scalanie(tab, lewy, srodek, prawy);
    }
}

/////////////////////// Algorytm sortowania szybkiego
int szybkie(int tab[], int niski, int wysoki) {
    int pivot = tab[wysoki];  // Wybierz ostatni element jako pivot
    int i = niski - 1;        // Indeks mniejszego elementu

    for (int j = niski; j <= wysoki - 1; ++j) {
        if (tab[j] < pivot) {
            ++i;
            swap(tab[i], tab[j]);
        }
    }

    swap(tab[i + 1], tab[wysoki]);
    return i + 1;
}

void sortowanieSzybkie(int tab[], int niski, int wysoki) {
    if (niski < wysoki) {
        // Znajdź indeks podziału
        int pi = szybkie(tab, niski, wysoki);

        // Sortuj osobno elementy przed i po podziale
        sortowanieSzybkie(tab, niski, pi - 1);
        sortowanieSzybkie(tab, pi + 1, wysoki);
    }
}

// Algorytm sortowania przez  Wstawianie
void sortowaniePrzezWstawianie(int tab[], int rozmiar) {
    for (int i = 1; i < rozmiar; ++i) {
        int klucz = tab[i];
        int j = i - 1;

        // Przesuwanie elementów większych niż klucz
        // do jednego miejsca w prawo
        while (j >= 0 && tab[j] > klucz) {
            tab[j + 1] = tab[j];
            --j;
        }

        tab[j + 1] = klucz;
    }
}

int main() {
    // Przykładowe użycie sortowania bąbelkowego
    int tabBabelkowe[] = {64, 34, 25, 12, 22, 11, 90};
    int rozmiarBabelkowe = sizeof(tabBabelkowe) / sizeof(tabBabelkowe[0]);
    sortowanieBabelkowe(tabBabelkowe, rozmiarBabelkowe);

    cout << "Sortowanie bąbelkowe:\n";
    for (int i = 0; i < rozmiarBabelkowe; ++i) {
        cout << tabBabelkowe[i] << " ";
    }
    cout << "\n\n";

    // Przykładowe użycie sortowania koktajlowego
        int tabKoktajlowego[] = {64, 34, 25, 12, 22, 11, 90};
    int rozmiarKoktajlowego = sizeof(tabKoktajlowego) / sizeof(tabKoktajlowego[0]);
    sortowanieKoktajlowe(tabKoktajlowego, rozmiarKoktajlowego);

    cout << "Sortowanie koktajlowe:\n";
    for (int i = 0; i < rozmiarKoktajlowego; ++i) {
        cout << tabKoktajlowego[i] << " ";
    }
    cout << "\n\n";

    // Przykładowe użycie sortowania przez scalanie
    int tabScalanie[] = {64, 34, 25, 12, 22, 11, 90};
    int rozmiarScalanie = sizeof(tabScalanie) / sizeof(tabScalanie[0]);
    sortowaniePrzezScalanie(tabScalanie, 0, rozmiarScalanie - 1);

    cout << "Sortowanie przez scalanie:\n";
    for (int i = 0; i < rozmiarScalanie; ++i) {
        cout << tabScalanie[i] << " ";
    }
    cout << "\n\n";

    // Przykładowe użycie sortowania szybkiego
    int tabSzybkie[] = {64, 34, 25, 12, 22, 11, 90};
    int rozmiarSzybkie = sizeof(tabSzybkie) / sizeof(tabSzybkie[0]);
    sortowanieSzybkie(tabSzybkie, 0, rozmiarSzybkie - 1);

    cout << "Sortowanie szybkie:\n";
    for (int i = 0; i < rozmiarSzybkie; ++i) {
        cout << tabSzybkie[i] << " ";
    }
    cout << "\n\n";
 
    // Przykładowe użycie sortowania przez wstawianie
    int tabWstawianie[] = {64, 34, 25, 12, 22, 11, 90};
    int rozmiarWstawianie = sizeof(tabWstawianie) / sizeof(tabWstawianie[0]);
    sortowaniePrzezWstawianie(tabWstawianie, rozmiarWstawianie);

    cout << "Sortowanie przez wstawianie:\n";
    for (int i = 0; i < rozmiarWstawianie; ++i) {
        cout << tabWstawianie[i] << " ";
    }
    cout << "\n\n";
 
    return 0;
}
