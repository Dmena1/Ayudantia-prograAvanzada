#include <iostream>
#include <vector>
using namespace std;

class Estudiante {
private:
    string rut;
    string nombre;
    vector<float> Notas;

public:
    Estudiante(string rut, string nombre) {
        this->rut = rut;
        this->nombre = nombre;
    }

    void ingresarUnaNota(float nota) {
        Notas.push_back(nota);
    }

    void ingresarMuchasNotas(vector<float> Lista) {
        for(int i=0;i<Lista.size();i++)
        {
        	Notas.push_back(Lista.at(i));
		}
    }

    float calcularPromedio() {
    	
         int n = Notas.size();
        float sum = 0;
        for (int i = 0; i < n; i++) {
            sum += Notas.at(i);
        }
        return sum / n;
    }

    void lista() {
        cout << "Notas de " << nombre << " (RUT: " << rut << "):" << endl;
        for (int i=0;i<Notas.size();i++) {
            cout << "Nota " << i + 1 << ": " << Notas[i] << endl;
        }
    }
};
int main() {
    Estudiante *estudiante = new Estudiante("1234", "Shi Hao");
    estudiante->ingresarUnaNota(7);
    vector<float> Muchas = {6, 4.5, 6};
    estudiante->ingresarMuchasNotas(Muchas);
    estudiante->lista();
    cout << "Promedio: " << estudiante->calcularPromedio() << endl;
}

