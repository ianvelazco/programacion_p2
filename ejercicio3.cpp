#include <iostream>
using namespace std;

int main() {
    float matriz[10][3];

    for (int i = 0; i < 10; i++) {
        cout << "Alumno " << i + 1 << endl;
        cout << "  Promedio grupo A: ";
        cin >> matriz[i][0];
        cout << "  Promedio grupo B: ";
        cin >> matriz[i][1];

        if (matriz[i][0] >= matriz[i][1]) {
            matriz[i][2] = matriz[i][0];
        } else {
            matriz[i][2] = matriz[i][1];
        }
    }

    cout << "\nAlumno\tGrupo A\tGrupo B\tMas alto" << endl;
    for (int i = 0; i < 10; i++) {
        cout << i + 1 << "\t" << matriz[i][0] << "\t" << matriz[i][1] << "\t" << matriz[i][2] << endl;
    }

    return 0;
}