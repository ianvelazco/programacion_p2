#include <iostream>
using namespace std;

int main() {
    float ventas[100];
    float total = 0;

    for (int i = 0; i < 100; i++) {
        cout << "Venta del cliente " << i + 1 << ": ";
        cin >> ventas[i];
        total = total + ventas[i];
    }

    cout << "\nTotal de ingresos: " << total << endl;

    return 0;
}