#include <iostream>
#include <map>
using namespace std;
class Ejemplo
{
	private:
		map<string, int>Sueldo;
	public:
		Ejemplo()
		{
		}
		
		void Agregar(string rut, int dinero)
		{
			Sueldo[rut]=dinero;
		}
		void BuscarSueldo(string rut)
		{
			if(Sueldo[rut]>=0)
			{
				cout<<"El sueldo de la persona con rut: "<<rut<<" es: "<<Sueldo[rut]<<endl;
			}
		}
};
int main()
{
	Ejemplo * objeto= new Ejemplo();
	
	objeto->Agregar("1234", 24000);
	objeto->Agregar("5678", 37000);
	
	objeto->BuscarSueldo("1234");
}
