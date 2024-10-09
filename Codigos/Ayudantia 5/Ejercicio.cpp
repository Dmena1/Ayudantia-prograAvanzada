#include <iostream>
using namespace std;

class Deportista {
protected:
    string nombre;
    string rut;

public:
    Deportista(string nombre, string rut) {
        this->nombre = nombre;
        this->rut = rut;
    }
    
    void imprimir() {
        cout << "El nombre del deportista es: " << nombre << "; el Rut del deportista es: " << rut << endl;
    }

    string getRut() {
        return rut;
    }
};

class Carrera : public Deportista {
protected:
    float tiempos[3];

public:
    Carrera(string nombre, string rut, float tiempos[3]) : Deportista(nombre, rut) {
        for (int i = 0; i < 3; i++) {
            this->tiempos[i] = tiempos[i];
        }
    }

    void imprimir3() {
        cout << "Tiempos de Carrera: ";
        for (int i = 0; i < 3; i++) {
            cout << tiempos[i] << " segundos ";
        }
        cout << endl;
    }

    void ordenarTiempos() {
        for(int i = 0; i < 2; i++) {
            for(int j = i + 1; j < 3; j++) {
                if (tiempos[i] > tiempos[j]) {
                    float aux = tiempos[i];
                    tiempos[i] = tiempos[j];
                    tiempos[j] = aux;
                }
            }
        }
    }

    float obtenerMenorTiempo() {
        return tiempos[0]; 
    }
};

int main() {
    float tiempos[3];
    Carrera* competidorCarrera[3];
    int opcion;
    bool ExisteCarrera = false;

    while (true) {
        cout << "1.- Ingresar un competidor de carrera" << endl;
        cout << "2.- Imprimir el competidor de carrera y su mejor tiempo" << endl;
        cout << "3.- Comparar dos competidores de carrera" << endl;
        cout << "4.- Ordenar los tiempos" << endl;
        cout << "Cualquier número para salir" << endl;
        cin >> opcion;

        if (opcion < 1 || opcion > 4) {
            break;
        } else if (opcion == 1 && ExisteCarrera==false) {
            for(int i = 0; i < 3; i++) {
                string nombre, rut;
                cout << "Ingrese el nombre del participante "<<i+1<<" ";
                cin >> nombre;
                cout << "Ingrese el rut del participante "<<i+1<<" ";
                cin >> rut;
                for (int j = 0; j < 3; j++) {
                    cout << "Ingrese el tiempo en segundos para la carrera " << (j + 1) << ": ";
                    cin >> tiempos[j];
                }
                competidorCarrera[i] = new Carrera(nombre, rut, tiempos);    
                ExisteCarrera=true;
            }
            ExisteCarrera = true;
        } else if (opcion == 2 && ExisteCarrera==true) {
            for(int i = 0; i < 3; i++) {
                competidorCarrera[i]->imprimir();
                competidorCarrera[i]->imprimir3();
                cout << "Mejor tiempo: " << competidorCarrera[i]->obtenerMenorTiempo() << " segundos" << endl;
            }
        } else if (opcion == 3 && ExisteCarrera==true) {
            string rut1, rut2;
            float mejorTiempo1, mejorTiempo2;
            cout << "Ingrese el rut del primer competidor de carrera a comparar: ";
            cin >> rut1;
            cout << "Ingrese el rut del segundo competidor de carrera a comparar: ";
            cin >> rut2;

            for(int i = 0; i < 3; i++) {
                if(competidorCarrera[i]->getRut() == rut1) {
                    mejorTiempo1 = competidorCarrera[i]->obtenerMenorTiempo();
                } else if(competidorCarrera[i]->getRut() == rut2) {
                    mejorTiempo2 = competidorCarrera[i]->obtenerMenorTiempo();
                }
            }

            if (mejorTiempo1 < mejorTiempo2) {
                cout << "El competidor rut: " << rut1 << " tiene el mejor tiempo: " << mejorTiempo1 << " segundos." << endl;
            } else if (mejorTiempo1 > mejorTiempo2) {
                cout << "El competidor rut: " << rut2 << " tiene el mejor tiempo: " << mejorTiempo2 << " segundos." << endl;
            } else {
                cout << "Ambos competidores tienen el mismo mejor tiempo." << endl;
            }
        } else if (opcion == 4 && ExisteCarrera) {
            for (int i = 0; i < 3; i++) {
                competidorCarrera[i]->ordenarTiempos();
            }
            cout << "Tiempos ordenados para cada competidor:" << endl;
        }
    }
}

