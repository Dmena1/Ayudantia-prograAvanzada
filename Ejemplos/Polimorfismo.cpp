#include <iostream>
using namespace std;
class Animal
{
	protected:
		string nombre;
	public:
		Animal(string nombre)
		{
			this->nombre=nombre;
		}
		virtual void Sonido()
		{
			cout<<"bla bla bla bla"<<endl;
		}
};

class Perro : public Animal
{
	protected:
		string color;
	public:
		Perro(string nombre, string color) : Animal(nombre)
		{
			this->color=color;
		}
		virtual void Sonido()
		{
			cout<<"El perro con nombre: "<<nombre<<", el color del perro es: "<<color<<" dice: Guau Guau"<<endl;
		}
};

class Gato : public Animal
{
	protected:
		string color;
	public:
		Gato(string nombre, string color) : Animal(nombre)
		{
			this->color=color;
		}
		virtual void Sonido()
		{
			cout<<"El gato con nombre: "<<nombre<<", el color del gato es: "<<color<<" dice: Miauuuuu"<<endl;
		}
};
int main()
{
	Perro * p = new Perro("Kiara", "Gris");
	Gato * g = new Gato("Sammy", "Negro");
	Animal* Arreglo[2]={p,g};
	for(int i=0;i<2;i++)
	{
		Arreglo[i]->Sonido();
	}
}
