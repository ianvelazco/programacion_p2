#include <iostream>
#include <string>
using namespace std;

int main() {
    string completo, nombre, apellido;
    bool valido = true;

    cout << "Ingrese nombre y apellido: ";
    getline(cin, completo);

    int pos = completo.find(' ');

    if (pos == string::npos) {
        cout << "Debe ingresar nombre y apellido separados por un espacio." << endl;
        return 0;
    }

    nombre = completo.substr(0, pos);
    apellido = completo.substr(pos + 1);

    for (int i = 0; i < nombre.length(); i++) {
        if (nombre[i] >= '0' && nombre[i] <= '9') {
            valido = false;
        }
    }

    for (int i = 0; i < apellido.length(); i++) {
        if (apellido[i] >= '0' && apellido[i] <= '9') {
            valido = false;
        }
    }

    if (valido) {
        cout << "Nombre: " << nombre << endl;
        cout << "Apellido: " << apellido << endl;
    } else {
        cout << "El nombre y el apellido no deben contener numeros." << endl;
    }

    return 0;
}