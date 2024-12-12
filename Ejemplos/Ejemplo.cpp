#include <iostream>
#include <queue>
#include <vector>
#include <math.h> 
using namespace std;

int main()
{
    int cantidad;
    queue<int> Ejemplo;
    vector<queue<int> > Vector;

    cout << "Ingresa la cantidad de sumas que realizara" << endl;
    cin >> cantidad;

    for (int i = 0; i < cantidad; i++)
    {
        int cantDigitos;
        cout<<"------------------------------------------------------------------------------------------------"<<endl;
        cout << "Ingrese la cantidad de numeros a anadir para la suma " << i + 1 << ":" << endl;
        cin >> cantDigitos;

        for (int j = 0; j < cantDigitos; j++)
        {
            int numero;
            cout << "Ingrese un numero a anadir" << endl;
            cin >> numero;
            Ejemplo.push(numero);
        }

        Vector.push_back(Ejemplo); 
        while (Ejemplo.empty()!=true)
        {
            Ejemplo.pop(); 
        }
}

    for (int i = 0; i < cantidad; i++)
    {
        queue<int> Aux = Vector[i];
        int total = 0;
        cout<<"------------------------------------------------------------------------------------------------"<<endl;
        cout << "Los numeros en la suma " << i + 1 << " son: ";
        while (Aux.empty()!=true)
        {
        	cout<<Aux.front()<<"//";
            total += Aux.front();
            Aux.pop();
        }
        cout << " => Total: " << total << endl;
    }
}

