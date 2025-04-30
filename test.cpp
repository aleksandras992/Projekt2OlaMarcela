#include <cassert>
#include <queue>
#include <iostream>
using namespace std;

queue<double> generujTasme();

void test_generujTasme() {
    srand(0); 

    queue<double> t = generujTasme(); 

    assert(!t.empty() && t.size() <= 10);

    while (!t.empty()) {
        double w = t.front();
        assert(w >= 1.0 && w <= 20.0);
        t.pop();
    }

    cout << "Test generujTasme() przeszedl pomyslnie.\n";
}
int main() {
    test_generujTasme();
    return 0;
}