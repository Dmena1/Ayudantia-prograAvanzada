#include <iostream>
using namespace std;
class Ejemplo4
{
	private:
		int Arreglo[4];
	public:
		//Constructor de la clase Ejemplo4, en el cual le daremos valores a cada casilla del arreglo
		Ejemplo4(int n1,int n2,int n3,int n4)
		{
			Arreglo[0]=n1;
			Arreglo[1]=n2;
			Arreglo[2]=n3;
			Arreglo[3]=n4;
		}
		//Funcion BubbleSort
		//aqui debes recordar que en este ejemplo tenemos un maximo de 4 casillas y estas son 0,1,2,3 
		void BubbleSort() {
			//Aqui tenemos un for i, el cual empezara en la casilla 0 hasta la 2, este no avanzara hasta que el for j acabe
            for(int i = 0; i < 3; i++) {
            	//De la misma forma contamos con un for j, el cual iniciara en la del frente de i.
            	//A partir de ahora vamos a tomar en cuenta solo la primera iteracion de j, y que el arreglo tiene estos valores(9,4,1,7)
                for(int j = i + 1; j < 4; j++) {
                    if (Arreglo[i] > Arreglo[j]) {// Aqui se pregunta si el valor que tiene la casilla 0 es mas grande que el valor de la casilla 1(9<4)
                        int aux = Arreglo[i];// Se inicializa una variable auxiliar int, la cual tendra el valor de la casilla 0(aux=9)
                        Arreglo[i] = Arreglo[j];//Como el valor de la casilla 1, era mas pequeño que el de 0, ahora 0 tendra el valor de la casilla 1. Antes(9,4,1,7). Despues(4,4,1,7)
                        Arreglo[j] = aux;//Aqui cambios el valor de la casilla 1, por el valor del auxiliar que en este caso era el antiguo valor de la casilla 0
                        //Dejando asi esta primera iteracion de j de la siguiente manera(4,9,1,7)
                        //Dejare un pdf de como se realizan las siguiente iteraciones del BubbleSort, junto con este codigo en GitHub
                    }
                }
            }
        }

        void Imprimir()
        {
        	cout<<"El arreglo esta asi actualmente: ";
            for(int i=0;i<4;i++)
		   {
		    	cout<<Arreglo[i]<<"/ ";
			                    }	
		}

};
int main()
{
	Ejemplo4* Objeto= new Ejemplo4(9,4,1,7);
	Objeto->Imprimir();
	cout<<endl;
	cout<<"Despues del BubbleSort el arreglo quedo de esta forma-> "<<endl;
	Objeto->BubbleSort();
	Objeto->Imprimir();
}
