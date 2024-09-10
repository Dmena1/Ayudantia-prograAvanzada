#include <iostream>
using namespace std;
int main ()
{
int Arreglo[3];
int n;
for(int i=0;i<3;i++)
{
	cout<<"Agregue el numero para insertar en la casilla: "<<i<<endl;
	cin>>n;
	Arreglo[i]=n;
}
for(int i=0;i<3;i++)
{
	cout<<Arreglo[i]<<"/";
}
}
