#include <iostream>
using namespace std;
class perros
{
	private:
		int edad;
		string nombre;
		string dueno;
	public:
		perros(int Edad, string Nombre, string Dueno)
		{
			this->edad=Edad;
			this->nombre=Nombre;
			this->dueno=Dueno;
		}
		void Encontrado()
		{
			if(dueno=="Vicente")
			{
				cout<<"encontrado"<<endl;
			}
		}
		string getNombre()
		{
			return nombre;
		}
		string getDueno()
		{
			return dueno;
		}
		int getEdad()
		{
			return edad;
		}
		void setDueno(string Dueno)
		{
			dueno=Dueno;
		}
};
int main()
{
	int Cantidad, edad;
	float promedio=0;
	string nombre, dueno;
	cout<<"Cuantos perros se quieren ingresar en la lista?"<<endl;
	cin>>Cantidad;
	perros *Lista[Cantidad];
	for(int i=0;i<Cantidad;i++)
	{
		cout<<"Numero de lista: "<<i+1<<endl;
		cout<<"Nombre del perro: "; cin>>nombre; cout<<endl;
		cout<<"Edad del perro: "; cin>>edad; cout<<endl;
		cout<<"Nombre del dueño: "; cin>>dueno; cout<<endl;
    Lista[i]= new perros(edad,nombre,dueno);
	}
	Lista[0]->setDueno("Banda");
	if(Lista[0]->getDueno()=="Banda")
	{
		cout<<"El cambio a sido realizado con exito"<<endl;
	}
	for(int i=0;i<Cantidad;i++)
	{
		cout<<"Numero de lista: "<<i+1<<endl;
		cout<<"Nombre del perro: "<<Lista[i]->getNombre() <<endl;
		cout<<"Nombre del dueño: "<<Lista[i]->getDueno() <<endl;
		Lista[i]->Encontrado();
	}
	for(int i=0;i<Cantidad;i++)
	{
	 promedio=promedio+Lista[i]->getEdad();
	}
	cout<<"El promedio de la edad de los perros es: "<< promedio/Cantidad<<endl;
}

