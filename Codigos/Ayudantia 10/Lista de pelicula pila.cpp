#include <iostream>
#include <map>
#include <stack>
using namespace std;
class Pelicula
{
	private:
		string nombre;
		int duracion;
	public:
		Pelicula(string nombre, int duracion)
		{
			this->nombre=nombre;
			this->duracion=duracion;
		}
		
		string getNombre()
		{
			return nombre;
		}
		int getDuracion()
		{
			return duracion;
		}
};
class Pila
{
	private:
		map<string,stack<Pelicula* > > Lista;
	public:
		Pila()
		{
			
		}
		void anadirGenero(string genero)
		{
			Lista[genero];
		}
		void anadirPeliculaxGenero(string genero)
		{
		 int Cantidad;
        cout << "Cuantas peliculas quieres poner en la lista para ver: ";
        cin >> Cantidad;
        for (int i = 0; i < Cantidad; i++)
        {
            string nombre;
            int duracion;
            cout << "Nombre de la pelicula a añadir: " << endl;
            cin >> nombre;
            cout << "Ingresa la duracion de la pelicula" << endl;
            cin >> duracion;
            Pelicula* pelicula = new Pelicula(nombre, duracion);
            Lista[genero].push(pelicula);
        }
		}
		void ImprimirXgenero()
		{	
		map<string, stack<Pelicula*> > ::iterator rec;
		for(rec=Lista.begin(); rec != Lista.end(); rec++)
		{
			int i=0;
			cout<<"Genero: "<<rec->first<<endl;
			stack<Pelicula* >aux = rec->second;
			while (aux.empty()!=true)
			{
				
				cout<<"Nombre "<<i+1<<": "<<aux.top()->getNombre()<<endl;
				cout<<"Duracion de la pelicula: "<<aux.top()->getDuracion()<<endl;
				aux.pop();
				i=i+1;
			}
		}
		}
		void CantidadXGenero()
		{
		map<string, stack<Pelicula* > > ::iterator rec;
		for(rec=Lista.begin(); rec != Lista.end(); rec++)
		{
			cout<<"Genero: "<<rec->first<<endl;
			cout<<"La cantidad de peliculas en la lista de este genero es: "<<rec->second.size()<<endl;
		}
	}
		void Eliminarpelicula(string genero, string nombre2)
		{
			stack<Pelicula*>aux;
			while(Lista[genero].empty()!=true)
			{
				if(Lista[genero].top()->getNombre()!=nombre2)
				aux.push(Lista[genero].top());		
				Lista[genero].pop();		
				}
			Lista[genero]=aux;	
		}
};
int main()
{
	Pila * pila=new Pila();
    int opcion;
    string genero,nombre;

    while (true) {
        cout << "Menu de opciones:" << endl;
        cout << "1. Añadir genero" << endl;
        cout << "2. Añadir peliculas por genero" << endl;
        cout << "3. Imprimir peliculas por genero" << endl;
        cout << "4. Mostrar cantidad de peliculas por genero" << endl;
        cout << "5. Eliminar una pelicula"<<endl;
        cout << "Salir" << endl;
        cin >> opcion;

        if (opcion == 1) {
            cout << "Introduce el nombre del genero a anadir: " << endl;
            cin >> genero;
            pila->anadirGenero(genero);
        } 
        else if (opcion == 2) {
            cout << "Introduce el genero para anadir peliculas: " << endl;
            cin >> genero;
            pila->anadirPeliculaxGenero(genero);
        }
        else if (opcion == 3) {
            pila->ImprimirXgenero();
        }
        else if (opcion == 4) {
            pila->CantidadXGenero();
        }
        else if (opcion >= 5) {
            cout<<"Introduce el genero de la pelicula a eliminar"<<endl;
            cin>>genero;
            cout<<"Introduce el nombre de la pelicula a eliminar"<<endl;
            cin>>nombre;
            pila->Eliminarpelicula(genero,nombre);
        }
        else if (opcion >= 6) {
            break;
        }

    }
}
