#include <iostream>
#include <map>
#include <stack>
using namespace std;

int main ()
{
	map<string, stack<string> >Pepe;
	int opcion;
	while(true){
	cout<<"1.- Anadir Raza y nombre"<<endl;
	cout<<"2.- Imprimir"<<endl;
	cin>>opcion;
	if(opcion==1){
		
		cout<<"Ingresa la raza del animal"<<endl;
		string raza;
		cin>>raza;
	
		for(int i=0;i<3;i++)
		{
			string nombre;
			cout<<"Ingrese el nombre de la raza"<<endl;
			cin>>nombre;
			Pepe[raza].push(nombre);
		}
	}
				
	else if(opcion==2)
	{
		map<string, stack<string> > ::iterator rec;
		for(rec=Pepe.begin(); rec != Pepe.end(); rec++)
		{
			int i=0;
			cout<<"Animal: "<<rec->first<<endl;
			stack<string>aux = rec->second;
			while (aux.empty()!=true)
			{
				
				cout<<"Nombre "<<i+1<<": "<<aux.top()<<endl;
				aux.pop();
				i=i+1;
			}
		}
	}
	else if(opcion>=3)
	{
		break;
	}
}
}


