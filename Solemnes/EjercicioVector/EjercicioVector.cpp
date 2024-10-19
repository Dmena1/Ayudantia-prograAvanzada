
/*
Hagan un código para poder observar si un estudiante se logró eximir y, si no, que indique qué nota necesita para pasar un ramo X. Para esto, se les pide crear una clase Situacion, la cual tiene como parámetros floats para las notas de las solemnes 1 y 2, además de contar con un vector<float> que almacene 4 controles que el estudiante tuvo que realizar. En el constructor, las notas de las solemnes deben estar inicializadas en 0.

Funcionalidades requeridas:

Debe haber métodos para agregar las notas de las solemnes 1 y 2.
Un método void agregarNotaC(float nota) que permita al usuario añadir las notas de los controles.
Una función bool que indique si el estudiante puede eximirse, verificando primero que estén completas tanto las notas de las solemnes como las de los controles.
Una función float que retorne la nota que tiene el estudiante si se eximió.
Una función float que retorne la nota que necesita el estudiante si no logró eximirse.

verifiquen siempre que las notas que se les ponen a las variables deben ser mayor igual a 1, como menor y igual 7
Y que el calculo es este: s1*0.35+s2*0.35+pc*0.3
*/


#include <iostream>
#include <vector>
using namespace std;
class Situacion
{
	private:
		float s1;
		float s2;
		vector<float>controles;
	public:
		Situacion()
		{
			s1=0;
			s2=0;
		}
	void SetS1(float nota)
	{
		if(nota>=1 && nota<=7)
		{
		s1=nota;	
		}
		else
		{
		cout<<"Ingrese un valor valido"<<endl;	
		}
		
			}	
	
	void SetS2(float nota)
	{
		if(nota>=1 && nota<=7)
		{
		s2=nota;	
		}
		else
		{
		cout<<"Ingrese un valor valido"<<endl;	
		}
			}	
	
	void agregarNotaC(float nota)
	{
		if(controles.size()<=4 && nota>=1 && nota<=7)
		{
			controles.push_back(nota);
			int cantidad= 4-controles.size();
			cout<<"Se pueden ingresar: "<<cantidad<<" notas de control más"<<endl;
		}
		else if(controles.size()>4)
		{
			cout<<"Ya no se pueden añadir más notas de controles"<<endl;
		}
		else if(nota<1 && nota>7)
		{
			cout<<"Nota invalida, no se agrego al vector"<<endl;
		}
	}
				
			
	bool Eximirse()
	{	
	float suma=0,pc;
	
		if(s1!=0 && s2!=0 && controles.size()==4)
		{
			for(int i=0; i<4;i++)
			{
				suma=suma+controles.at(i);
			
			}
			pc=suma/controles.size();
			
			if(s1*0.35+s2*0.35+pc*0.3>=5)
			{
			 return true;	
			}
			
			else if(s1*0.35+s2*0.35+pc*0.3<5)
			{
			return false;
			}
		} 
	}
	
	float Eximido()
	{
	float suma=0,pc;
		
		for(int i=0; i<4;i++)
			{
				suma=suma+controles.at(i);
			
			}
			
	pc=suma/controles.size();
	
		if(Eximirse()==true)
		{
		  return s1*0.35+s2*0.35+pc*0.3;
		}
	}
	
	float NoEximido()
	{
	float suma=0,pc;
		
		for(int i=0; i<4;i++)
			{
				suma=suma+controles.at(i);
			
			}
			
	    pc=suma/controles.size();
	
		if(Eximirse()==false)
		{
		  	return (4-(s1*0.35+s2*0.35+pc*0.3)*0.7)/0.3;
		}	
	}			
};
int main()
{
	Situacion* estudiante= new Situacion();
	estudiante->SetS1(5);
	estudiante->SetS2(7);
	estudiante->agregarNotaC(5);
	estudiante->agregarNotaC(4);
	estudiante->agregarNotaC(2);
	estudiante->agregarNotaC(1);
	if(estudiante->Eximirse()==true)
	{
		cout<<"El estudiante se eximio con un: "<<estudiante->Eximido()<<endl;
	}
	else
	{
		cout<<"El estudiante necesita un: "<<estudiante->NoEximido()<<"; para poder pasar el ramo"<<endl;
	}
}

