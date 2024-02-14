#include <iostream>
#include "sortowanie.hpp"
using namespace std;

int main() {
    // Przykladowe uzycie sortowania babelkowego
    int tabBabelkowe[] = {64, 34, 25, 12, 22, 11, 90, 80, 21, 1, 99, 43};
    int rozmiarBabelkowe = sizeof(tabBabelkowe) / sizeof(tabBabelkowe[0]); // oblicza rozmiar tablicy
    sortowanieBabelkowe(tabBabelkowe, rozmiarBabelkowe); // przekazuje tablice i jej rozmiar jako argument

    cout << "Sortowanie babelkowe:\n";
    for (int i = 0; i < rozmiarBabelkowe; ++i) {
        cout << tabBabelkowe[i] << " ";
    }
    cout << "\n\n";

    // koktajlowego
        int tabKoktajlowego[] = {64, 34, 25, 12, 22, 11, 90, 80, 21, 1, 99, 43};
    int rozmiarKoktajlowego = sizeof(tabKoktajlowego) / sizeof(tabKoktajlowego[0]); 
    sortowanieKoktajlowe(tabKoktajlowego, rozmiarKoktajlowego);

    cout << "Sortowanie koktajlowe:\n";
    for (int i = 0; i < rozmiarKoktajlowego; ++i) {
        cout << tabKoktajlowego[i] << " ";
    }
    cout << "\n\n";

    // scalanie
    int tabScalanie[] = {64, 34, 25, 12, 22, 11, 90, 80, 21, 1, 99, 43};
    int rozmiarScalanie = sizeof(tabScalanie) / sizeof(tabScalanie[0]);
    sortowaniePrzezScalanie(tabScalanie, 0, rozmiarScalanie - 1);

    cout << "Sortowanie przez scalanie:\n";
    for (int i = 0; i < rozmiarScalanie; ++i) {
        cout << tabScalanie[i] << " ";
    }
    cout << "\n\n";

    // szybkiego
    int tabSzybkie[] = {64, 34, 25, 12, 22, 11, 90, 80, 21, 1, 99, 43};
    int rozmiarSzybkie = sizeof(tabSzybkie) / sizeof(tabSzybkie[0]);
    sortowanieSzybkie(tabSzybkie, 0, rozmiarSzybkie - 1);

    cout << "Sortowanie szybkie:\n";
    for (int i = 0; i < rozmiarSzybkie; ++i) {
        cout << tabSzybkie[i] << " ";
    }
    cout << "\n\n";
 
    // wstawianie
    int tabWstawianie[] = {64, 34, 25, 12, 22, 11, 90, 80, 21, 1, 99, 43};
    int rozmiarWstawianie = sizeof(tabWstawianie) / sizeof(tabWstawianie[0]);
    sortowaniePrzezWstawianie(tabWstawianie, rozmiarWstawianie);

    cout << "Sortowanie przez wstawianie:\n";
    for (int i = 0; i < rozmiarWstawianie; ++i) {
        cout << tabWstawianie[i] << " ";
    }
    cout << "\n\n";
 
    return 0;
}
