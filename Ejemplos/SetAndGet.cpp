#include <iostream>
using namespace std;
class ejemploSetAndGet
{
	private:
	int entero;
	string caracteres;
	public:
		//-------------------------------------------------------------------------------
		ejemploSetAndGet(int numero, string palabra)
		{
			entero=numero;
			caracteres=palabra;
		}
		//------------------------------------------------------------------------------
		//ejemploSetAndGet(int entero, string caracteres)
		//{
		//	this->entero=entero;
		//	this->caracteres=caracteres;
		//}
		//------------------------------------------------------------------------------
		//void SetEntero(int numero)
		//{
		//	entero=numero;
		//}
		//void SetCaracteres(string palabra)
		//{
		//	caracteres=palabra;
		//}
		//----------------------------------------------------------------------------------
		int getNumero()
		{
			return entero;
		}
		string getCaracteres()
		{
			return caracteres;
		}
};
int main()
{
	ejemploSetAndGet*Objeto=new ejemploSetAndGet(1,"Hola");
	//-----------------------------------------------------------
    //ejemploSetAndGet*Objeto=new ejemploSetAndGet();
	//Objeto->SetEntero(1);
	//Objeto->SetCaracteres("Hola");
	//------------------------------------------------------------
	cout<<Objeto->getNumero()<<endl;
	cout<<Objeto->getCaracteres()<<endl;
	
}
