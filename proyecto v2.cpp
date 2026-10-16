#include <iostream>
#include <string>
using namespace std;

struct Alumno {
    string nombre;
    string matricula;
    float calif[3];
    int grupo;
};

struct Maestro {
    string nombre;
    string materia;
};

struct Grupo {
    string nombre;
    string carrera;
};

int main() {
    Alumno alumnos[100];
    Maestro maestros[50];
    Grupo grupos[20];

    int totalAlumnos = 0;
    int totalMaestros = 0;
    int totalGrupos = 0;
    int opcion;

    do {
        cout << "\n===== MENU =====" << endl;
        cout << "1. Capturar alumnos" << endl;
        cout << "2. Capturar grupos y carreras" << endl;
        cout << "3. Capturar maestros" << endl;
        cout << "4. Mostrar reportes" << endl;
        cout << "5. Salir" << endl;
        cout << "Opcion: ";
        cin >> opcion;
        cin.ignore();

        switch (opcion) {

        case 1: {
            if (totalGrupos == 0) {
                cout << "Primero captura los grupos (opcion 2)" << endl;
                break;
            }

            int n;
            cout << "Cuantos alumnos quieres capturar? ";
            cin >> n;
            cin.ignore();

            if (totalAlumnos + n > 100) {
                cout << "No caben tantos alumnos (maximo 100)" << endl;
                break;
            }

            for (int i = totalAlumnos; i < totalAlumnos + n; i++) {
                cout << "Alumno " << i + 1 << endl;
                cout << "  Nombre: ";
                getline(cin, alumnos[i].nombre);
                cout << "  Matricula: ";
                getline(cin, alumnos[i].matricula);
                for (int j = 0; j < 3; j++) {
                    cout << "  Calificacion " << j + 1 << ": ";
                    cin >> alumnos[i].calif[j];
                    while (alumnos[i].calif[j] < 0 || alumnos[i].calif[j] > 100) {
                        cout << "  Calificacion invalida, escribela otra vez: ";
                        cin >> alumnos[i].calif[j];
                    }
                }

                cout << "  Grupos:" << endl;
                for (int g = 0; g < totalGrupos; g++) {
                    cout << "    " << g + 1 << ". " << grupos[g].nombre << endl;
                }
                int num;
                cout << "  Numero de grupo: ";
                cin >> num;
                while (num < 1 || num > totalGrupos) {
                    cout << "  Grupo invalido, escribelo otra vez: ";
                    cin >> num;
                }
                alumnos[i].grupo = num - 1;
                cin.ignore();
            }
            totalAlumnos = totalAlumnos + n;
            break;
        }

        case 2: {
            int n;
            cout << "Cuantos grupos quieres capturar? ";
            cin >> n;
            cin.ignore();

            if (totalGrupos + n > 20) {
                cout << "No caben tantos grupos (maximo 20)" << endl;
                break;
            }

            for (int i = totalGrupos; i < totalGrupos + n; i++) {
                cout << "Grupo " << i + 1 << endl;
                cout << "  Nombre: ";
                getline(cin, grupos[i].nombre);
                cout << "  Carrera: ";
                getline(cin, grupos[i].carrera);
            }
            totalGrupos = totalGrupos + n;
            break;
        }

        case 3: {
            int n;
            cout << "Cuantos maestros quieres capturar? ";
            cin >> n;
            cin.ignore();

            if (totalMaestros + n > 50) {
                cout << "No caben tantos maestros (maximo 50)" << endl;
                break;
            }

            for (int i = totalMaestros; i < totalMaestros + n; i++) {
                cout << "Maestro " << i + 1 << endl;
                cout << "  Nombre: ";
                getline(cin, maestros[i].nombre);
                cout << "  Materia: ";
                getline(cin, maestros[i].materia);
            }
            totalMaestros = totalMaestros + n;
            break;
        }

        case 4: {
            if (totalAlumnos == 0) {
                cout << "No hay alumnos capturados" << endl;
                break;
            }

            cout << "\nPromedios:" << endl;
            for (int i = 0; i < totalAlumnos; i++) {
                float suma = 0;
                for (int j = 0; j < 3; j++) {
                    suma = suma + alumnos[i].calif[j];
                }
                cout << alumnos[i].nombre << " (" << alumnos[i].matricula << "): " << suma / 3 << endl;
            }

            cout << "\nMejor alumno por grupo:" << endl;
            for (int g = 0; g < totalGrupos; g++) {
                float mejor = -1;
                int posicion = -1;
                for (int i = 0; i < totalAlumnos; i++) {
                    if (alumnos[i].grupo == g) {
                        float suma = 0;
                        for (int j = 0; j < 3; j++) {
                            suma = suma + alumnos[i].calif[j];
                        }
                        float prom = suma / 3;
                        if (prom > mejor) {
                            mejor = prom;
                            posicion = i;
                        }
                    }
                }
                if (posicion == -1) {
                    cout << grupos[g].nombre << ": no tiene alumnos" << endl;
                } else {
                    cout << grupos[g].nombre << ": " << alumnos[posicion].nombre << " con " << mejor << endl;
                }
            }

            cout << "\nAlumnos por carrera:" << endl;
            for (int g = 0; g < totalGrupos; g++) {
                // revisar si esta carrera ya se mostro antes
                int repetida = 0;
                for (int k = 0; k < g; k++) {
                    if (grupos[k].carrera == grupos[g].carrera) {
                        repetida = 1;
                    }
                }
                if (repetida == 0) {
                    int contador = 0;
                    for (int i = 0; i < totalAlumnos; i++) {
                        if (grupos[alumnos[i].grupo].carrera == grupos[g].carrera) {
                            contador++;
                        }
                    }
                    cout << grupos[g].carrera << ": " << contador << endl;
                }
            }
            break;
        }

        case 5:
            cout << "Adios" << endl;
            break;

        default:
            cout << "Opcion no valida" << endl;
        }

    } while (opcion != 5);

    return 0;
}
