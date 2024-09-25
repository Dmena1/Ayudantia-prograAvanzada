#include <iostream>
using namespace std;
class Investigacion
 {
  private:
   int Nature;
   int Science;
   int Astrophys;
  public:
  	Investigacion()
  	 {
  	 	Nature = 0;
  	 	Science = 0;
  	 	Astrophys = 0;
	   }
	void acumularEnRevista(string nombreRevista)
	 {
	  if (nombreRevista == "Nature")
	    {
	    Nature++;	
			}	
	  if (nombreRevista == "Science")
	    {
	    Science++;	
			} 
	  if (nombreRevista == "Astrophys")
	    {
	    Astrophys++;	
			}
	 }
	void eliminarArticuloRevista(string nombreRevista)
	 {
	  if (nombreRevista == "Nature" && Nature > 0)
	    {
	    Nature--;	
			}	
	  if (nombreRevista == "Science" && Science > 0)
	    {
	    Science--;	
			} 
	  if (nombreRevista == "Astrophys" && Astrophys > 0)
	    {
	    Astrophys--;	
			}
	 }
void imprimirEstadisticas()
 {
 	cout << "ESTADISTICAS INVESTIGACION"<<endl;
 	cout << "Nature "<< Nature << " articulos" << endl;
 	cout << "Science "<< Science << " articulos" << endl;
 	cout << "Astrophys "<< Astrophys << " articulos" << endl;
 	float suma = Nature + Science + Astrophys;
 	if ( suma > 0) 
 	  {
       	cout << "Nature "<< Nature/suma *100.0 << " %" << endl;
	 	cout << "Science "<< Science/suma *100.0 << " %" << endl;
 		cout << "Astrophys "<< Astrophys/suma *100.0 << " %" << endl;
 	  	
	   }
	cout << "----------------------"<<endl<<endl;
	  }	 
    };
main()
 {
	Investigacion *inv = new Investigacion();
	inv->imprimirEstadisticas();
	inv->acumularEnRevista("Nature");
	inv->acumularEnRevista("Nature");
	inv->acumularEnRevista("Science");
	inv->acumularEnRevista("Nature");
	inv->acumularEnRevista("Nature");
	inv->acumularEnRevista("Astrophys");
	inv->acumularEnRevista("Astrophys");
	inv->imprimirEstadisticas();
 }
