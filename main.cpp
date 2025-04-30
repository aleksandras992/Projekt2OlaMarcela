#include <iostream>
#include <queue>
#include <future>

using namespace std;

queue<double> generujTasme();
void zaladujSamoachody(queue<double>&);
void pokazWszytskiePartie();

int main() {
    srand(time(0));
    queue<double> tasma;
    int wybor;

    do {
        cout << "1. Wytworz partie na tasmociagu\n";
        cout << "2. Zaladuj towar do auta\n";
        cout << "3. Pokaz wszystkie partie zaladowane do aut\n";
        cout << "4. Zakoncz program i wyjdz\n";
        cin >> wybor;

        if (wybor == 1) {
            future<queue<double>> przyszlaTasma = async(generujTasme);
            tasma = przyszlaTasma.get();
        } else if (wybor == 2) {
            zaladujSamoachody(tasma);
        } else if (wybor == 3) {
            pokazWszytskiePartie();
        } else if (wybor == 4) {
            cout << "Dziekujemy za skorzystanie z programu.\n";
        } else {
            cout << "Nieznana opcja. \n";
        }
    } while (wybor != 4);

    return 0;
}