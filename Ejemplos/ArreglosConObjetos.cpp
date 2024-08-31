#include <iostream>
using namespace std;
class Arreglo
{
	private:
		int numeros;
		public:
			Arreglo(int numeros)
			{
				this->numeros=numeros;
			}
			int getNumeros()
			{
				return numeros;
			}
};
int main()
{
	Arreglo*Objeto[3];
	Objeto[0]=new Arreglo(1);
	Objeto[1]=new Arreglo(2);
	Objeto[2]=new Arreglo(3);
	for(int i=0;i<3;i++)
	{
		cout<<Objeto[i]->getNumeros()<<endl;
	}
}
