#include <iostream>
using namespace std;
class Mascota
{
	protected:
		string nombre;
		int edad;
	public:
		Mascota(string nombre, int edad)
		{
			this->nombre=nombre;
			this->edad=edad;
		}
	void Imprimir()
	{
		cout<<"El nombre es: "<<nombre<<"; Y su edad es: "<<edad<<" años"<<endl;
	}
	void setNombre(string Nombre)
	{
		nombre=Nombre;
	}
	void setEdad(int Edad)
	{
		edad=Edad;
	}
};
class Perro : public Mascota
{
	protected:
		string raza;
		string color;
	public:
		Perro(string nombre, int edad, string raza, string color) : Mascota(nombre, edad)
		{
			this->raza=raza;
			this->color=color;
		}
	void setRaza(string Raza)
	{
		raza=Raza;
	}
	void setColor(string Color)
	{
		color=Color;
	}
	void Imprimir2()
	{
		cout<<"La raza del perrito es: "<<raza<<"; Y su color principal es: "<<color<<endl;
	}
};
int main()
{
	Perro* objeto= new Perro("Deisy", 12, "Maltes", "Blanca");
	objeto->Imprimir();
	objeto->Imprimir2();
	objeto->setNombre("Kiara");
	objeto->setEdad(5);
	objeto->setRaza("Schnauzer");
	objeto->setColor("Gris");
	cout<<"-------------------------------------------------------------------"<<endl;
	objeto->Imprimir();
	objeto->Imprimir2();
}
