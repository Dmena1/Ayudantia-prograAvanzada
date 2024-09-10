#include <iostream>
using namespace std;
class Alumno
{
private:
int edad;
string nombre;	
public:
	Alumno(int edad, string nombre)
	{
		this->edad=edad;
		this->nombre=nombre;
	}
	int getEdad()
	{
		return edad;
	}
	string getNombre()
	{
		return nombre;
	}
	void setNombre( string nuevoNombre)
	{
		nombre=nuevoNombre;
	}
	void setEdad( int nuevaEdad)
	{
		edad=nuevaEdad;
	}
};
class Lista
{
	private:
		Alumno* Arreglo[4];
	public:
		Lista()
		{
			for(int i=0;i<4;i++)
			{
				Arreglo[i]=NULL;
			}
		}
		void anadirAlumno(Alumno*Objeto)
		{
			int x=0;
			for(int i=0;i<4;i++)
			{
				if(Arreglo[i]==NULL)
				{
					Arreglo[i]=Objeto;
					x=1;
					break;
				}
			}
			if(x==0)
			{
				cout<<"La lista esta completa"<<endl;
			}
		}
		void imprimir()
		{
			for(int i=0;i<4;i++){
			if(Arreglo[i]!=NULL)
			{
				cout<<"--------------------------"<<endl;
				cout<<"nombre del alumno: "<<Arreglo[i]->getNombre()<<"/Y la edad es: "<<Arreglo[i]->getEdad()<<"/en la casilla: "<<i<<endl;
			}
		 }
		}
		void cambiarNombre(int casilla)
		{
			string nuevoNombre;
			if(Arreglo[casilla]!=NULL)
			{
				cout<<"Ingrese el nuevo nombre: "<<endl;
				cin>>nuevoNombre;
				Arreglo[casilla]->setNombre(nuevoNombre);
			}
		}
};
int main()
{
	Lista*lista= new Lista();
	Alumno*Nino1=new Alumno(21,"Aldo");
	Alumno*Nino2=new Alumno(21,"Isi");
	Alumno*Nino3= new Alumno(20,"Ariel");
	
	lista->anadirAlumno(Nino1);
	lista->anadirAlumno(Nino2);
	lista->anadirAlumno(Nino3);
	
	lista->imprimir();
	
	lista->cambiarNombre(1);
	
	lista->imprimir();
		
}
