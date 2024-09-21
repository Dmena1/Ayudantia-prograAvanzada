#include <iostream>
using namespace std;
class Clientes
{
	private:
		string nombre;
		string rut;
		int edad;
	public:
    Clientes(string nombre, string rut, int edad) {
        this->nombre = nombre;
        this->rut = rut;
        this->edad = edad;
    }

    int getEdad() {
        return edad;
    }

    string getNombre() {
        return nombre;
    }

    string getRut() {
        return rut;
    }

    void setNombre(string nuevoNombre) {
        nombre = nuevoNombre;
    }

    void setRut(string nuevoRut) {
        rut = nuevoRut;
    }

    void setEdad(int nuevaEdad) {
        edad = nuevaEdad;
    }
};
class Cine
{
	private:
		Clientes*funcion[6];
	public:
		Cine()
		{
			for(int i=0;i<6;i++)
			{
				funcion[i]=NULL;
			}
		}
		void venderAsiento(int asiento, Clientes*clientes)
		{
			if (asiento >= 0 && asiento < 6 && funcion[asiento] == NULL) {
            funcion[asiento] = clientes;
            cout << "Asiento " << asiento << " vendido a " << clientes->getNombre() << endl;
        } else {
            cout << "El asiento no está disponible." << endl;
        }
		}
		
		void devolverAsiento(int asiento)
		{
			if (asiento >= 0 && asiento < 6 && funcion[asiento] != NULL) {
            cout << "Asiento " << asiento << " devuelto por " << funcion[asiento]->getNombre() << endl;
            funcion[asiento] = NULL;
        } else {
            cout << "El asiento no está ocupado." << endl;
        }
		}
		
		void Imprimir()
		{
			cout<<"---------------------------------------------------------------------------------------------------------------------"<<endl;
			for (int i = 0; i < 6; i++) {
            if (funcion[i] != NULL) {
                cout << "Asiento " << i << ": " << funcion[i]->getNombre() << " (" << funcion[i]->getRut() << "), " << funcion[i]->getEdad() << " años" << endl;
            } else {
                cout << "Asiento " << i << ": vacío" << endl;
            }
        }
		}
		
		void promedioedades()
		{
		int sumaEdades = 0;
        for (int i = 0; i < 6; i++) {
            if (funcion[i] != NULL) {
                sumaEdades= sumaEdades+ funcion[i]->getEdad();
            }
        }
        cout<<"El promedio de las edades es: "<<sumaEdades<<endl;
		}
		
		void modificarCliente(int asiento, string nuevoNombre, string nuevoRut, int nuevaEdad) {
        if (asiento >= 0 && asiento < 6 && funcion[asiento] != NULL) {
            funcion[asiento]->setNombre(nuevoNombre);
            funcion[asiento]->setRut(nuevoRut);
            funcion[asiento]->setEdad(nuevaEdad);
            cout << "Datos del cliente en el asiento " << asiento << " modificados." << endl;
        } else {
            cout << "No hay cliente en el asiento " << asiento << " para modificar." << endl;
        }
    }
};
int main()
{
    Cine* funcion = new Cine();

    Clientes* Persona1 = new Clientes("Aldo", "212456",19);
    Clientes* Persona2 = new Clientes("Isi", "2123124",21);
    Clientes* Persona3 = new Clientes("Ariel", "2124124",20);

    funcion->venderAsiento(0, Persona1);
    funcion->venderAsiento(1, Persona2);
    funcion->venderAsiento(2, Persona3);

    funcion->Imprimir();
    funcion->promedioedades();
    funcion->devolverAsiento(0);
    funcion->Imprimir();
    funcion->modificarCliente(1,"Angi","12312314",20);
    funcion->Imprimir();

}
