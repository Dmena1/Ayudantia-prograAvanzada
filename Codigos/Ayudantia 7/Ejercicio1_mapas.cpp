#include <iostream>
#include <map>
using namespace std;

class GestionCalificaciones {
private:
    map<string, float> estudiantes; 

public:
    void agregarEstudiante(string nombre) {
        estudiantes[nombre] = 1.0;
    }

    void agregarNotas(string nombre) {
        if (estudiantes.find(nombre) != estudiantes.end()) {
            float sumaNotas = 0;
            float nota;
            for (int i = 0; i<3; ++i) {
                cout << "Ingrese la nota " << i << " para " << nombre << ": ";
                cin >> nota;
                sumaNotas += nota; 
            }
            float promedio = sumaNotas / 3; 
            estudiantes[nombre] = promedio;
        } else {
            cout << "Estudiante no encontrado."<<endl;
        }
    }

    void imprimir() {
        map<string, float>::iterator rec;
        for (rec=estudiantes.begin();rec!=estudiantes.end();rec++) {
            cout << " El estudiante: " << rec->first << "; tiene un promedio de: " << rec->second << endl;
        }
    }
};

int main() {
    GestionCalificaciones gestion;
    gestion.agregarEstudiante("Vixon");
    gestion.agregarEstudiante("Shi hao");

    gestion.agregarNotas("Vixon");
    gestion.agregarNotas("Shi hao");

    gestion.imprimir();
    
}

