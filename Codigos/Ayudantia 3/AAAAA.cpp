#include <iostream>
using namespace std;
//--------------------------------------------------------------
    //ClaseA
class ClaseA
{
private:
	//--------------------------------------------------------------
    //Inicializamos la variable numero, la cual es un Int
int numero;
public:
	//--------------------------------------------------------------
	//constructor
ClaseA(int numero)
{
	this->numero=numero;
	}	
	//--------------------------------------------------------------
    //Funcion que retornara el valor del atributo Numero
  int getNumero()
  {
  	return numero;
  }
    //--------------------------------------------------------------
    //Funcion que retornara el valor del atributo Numero
  void setNumero(int  newNumber)
  {
  	numero=newNumber;
  }
};
//--------------------------------------------------------------
    //ClaseB
class ClaseB
{
private:
	//--------------------------------------------------------------
    //inicializamos el objeto el cual en vez de ser una variable int, string, float, etc. Esta variable sera perteneciente de la clase A.
ClaseA*Objeto;
public:
	//--------------------------------------------------------------
    //Constructor de la clase B 
ClaseB(ClaseA*Objeto)
{
	this->Objeto=Objeto;
	}
	//--------------------------------------------------------------
    //En esta funcion le pediremos a nuestro objeto que ocupe una de las funciones de la clase a la que pertenece, la cual es getNumero, para asi poder imprimir el mensaje y el valor que nos retornara la funcion getNumero
	void imprimir()
	{
		cout<<"EL numero ingresado en la claseA es: "<<Objeto->getNumero()<<endl;
		}
		//--------------------------------------------------------------
    //En esta funcion inicializamos una nueva variable int, en donde le pediremos al usuario que le asigne un valor a este, para que nuestro objeto haga uso de la funcion setNumero, modificando el valor del atributo que este tenia con anteridad
		void NewNumber()
		{
			int newNumber;
			cout<<"Cual sera el nuevo valor de la claseA: "<<endl;
			cin>>newNumber;
			Objeto->setNumero(newNumber);
		}
		
};
int main()
{
	//Inicializamos el objeto A, el cual pertenece a la clase ClaseA, en donde el constructor nos pide que le demos un valor a su variable en este caso A
	ClaseA* A = new ClaseA(18);
	//Inicializamos el objeto B, el cual pertenece a la clase ClaseB, en donde el constructor nos pide que le demos un objeto que perteneza a la clase ClaseA
	ClaseB* B = new ClaseB(A);
	//Ocupamos las funciones que puede usar el objeto de la clase B 
	B->imprimir();
	B->NewNumber();
	B->imprimir();
}
