#include <iostream>
using namespace std;

int main() {
    float calif[6];
    float suma = 0;

    for (int i = 0; i < 5; i++) {
        cout << "Calificacion " << i + 1 << ": ";
        cin >> calif[i];
        suma = suma + calif[i];
    }
    
    calif[5] = suma / 5;

    cout << "\nCalificaciones:" << endl;
    for (int i = 0; i < 5; i++) {
        cout << "Parcial " << i + 1 << ": " << calif[i] << endl;
    }
    cout << "Promedio: " << calif[5] << endl;

    return 0;
}