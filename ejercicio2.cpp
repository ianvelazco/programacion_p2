#include <iostream>
using namespace std;

int main() {
    float grupo1[5], grupo2[5], mayor[5];

    cout << "Promedios del grupo 1:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Alumno " << i + 1 << ": ";
        cin >> grupo1[i];
    }

    cout << "\nPromedios del grupo 2:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Alumno " << i + 1 << ": ";
        cin >> grupo2[i];
    }

    for (int i = 0; i < 5; i++) {
        if (grupo1[i] >= grupo2[i]) {
            mayor[i] = grupo1[i];
        } else {
            mayor[i] = grupo2[i];
        }
    }

    cout << "\nPos\tGrupo 1\tGrupo 2\tMas alto" << endl;
    for (int i = 0; i < 5; i++) {
        cout << i + 1 << "\t" << grupo1[i] << "\t" << grupo2[i] << "\t" << mayor[i] << endl;
    }

    return 0;
}