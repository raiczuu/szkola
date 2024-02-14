#include <iostream>
#include "wyszukiwanie.hpp"
using namespace std;

int main() {
    // Przykladowe uzycie sortowania wyszukiwania
    int tablica[] = {10, 20, 30, 40, 50, 60, 70};
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
    
    // binarne
    int klucz4 = 20;
    int indeks4 = binarne(tablica, rozmiar, klucz4);
    cout << "Binarne wyszukiwanie: " << indeks4 << endl;
    return 0;
}
