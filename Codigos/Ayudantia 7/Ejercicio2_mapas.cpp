#include <iostream>
#include <map>
#include <vector>
#include <string>

using namespace std;

class Netflix {
public:
    map<string, vector<string> > Peliculas;

    Netflix() {} 

    void agregarGenero(string genero) {
        Peliculas[genero] = vector<string>();
        cout << "Genero '" << genero << "' agregado." << endl;
        cout<<"-----------------------------------------------------------------"<<endl;
    }

    void agregarTitulo(string genero, string titulo) {
        if (Peliculas.find(genero) == Peliculas.end()) {
            cout << "El genero '" << genero << "' no esta registrado." << endl;
            return;
        }

        Peliculas[genero].push_back(titulo);
        cout << "Titulo '" << titulo << "' agregado al genero '" << genero << "'." << endl;
        cout<<"-----------------------------------------------------------------"<<endl;
    }

   void mostrarTitulosPorGenero(string genero) {
   	
    if (Peliculas.find(genero) == Peliculas.end()) {
    	cout<<"-----------------------------------------------------------------"<<endl;
        cout << "El genero '" << genero << "' no esta registrado." << endl;
        return;
    }
    cout<<"-----------------------------------------------------------------"<<endl;
    cout << "Títulos en el genero '" << genero << "':" << endl;
    
    map<string, vector<string> >::iterator rec;   
    for (rec = Peliculas.begin(); rec != Peliculas.end(); rec++) {
        if (rec->first == genero) {
            cout << rec->first << endl;
            for (int i = 0; i < rec->second.size(); i++) {
                cout << "Nombres: " << rec->second[i] << endl;
            }	
        }
    }
}
};

int main() {
    Netflix peliculas; 

    peliculas.agregarGenero("Accion");
    peliculas.agregarGenero("Drama");
    peliculas.agregarGenero("Comedia");
    peliculas.agregarGenero("Animacion");

    peliculas.agregarTitulo("Accion", "Robocop");
    peliculas.agregarTitulo("Accion", "Jhon Wick");
    peliculas.agregarTitulo("Drama", "La la land");
    peliculas.agregarTitulo("Comedia", "¿Que paso ayer?");
    peliculas.agregarTitulo("Comedia", "Supercool");
    peliculas.agregarTitulo("Animacion", "Look Back");

    peliculas.mostrarTitulosPorGenero("Accion");
    peliculas.mostrarTitulosPorGenero("Drama");
    peliculas.mostrarTitulosPorGenero("Comedia");
    peliculas.mostrarTitulosPorGenero("Animacion"); 

}

