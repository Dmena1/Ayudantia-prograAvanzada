#include <iostream>
using namespace std;
class clase1
{
	protected:
		string nombre;
	public:
		clase1(string nombre)
		{
			this->nombre=nombre;
		}
		void Imprimir()
		{
			cout<<"El nombre es: "<<nombre<<endl;
		}
};
class clase2 : public clase1
{
	private:
		int edad;
	public:
		clase2(string nombre, int edad) : clase1(nombre)
		{
			this->edad=edad;
		}
	void Imprimir2()
	{
		Imprimir();
		cout<<"La edad es: "<<edad<<endl;
	}
};
//-----------------------------------------------------------------------------------
//-----------------------------------------------------------------------------------

class clase3 : public clase2
{
	protected:
		string rut;
	public:
		clase3(string nombre, int edad, string rut) : clase2(nombre, edad)
		{
		this->rut=rut;	
		}
		virtual void Imprimir()
		{
			Imprimir2();
			cout<<"Tengo: "<<edad<<"; y mi rut es: "<<rut<<endl;
		}
	
};

class clase4 : public clase2
{
	protected:
		string rut;
	public:
		clase4(string nombre, int edad, string rut) : clase2(nombre, edad)
		{
		this->rut=rut;	
		}
		virtual void Imprimir()
		{
			cout<<"PEPEPEPEPPEPEPEPPEPEPEPEPPEPEPEPE"<<endl;
		}
	
};


int main()
{
	clase2 * objeto1= new clase2("Seba", 12);
	objeto1->Imprimir2();
	cout<<"-------------------------------------------------"<<endl;
	objeto1->Imprimir();
	cout<<"------------------------------------------------------------------------------------------"<<endl;
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	clase3 * objeto2= new clase3("Richard", 52, "1234");
	objeto2->Imprimir();
	cout<<"-----------------------------------------------------------------------------------------"<<endl;
	clase4 * objeto3= new clase4("Richard", 52,"1234");
	objeto3->Imprimir();

}
