#include <iostream>
using namespace std;
class Evento
{
	private:
		int numero;
		int detenidos;
		int fugados;
		public: 
		Evento()
		{}
		void setNumero(int numero)
		{
			this->numero=numero;
		}
		void setDetenidos(int detenidos)
		{
			this->detenidos=detenidos;
		}
		void setFugados(int fugados)
		{
			this->fugados=fugados;
		}
		int getNumero()
		{
			return numero;
		}
		int getDetenidos()
		{
			return detenidos;
		}
		int getFugados()
		{
			return fugados;
		}
};
class PuntoCritico
{
	private:
		Evento*objeto[300];
	public:
		PuntoCritico()
		{
			for(int i=0;i<300;i++)
			{
				objeto[i]=NULL;
			}
		}
		void registrarEvento(Evento*e)
		{
			if(objeto[e->getNumero()]==NULL)
			{
				objeto[e->getNumero()]=e;
				cout<<"Se logro añadir al arreglo"<<endl;
			}
			else
			{
				objeto[e->getNumero()]->setNumero(objeto[e->getNumero()]->getFugados()+e->getFugados());
				objeto[e->getNumero()]->setNumero(objeto[e->getNumero()]->getDetenidos()+e->getDetenidos());
			}
		}
		void Estadisticas()
		{
			float contadorSinNovedad=0;
			float contadorConNovedad=0;
			int totalDetenidos=0;
			int totalFugados=0;
			int PuntoConMasFugados;
			for(int i=0;i<300;i++)
			{
				if(objeto[i]!=NULL)
				{
					contadorConNovedad++;
					totalDetenidos=totalDetenidos+objeto[i]->getDetenidos();
					totalFugados+=objeto[i]->getFugados();
					if(objeto[i]->getFugados()>objeto[i]->getDetenidos())
					{
						PuntoConMasFugados=i;
					}
				}
				else if(objeto[i]==NULL)
				{
					contadorSinNovedad++;
				}
			}
			float porcentajeSin= (contadorSinNovedad/300);
			float porcentajeCon=(contadorConNovedad/300);
			cout<<"El porcentaje de puntos criticos sin novedad es: "<<porcentajeSin*100<<"%"<<endl;
			cout<<"El porcentaje de puntos criticos con novedad es: "<<porcentajeCon*100<<"%"<<endl;
			cout<<"El total de detenidos es: "<<totalDetenidos<<endl;
			cout<<"El total de fugados es: "<<totalFugados<<endl;
			cout<<"El punto critico con mas fugados que detenidos es: "<<PuntoConMasFugados<<endl;
		}
				
};
int main()
{
	int numero, detenidos,fugados;
	PuntoCritico *Objeto2= new PuntoCritico();
	for(int i=0;i<5;i++)
	{
		cout<<"Ingrese el valor del numero del punto critico: ";cin>>numero;cout<<endl;
		cout<<"Ingrese el numero de detenidos: ";cin>>detenidos;cout<<endl;
		cout<<"Ingrese el numero de fugados: ";cin>>fugados;cout<<endl;
		Evento*Objeto1=new Evento();
		Objeto1->setNumero(numero);
		Objeto1->setDetenidos(detenidos);
		Objeto1->setFugados(fugados);
		Objeto2->registrarEvento(Objeto1);
	}
		Objeto2->Estadisticas();
}
