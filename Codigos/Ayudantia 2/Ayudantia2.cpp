#include <iostream> 
using namespace std;
class Persona
{
	private:
		string nombre, rut;
	public:
		Persona(string nombre, string rut)
		{
			this->nombre=nombre;
			this->rut=rut;
		}
		string getNombre()
		{
			return nombre;
		}
		string getRut()
		{
			return rut;
		}
};
class Bus
{
	private:
		Persona*Arreglo[4];
	public:
		Bus()
		{
			for(int i=0;i<4;i++)
			{
				Arreglo[i]=NULL;
			}
		}
	void VentaAsientos(Persona*Objeto1, int asiento)
	{
		if(Arreglo[asiento]==NULL)
		{
			Arreglo[asiento]= Objeto1;
			cout<<"Asiento comprado"<<endl;
		}
		else
		{
			cout<<"El asiento ya esta ocupado"<<endl;
		}
	}
	void BuscarMiAsiento(string rut)
	{
		int x=0;
		for(int i=0;i<4;i++)
		{
			if(Arreglo[i]!=NULL && Arreglo[i]->getRut()==rut)
			{
				cout<<"Su asiento es: "<<i<<endl;
				x=1;
				break;
			}
			
		}
		if(x==0)
		{
			cout<<"Usted no ha comprado ningun asiento en el bus"<<endl;
		}
	}
	void imprimir()
	{
		cout<<"-------------------------------------------------------"<<endl;
			cout<<"|";
			
			for(int i=0;i<4;i++)
			{
				if(Arreglo[i]!=NULL)
				{
              cout << Arreglo[i]->getNombre() << "// " << Arreglo[i]->getRut() << "// Asiento: " << i;			
			  }
			else{
				cout<<" asiento disponible ";
			}
			cout<<"|";
			}
			cout<<endl;
			cout<<"-------------------------------------------------------"<<endl;
	}
	void DevolverAsiento(string rut)
	{
		for(int i=0;i<4;i++)
		{
			if(Arreglo[i]!=NULL && Arreglo[i]->getRut()==rut)
			{
				Arreglo[i]=NULL;
				break;
			}
			
		}
	}
};
int main()
{
	Bus*buses= new Bus();
	Persona*persona1=new Persona("Polanco", "2145");
	Persona*persona2=new Persona("Matias", "8634");
	buses->VentaAsientos(persona1, 1);
	buses->VentaAsientos(persona2, 2);
	buses->imprimir();
    system("pause");
	system("cls");
	buses->DevolverAsiento("2145");
	buses->imprimir();
}
