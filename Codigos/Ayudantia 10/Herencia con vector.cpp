#include <iostream>
#include <vector>
using namespace std;

class Libro {
protected:
    int codigo;
    string titulo;
    string autor;
    int anho;

public:
    
    Libro(int codigo, string titulo, string autor, int anho) {
        this->codigo = codigo;
        this->titulo = titulo;
        this->autor = autor;
        this->anho = anho;
    }

    virtual void imprimir() {
        cout << "LIBRO " << codigo << " " << titulo << " " << autor << " " << anho << endl;
    }
};

class Novela : public Libro {
protected:
    string genero;

public:
  
    Novela(int codigo, string titulo, string autor, int anho, string genero) :Libro(codigo,titulo,autor, anho)
    {
        this->genero = genero;
    }

    void imprimir() {
        cout << "NOVELA " << codigo << " " << titulo << " " << autor << " " << anho << " " << genero << endl;
    }
};

class CienciaFiccion : public Novela {
private:
    string universo;

public:

    CienciaFiccion(int codigo, string titulo, string autor, int anho, string genero, string universo) : Novela(codigo, titulo, autor, anho, genero) {
        this->universo = universo;
    }

    void imprimir() {
        cout << "CIENCIA FICCION " << codigo << " " << titulo << " " << autor << " " << anho << " "
             << genero << " " << universo << endl;
    }
};

class Historia : public Libro {
private:
    string periodo;

public:
    Historia(int codigo, string titulo, string autor, int anho, string periodo) : Libro(codigo, titulo, autor, anho) {
        this->periodo = periodo;
    }

    void imprimir() {
        cout << "HISTORIA " << codigo << " " << titulo << " " << autor << " " << anho << " " << periodo << endl;
    }
};

class Biblioteca {
private:
    vector<Libro*> listaLibros;
    int maxLibros;

public:
    Biblioteca(int maxLibros) {
        this->maxLibros = maxLibros;
    }

    void agregarLibro(Libro* libro) {
        if (listaLibros.size() == maxLibros) {
            cout << "No se puede agregar, límite alcanzado." << endl;
        } else {
            listaLibros.push_back(libro);
            cout << "Libro agregado." << endl;
        }
    }

    void imprimir() {
        for (int i = 0; i < listaLibros.size(); i++) {
            listaLibros[i]->imprimir();
        }
    }
};

int main() {
    Biblioteca* biblioteca = new Biblioteca(5);
    Historia* libro1 = new Historia(1, "Historia de la Segunda Guerra", "John Doe", 2005, "Siglo XX");
    CienciaFiccion* libro2 = new CienciaFiccion(2, "Viaje a Marte", "Jane Doe", 2020, "Ciencia Ficción", "Marte");
    Novela* libro3 = new Novela(3, "El Gran Gatsby", "F. Scott Fitzgerald", 1925, "Literatura Clásica");
    Historia* libro4 = new Historia(4, "La Revolución Francesa", "Victor Hugo", 1840, "Siglo XVIII");
    
    biblioteca->agregarLibro(libro1);
    biblioteca->agregarLibro(libro2);
    biblioteca->agregarLibro(libro3);
    biblioteca->agregarLibro(libro4);

    biblioteca->imprimir();

}

