#include <iostream>
#include <math.h>
using namespace std;
class Triangulo
{
	private:
		int ladoA;
		int ladoB;
		int ladoC;
	public:
		Triangulo(int ladoA, int ladoB, int ladoC)
		{
			this->ladoA=ladoA;
			this->ladoB=ladoB;
			this->ladoC=ladoC;
		}
		bool Validar()
		{
			if(ladoA+ladoB>ladoC || ladoB+ladoC>ladoA || ladoC+ladoA>ladoB)
			{
				return true;
			}
			else
			{
				return false;
			}
		}
		string ObtieneTipo()
		{
			if(Validar()==true)
			{
				if(ladoA==ladoB==ladoC)
				{
					return "equilatero";
				}
				else if(ladoA==ladoB!=ladoC||ladoC==ladoB!=ladoA||ladoB==ladoC!=ladoA)
				{
					return "isosceles";
				}
				else if(ladoA!=ladoB!=ladoC||ladoC!=ladoB!=ladoA||ladoB!=ladoC!=ladoA)
				{
					return "escaleno";
				}
			}
			else
			{
				return "triangulo invalido";
			}
		}
		float obPerimetro()
		{
			float suma;
			if(Validar()==true)
			{
				suma=ladoA+ladoB+ladoC;
				return suma;
			}
			else
			{
				return -1;
			}
		}
		float obArea()
		{
			if(Validar()==true)
			{
				float S=obPerimetro()/2;
				return sqrt(S*(S-ladoA)*(S-ladoB)*(S-ladoC));
			}
		}		
};
int main()
{
	Triangulo* objeto1 = new Triangulo(2,2,2);
	Triangulo* objeto2 = new Triangulo(2,3,2);
	Triangulo* objeto3 = new Triangulo(2,3,4);
	cout<<"El perimetro del triangulo equilatero es: "<<objeto1->obPerimetro()<<endl;
	cout<<"El area del triangulo equilatero es: "<<objeto1->obArea()<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<"El perimetro del triangulo isosceles es: "<<objeto2->obPerimetro()<<endl;
	cout<<"El area del triangulo isosceles es: "<<objeto2->obArea()<<endl;
	cout<<"--------------------------------------------------"<<endl;
	cout<<"El perimetro del triangulo escaleno es: "<<objeto3->obPerimetro()<<endl;
	cout<<"El area del triangulo escaleno es: "<<objeto3->obArea()<<endl;
	
}
