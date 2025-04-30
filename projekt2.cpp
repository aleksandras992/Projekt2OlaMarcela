#include <iostream>
#include <vector>
#include <queue>
#include <stack>
#include <cstdlib>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <future>

using namespace std;

double losujWage(double min, double max) {
    return ((rand() % static_cast<int>((max - min) * 100 + 1)) / 100.0) + min;
}

queue<double> generujTasme() {
    queue<double> tasma;
    int ile = rand() % 10 + 1;
    cout << "\n Wtworzono " << ile << " przedmiotow:\n";
    for (int i = 0; i < ile; i++) {
        double waga = losujWage(1.0, 20.0);
        tasma.push(waga);
        cout << fixed << setprecision(2) << waga << " kg\n";
    }
    cout << endl;
    return tasma;
}

class Samochod {
private:
    double maxLadownosc;
    double aktualnaLadownosc;
    stack<double> ladunek;
public:
    Samochod() {
        maxLadownosc = rand() % 41 + 20;
        aktualnaLadownosc = 0;
    }

    bool czyZmiesci(double waga) {
        return aktualnaLadownosc + waga <= maxLadownosc;
    }

    void dodajPrzedmiot(double waga) {
        ladunek.push(waga);
        aktualnaLadownosc += waga;
    }

    void pokazSamochod(int numer) {
        const int szerokosc = 30;
        stack<double> kopia = ladunek;
        vector<double> odwrocona;

        while (!kopia.empty()) {
            odwrocona.push_back(kopia.top());
            kopia.pop();
        }

        string linia = "+" + string(szerokosc - 2, '-') + "+";
        cout << linia << "\n";
        cout << "| " << left << setw(szerokosc - 3) << ("Samochod nr " + to_string(numer)) << "|\n";
        cout << "| " << left << setw(szerokosc - 3) << ("Ladownosc " + to_string(static_cast<int>(maxLadownosc)) + " kg") << "|\n";
        cout << linia << "\n";
        cout << "| " << left << setw(szerokosc - 3) << "Ladunek:" << "|\n";

        for (double w : odwrocona) {
            ostringstream ss;
            ss << fixed << setprecision(2) << w << " kg";
            cout << "| -- " << left << setw(szerokosc - 6) << ss.str() << "|\n";
        }
        cout << linia << "\n\n";
    }
};

vector<vector<Samochod>> wszystkiePartie;
int numerPartii = 0;

void zaladujSamoachody(queue<double>& tasma) {
    vector<Samochod> partia;
    if (tasma.empty()) {
        cout << "Tasma pusta\n";
        return;
    }

    Samochod auto1;
    while (!tasma.empty()) {
        double waga = tasma.front();
        if (auto1.czyZmiesci(waga)) {
            auto1.dodajPrzedmiot(waga);
            tasma.pop();
        } else {
            partia.push_back(auto1);
            auto1 = Samochod();
        }
    }
    partia.push_back(auto1);
    wszystkiePartie.push_back(partia);
    numerPartii++;

    cout << "Partia " << numerPartii << " spakowana:\n\n";
    for (size_t i = 0; i < partia.size(); i++) {
        partia[i].pokazSamochod(i + 1);
    }
}

void pokazWszytskiePartie() {
    if (wszystkiePartie.empty()) {
        cout << "NIe ma jeszcze partii\n\n";
        return;
    }
    for (size_t i = 0; i < wszystkiePartie.size(); i++) {
        cout << "Partia " << i + 1 << ":\n";
        for (size_t j = 0; j < wszystkiePartie[i].size(); j++) {
            wszystkiePartie[i][j].pokazSamochod(j + 1);
        }
    }
}