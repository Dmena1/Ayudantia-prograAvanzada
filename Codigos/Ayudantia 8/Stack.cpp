#include <iostream>
#include <stack>
using namespace std;

class Videojuego {
private:
    string nombre, genero, desarrollador;
    int anio, precio;

public:
    Videojuego(string nombre, string genero, string desarrollador, int anio, int precio) {
        this->nombre = nombre;
        this->genero = genero;
        this->desarrollador = desarrollador;
        this->anio = anio;
        this->precio = precio;
    }

    string getGenero() {
        return genero;
    }

    void info() {
        cout << "Nombre: " << nombre << " - Género: " << genero << " - Desarrollador: " << desarrollador << " - Año: " << anio << " - Precio: " << precio << endl;
    }
};

class Weplay {
private:
    stack<Videojuego*> pilaDesordenada; 
    stack<Videojuego*> pilaAccion;      
    stack<Videojuego*> pilaAventura;    
    stack<Videojuego*> pilaEstrategia;  

public:
    Weplay() {
        pilaDesordenada.push(new Videojuego("Call of Duty", "Acción", "Activision", 2003, 59));
        pilaDesordenada.push(new Videojuego("The Legend of Zelda", "Aventura", "Nintendo", 1986, 49));
        pilaDesordenada.push(new Videojuego("Civilization VI", "Estrategia", "Firaxis", 2016, 29));
        pilaDesordenada.push(new Videojuego("Super Mario Odyssey", "Aventura", "Nintendo", 2017, 59));
        pilaDesordenada.push(new Videojuego("Doom Eternal", "Acción", "id Software", 2020, 59));
    }

    void ordenar() {
        while (pilaDesordenada.empty()==false) {
            string genero = pilaDesordenada.top()->getGenero();
            if (genero == "Acción") {
                pilaAccion.push(pilaDesordenada.top());
                cout << "Videojuego Agregado a Acción." << endl;
            } else if (genero == "Aventura") {
                pilaAventura.push(pilaDesordenada.top());
                cout << "Videojuego Agregado a Aventura." << endl;
            } else if (genero == "Estrategia") {
                pilaEstrategia.push(pilaDesordenada.top());
                cout << "Videojuego Agregado a Estrategia." << endl;
            } else {
                cout << "Error al ordenar." << endl;
            }
            pilaDesordenada.top()->info(); 
            pilaDesordenada.pop(); 
            cout << " - -- - - - " << endl;
        }
        cout << "Piloto de videojuegos ordenada!" << endl;
    }


    void mostrarCatalogo() {
        cout << "Videojuegos en Acción:" << endl;
        while (pilaAccion.empty()==false) {
            pilaAccion.top()->info();
            pilaAccion.pop();
        }

        cout << "Videojuegos en Aventura:" << endl;
        while (pilaAventura.empty()!=true) {
            pilaAventura.top()->info();
            pilaAventura.pop();
        }

        cout << "Videojuegos en Estrategia:" << endl;
        while (pilaEstrategia.empty()==false) {
            pilaEstrategia.top()->info();
            pilaEstrategia.pop();
        }
    }
};

int main() {
    Weplay* tiendita = new Weplay(); 
    tiendita->ordenar();                   
    tiendita->mostrarCatalogo();             
}

