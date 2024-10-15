#include <iostream>
#include <vector>
using namespace std;
class Ejemplo
{
	private:
		vector<int>Numeros;
	public:
		Ejemplo()
		{
	}
	void AgregarUnElemento(int numero)
	{
		Numeros.push_back(numero);
		cout<<"Se agrego el numero al vector"<<endl;
	}
	void EliminarUltimo()
	{
		Numeros.pop_back();
		cout<<"Se elimino el ultimo elemento del vector"<<endl;
	}
	void Size()
	{
		cout<<"El vector tiene un tamaño de: "<< Numeros.size()<<endl;
	}
	void HayAlgo()
	{
		if(Numeros.empty()==false)
		{
			cout<<"El vector contiene algo"<<endl;
		}
		else
		{
			cout<<"El vector esta vacio"<<endl;
		}
	}
	void UltimoYInicio()
	{
		cout<<"El primer elemento del vector es: "<<Numeros.front()<<endl;
		cout<<"El ultimo elemento del vector es: "<<Numeros.back()<<endl;
	}
	void BorrarTodo()
	{
		Numeros.clear();
		cout<<"Se borraron todos los elementos del vector"<<endl;
	}
	void Buscar(int Buscar)
	{
		cout<<"El elemento que se encontro en la posicion pedida es: "<<Numeros.at(Buscar)<<endl;
	}
	void BorrarElPrimero()
	{
		Numeros.erase(Numeros.begin());
		cout<<"Se borro el primer elemento"<<endl;
	}
	void BorrarPenultimo()
	{
		Numeros.erase(Numeros.end()-2);
		cout<<"Se borro el penultimo elemento"<<endl;
	}
	void Imprimir()
	{
		for(int i=0;i<Numeros.size();i++)
		{
			//cout<<Numeros.at(i)<<"//";
			cout<<Numeros[i]<<"//";
		}
		cout<<endl;
	}
};
int main()
{
	Ejemplo*objeto=new Ejemplo();
	
	objeto->HayAlgo();
	cout<<"--------------------------------------------------------------------------"<<endl;
	objeto->AgregarUnElemento(8);
	objeto->AgregarUnElemento(5);
	objeto->AgregarUnElemento(1);
	objeto->AgregarUnElemento(42);
	objeto->Imprimir();
	objeto->HayAlgo();
	objeto->Size();
	cout<<"--------------------------------------------------------------------------"<<endl;
	objeto->EliminarUltimo();
	objeto->Imprimir();
	objeto->Size();
	cout<<"--------------------------------------------------------------------------"<<endl;
	objeto->UltimoYInicio();
	cout<<"--------------------------------------------------------------------------"<<endl;
	objeto->Buscar(2);
	cout<<"--------------------------------------------------------------------------"<<endl;
	objeto->BorrarElPrimero();
	objeto->Imprimir();
	cout<<"--------------------------------------------------------------------------"<<endl;
	objeto->BorrarPenultimo();
	objeto->Imprimir();
	cout<<"--------------------------------------------------------------------------"<<endl;
	objeto->BorrarTodo();
	objeto->HayAlgo();
}
