#include <iostream>
using namespace std;
class Caja
{
	private:
		int id;
	public:
		Caja(int id)
		{
			this->id=id;
		}
		int getId()
		{
			return id;
		}
};
class Espacio
{
	private:
		Caja*cajas[4];
    public:
    	Espacio()
    	{
    		for(int i=0;i<4;i++)
    		{
    			cajas[i]=NULL;
			}
		}
		void Asignar(Caja*Objeto1, int espacio)
		{
			if(cajas[espacio]==NULL)
			{
				cajas[espacio]=Objeto1;
				cout<<"La caja a sido asignada al espacio: "<<espacio+1<<endl;
			}
			else
			{
				cout<<"El espacio esta lleno, la caja no cabe"<<endl;
			}
		}
		void buscarCaja(int id)
		{
		int x=0;	
			for(int i=0;i<4;i++)
			{
				if(cajas[i]!=NULL && cajas[i]->getId()==id)
				{
					cout<<"La caja esta en el espacio: "<<i+1<<endl;
					x=1;
				}
			}
		if(x==0)
		{
			cout<<"La caja no tiene un espacio asignado aun"<<endl;
		}	
		}
		
		void imprimir()
		{
			cout<<"-------------------------------------------------------"<<endl;
			cout<<"|";
			
			for(int i=0;i<4;i++)
			{
				if(cajas[i]!=NULL)
				{
				cout<<cajas[i]->getId();
			}
			else{
				cout<<" Espacio disponible ";
				
			}
			cout<<"|";
			}
			cout<<endl;
			cout<<"-------------------------------------------------------"<<endl;
		}
};
int main()
{
	
    Espacio *espacio = new Espacio();
    Caja *caja1 = new Caja(12345);
    Caja *caja2 = new Caja(67890);   
    espacio->Asignar(caja1,0);
    espacio->Asignar(caja2,3);
    espacio->imprimir();
		
}
