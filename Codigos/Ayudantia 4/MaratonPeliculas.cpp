#include <iostream>
using namespace std;
class Pelicula
{
	private:
		string nombre;
		string genero;
		int duracion;
	public:
		Pelicula(string nombre, string genero, int duracion)
		{
			this->nombre=nombre;
			this->genero=genero;
			this->duracion=duracion;
		}
		string getnombre()
		{
			return nombre;
		}
		string getgenero()
		{
			return genero;
		}
		int getduracion()
		{
			return duracion;
		}
};

class Maraton
{
	private:
	Pelicula* maraton[8];
	public:
		Maraton()
		{
			for(int i=0;i<8;i++)
			{
				maraton[i]=NULL;
			}
		}
	void AgregarPelicula(Pelicula*lista)
	{
		bool encontro=false;
	 for(int i=0;i<8;i++)
	 {
	 	if(maraton[i]==NULL)
	 	{
	 		encontro=true;
	 	   maraton[i]=lista;
			break;	
		 }
		}
		if(encontro==false)
		{
			cout<<"Ya no se pueden añadir peliculas a la lista"<<endl;
			}	
	}
	void BubbleSortDuracion()
	{
		for(int i=0;i<7;i++)
		{
			for(int j= i+1; j<8; j++)
			{
				if(maraton[i]!=NULL && maraton[j]!=NULL && maraton[i]->getduracion()>maraton[j]->getduracion())
				{
				Pelicula*corta =maraton[i];
				maraton[i]=maraton[j];
				maraton[j]=corta;
				}
			}
		}
		cout<<"Ahora la lista esta ordenada por duracion"<<endl;
	}
	void Imprimir()
	{
		cout<<"Este es el orden actual de la lista"<<endl;
		for(int i=0;i<8;i++){
		if(maraton[i]!=NULL)
		{
		    cout<<"Pelicula N°"<<i+1<<endl;
			cout<<"El nombre de la pelicula es: "<<maraton[i]->getnombre()<<endl;
			cout<<"El genero de la pelicula es: "<<maraton[i]->getgenero()<<endl;
			cout<<"La duracion de la pelicula es: "<<maraton[i]->getduracion()<<endl;
			cout<<"--------------------------------------------------------------------------------"<<endl;	
		}
		}
	}
	void ImprimirGeneroEspecifico(string genero)
	{
		for(int i=0;i<8;i++)
		{
			if(maraton[i]!=NULL && maraton[i]->getgenero()==genero)
			{
			cout<<"Pelicula N°"<<i+1<<endl;
			cout<<"El nombre de la pelicula es: "<<maraton[i]->getnombre()<<endl;
			cout<<"El genero de la pelicula es: "<<maraton[i]->getgenero()<<endl;
			cout<<"La duracion de la pelicula es: "<<maraton[i]->getduracion()<<endl;
			cout<<"--------------------------------------------------------------------------------"<<endl;	
			}
		}
	}
	void EliminarDeLaLista(string nombre)
	{
		bool encontro=false;
		for(int i=0;i<8;i++)
		{
			if(maraton[i]!=NULL && maraton[i]->getnombre()==nombre)
			{
				encontro=true;
				maraton[i]=NULL;
				break;
			}
		}
		if(encontro==false)
		{
			cout<<"No se encontro la pelicula a eliminar :("<<endl;
		}
	}
};
int main()
{
	Maraton*maratonDePeliculas= new Maraton();
	Pelicula*p1=new Pelicula("Whiplash", "Musica", 103);
	Pelicula*p2=new Pelicula("La la land","Musica", 127);
	Pelicula*p3=new Pelicula("Fallen Angels","Drama",92);
	Pelicula*p4=new Pelicula("Coraline","Animacion",97);
	Pelicula*p5=new Pelicula("La familia del futuro","Animacion",95);
	Pelicula*p6=new Pelicula("Look Back","Animacion",62);
	Pelicula*p7=new Pelicula("El planeta del tesoro","Animacion",96);
	maratonDePeliculas->AgregarPelicula(p1);
	maratonDePeliculas->AgregarPelicula(p2);
	maratonDePeliculas->AgregarPelicula(p3);
	maratonDePeliculas->AgregarPelicula(p4);
	maratonDePeliculas->AgregarPelicula(p5);
	maratonDePeliculas->AgregarPelicula(p6);
	maratonDePeliculas->AgregarPelicula(p7);
	maratonDePeliculas->Imprimir();
	system("pause");
	system("cls");
	maratonDePeliculas->BubbleSortDuracion();
	maratonDePeliculas->Imprimir();
	system("pause");
	system("cls");
	maratonDePeliculas->ImprimirGeneroEspecifico("Animacion");
	system("pause");
	system("cls");
	maratonDePeliculas->EliminarDeLaLista("Look Back");
	maratonDePeliculas->Imprimir();
}


