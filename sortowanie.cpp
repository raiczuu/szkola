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
                swap(tab[i], tab[i + 1]);   // zamienia miejscami 2 elementy
                zamienione = true;
            }
        }

        // jesli nie bylo zmiany, zakoncz petle
        if (!zamienone) {
            break;
        }

        // zmniejsz zakres o 1

        --koniec; // operator dekrementacji, zmiejsza wartosc zmiennej koniec o 1

        // Przechodzenie od prawej do lewej strony
        for (int i = koniec - 1; i >= poczatek; --i) {
            if (tab[i] > tab[i + 1]) {
                swap(tab[i], tab[i + 1]);
                zamienione = true;
            }
        }

        // zwieksz zakres o 1

        ++poczatek; // operator inkrementacji, zwieksza wartosc zmiennej o 1
    }
}

/////////////////////// Algorytm sortowania przez scalanie
void scalanie(int tab[], int lewa, int srodek, int prawa) {
    int a = srodek - lewa + 1;
    int b = prawa - srodek;

    int *lewaTablica = new int[a];   // sluzy do przydzielenia pamieci dla tablicy liczb. Calk, zwracania wskaznika do pierwszego elementu tablicy
    int *prawaTablica = new int[b];

    // kopiowanie danych do tymczasowej tablicy
    for (int i = 0; i < a; ++i) {
        lewaTablica[i] = tab[lewa + i];
    }
    for (int j = 0; j < b; ++j) {
        prawaTablica[j] = tab[srodek + 1 + j];
    }

    // laczenie dwoch tymczasowych tablic w 1 posortowana
    int i = 0;
    int j = 0;
    int k = lewa;
    while (i < a && j < b) {       // petla bedzie kontynuowana dopoki oba warunki sa spelnione
        if (lewaTablica[i] <= prawaTablica[j]) {
            tab[k] = lewaTablica[i];
            ++i; // inkrementacja i o + 1
        } else {
            tab[k] = prawaTablica[j];
            ++j; // inkrementacja j o + 1
        }
        ++k; // inkrementacja k o + 1
    }

    // jezeli sa pozostale elementy lewej tablicy, skopiuj je
    while (i < a) {
        tab[k] = lewaTablica[i]; // przepisuje wartosci z lewej tablicy do innej
        ++i; // inkrementacja i o + 1
        ++k; // inkrementacja k o + 1
    }

    // jezeli sa pozostale elementy prawej tablicy, skopiuj je
    while (j < b ) {
        tab[k] = prawaTablica[j]; // przepisuje wartosci z prawej tablicy do innej
        ++j; // inkrementacja j o + 1
        ++k; // inkrementacja k o + 1
    }

    delete[] lewaTablica;  // zwalnia pamiec ktora wczesciej przydzielilismy
    delete[] prawaTablica; // zwalnia pamiec ktora wczesciej przydzielilismy
}

void sortowaniePrzezScalanie(int tab[], int lewa, int prawa) {
    if (lewa < prawa) {
        int srodek = lewa + (prawa - lewa) / 2;  // oblicza srodek przedzialu miedzy lewa a prawa

        // Sort lewej i prawej czesci
        sortowaniePrzezScalanie(tab, lewa, srodek);  // posortowanie tej czesci
        sortowaniePrzezScalanie(tab, srodek + 1, prawa); // posortowanie tej czesci 

        // Scal posortowane czesci
        scalanie(tab, lewa, srodek, prawa);  // laczy 2 posortowane fragmenty tablicy
    }
}

/////////////////////// Algorytm sortowania szybkiego
int szybkie(int tab[], int niski, int wysoki) {
    int pivot = tab[wysoki];  // Wybierz ostatni element jako pivot
    int i = niski - 1;        // Indeks mniejszego elementu

    for (int j = niski; j <= wysoki - 1; ++j) {
        if (tab[j] < pivot) {  // sprawdza czy wartosc j w tab jest mniejsza od pivota
            ++i; // inkrementacja i o 1
            swap(tab[i], tab[j]);
        }
    }

    swap(tab[i + 1], tab[wysoki]); // zamienia miejcami wartosci dwoch elemtnow w tab
    return i + 1;
}

void sortowanieSzybkie(int tab[], int niski, int wysoki) {
    if (niski < wysoki) {
        // Znajdź indeks podziału
        int pi = szybkie(tab, niski, wysoki);  // pi = pivot, wywoluje funkcje

        // Sortuj osobno elementy przed i po podziale
        sortowanieSzybkie(tab, niski, pi - 1); // To wywolajanie odnosi sie do lewej czesci tablicy gdzie elemtny sa mniejsze niz pivot
        sortowanieSzybkie(tab, pi + 1, wysoki); // --- | --- do prawej czesci 
    }
}

/////////////////////// Algorytm sortowania przez  Wstawianie
void sortowaniePrzezWstawianie(int tab[], int rozmiar) {
    for (int i = 1; i < rozmiar; ++i) {
        int klucz = tab[i];
        int j = i - 1;

        // Przesuwanie elementów większych niż klucz
        // do jednego miejsca w prawo
        while (j >= 0 && tab[j] > klucz) { 
            tab[j + 1] = tab[j];
            --j; // dekramentacja j o - 1
        }

        tab[j + 1] = klucz;
    }
}

int main() {
    // Przykładowe użycie sortowania bąbelkowego
    int tabBabelkowe[] = {64, 34, 25, 12, 22, 11, 90};
    int rozmiarBabelkowe = sizeof(tabBabelkowe) / sizeof(tabBabelkowe[0]); // oblicza rozmiar tablicy
    sortowanieBabelkowe(tabBabelkowe, rozmiarBabelkowe); // przekazuje tablice i jej rozmiar jako argument

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
