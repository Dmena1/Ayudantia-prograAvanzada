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
		void setNombre(string nuevoNombre)
		{
			nombre=nuevoNombre;
		}
		string getNombre()
		{
			return nombre;
		}		
};
int main()
{
	perros *objeto = new perros(4,"Kiara","Mena");
	perros *Arreglo[3];
	Arreglo[0]=new perros(1,"Deisy","Araceli");
	Arreglo[1]=new perros(2,"Nina","Britanic");
	Arreglo[2]=new perros(3,"Loki","Miguel");
	cout<<objeto->getNombre()<<endl;
	objeto->setNombre("Deisy");
	cout<<objeto->getNombre()<<endl;
	for(int i=0;i<3;i++)
	{
	cout<<Arreglo[i]->getNombre()<<endl;
	}
}

