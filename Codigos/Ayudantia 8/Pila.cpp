#include <iostream>
#include <queue>
using namespace std;

class Persona {
private:
    string nombre;
    int boletos;

public:
    Persona(string nombre, int boletos)
    {
    	this->nombre=nombre;
    	this->boletos=boletos;
	}

    string getNombre() {
        return nombre;
    }

    int getBoletos(){
        return boletos;
    }
};

void mostrarFila(queue<Persona*> q) {
    cout << "Estado actual de la fila:" << endl;
    if (q.empty()==true) {
        cout << "La fila est� vac�a." << endl;
    } else {
        int posicion = 1;
        while (q.empty()!=true) {
            Persona*p = q.front();
            cout << "Posici�n " << posicion << ": " << p->getNombre() << " con " << p->getBoletos() << " boletos." << endl;
            q.pop();
            posicion++;
        }
    }
}

int main() {
    queue<Persona*> fila;
    int opcion;

    while (true) {
        cout << "1. Agregar persona a la fila" << endl;
        cout << "2. Dejar entrar a la persona en el frente de la fila" << endl;
        cout << "3. Mostrar el estado de la fila" << endl;
        cout << "otro numero para salir" << endl;
        cin >> opcion;

        if (opcion == 1) {
            string nombre;
            int boletos;
            cout << "Nombre de la persona: ";
            cin >> nombre;
            cout << "N�mero de boletos: ";
            cin >> boletos;
            Persona * p1= new Persona(nombre, boletos);
            fila.push(p1);
            cout << nombre << " ha sido agregado a la fila." << endl;
        }
        else if (opcion == 2) {
            if (fila.empty()==false) {
                Persona* siguientePersona = fila.front();
                cout << siguientePersona->getNombre() << " ha entrado al estadio con " << siguientePersona->getBoletos() << " boletos." << endl;
                fila.pop();
            } else {
                cout << "La fila est� vac�a, no hay nadie para dejar entrar." << endl;
            }
        }
        else if (opcion == 3) {
            mostrarFila(fila);
        }
        else if (opcion >= 4) {
            cout << "Saliendo del programa." << endl;
            break;
        }
    }
}
