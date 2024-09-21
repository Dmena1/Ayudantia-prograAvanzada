#include <iostream>
using namespace std;
class Numero
{
	private:
		int numero;
	public:
		Numero(int numero)
		{
			this->numero=numero;
		}
		int getNumero()
		{
			return numero;
		}
};
class Ejemplo4
{
	private:
		Numero* Arreglo[4];
	public:
		Ejemplo4()
		{
			for(int i=0;i<4;i++)
			{
				Arreglo[i]=NULL;
			}
		}
		void Agregar(Numero*Objeto)
		{
			for(int i=0;i<4;i++)
			{
				if(Arreglo[i]==NULL)
				{
					Arreglo[i]=Objeto;
					break;
				}
			}
		}
		void BubbleSort() {
            for(int i = 0; i < 3; i++) {
                for(int j = i + 1; j < 4; j++) {
                    if (Arreglo[i]->getNumero() > Arreglo[j]->getNumero()) {
                        Numero* aux = Arreglo[i];
                        Arreglo[i] = Arreglo[j];
                        Arreglo[j] = aux;
                    }
                }
            }
        }
        void Imprimir()
        {
        	cout<<"El arreglo esta asi actualmente: ";
        for(int i=0;i<4;i++)
		{
			cout<<Arreglo[i]->getNumero()<<"/ ";
			}	
		
		}

};
int main()
{
	Ejemplo4* Objeto= new Ejemplo4;
	Numero* Objeto1= new Numero(5);
	Numero* Objeto2= new Numero(9);
	Numero* Objeto3= new Numero(3);
	Numero* Objeto4= new Numero(1);

	Objeto->Agregar(Objeto1);
	Objeto->Agregar(Objeto2);
	Objeto->Agregar(Objeto3);
	Objeto->Agregar(Objeto4);
	Objeto->Imprimir();
	cout<<endl;
	cout<<"Despues del BubbleSort el arreglo quedo de esta forma-> "<<endl;
	Objeto->BubbleSort();
	Objeto->Imprimir();
}
