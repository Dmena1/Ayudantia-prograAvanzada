#include <iostream>
#include <queue>
#include <vector>
using namespace std;

class GestionSolicitudes {
private:
    queue<string> solicitudes; 
    vector<string> historialAtendidos; 
public:
	GestionSolicitudes()
	{
		
	}
    void agregarSolicitud(string candidato) {
        solicitudes.push(candidato);
        cout << "Solicitud de " << candidato << " añadida a la cola."<< endl;
    }

    void atenderSolicitud() {
        if (solicitudes.empty()==true) {
            cout << "No hay solicitudes pendientes."<< endl;
        } else {
            string atendido = solicitudes.front();
            solicitudes.pop();
            historialAtendidos.push_back(atendido);
            cout << "Solicitud de " << atendido << " atendida."<< endl;
        }
    }

    void mostrarSolicitudesPendientes() {
        if (solicitudes.empty()==true) {
            cout << "No hay solicitudes pendientes."<< endl;
        } else {
            cout << "Solicitudes pendientes:"<< endl;
            queue<string> copiaSolicitudes = solicitudes;
            while (copiaSolicitudes.empty()!=true) {
                cout << "- " << copiaSolicitudes.front() << endl;
                copiaSolicitudes.pop();
            }
        }
    }

    void mostrarHistorialAtendidos() {
    	if (historialAtendidos.empty()) {
        cout << "No se han atendido solicitudes todavía."<< endl;
   	 } else {
        cout << "Historial de candidatos atendidos:"<< endl;
        for (int i = 0; i < historialAtendidos.size(); i++) {
            cout << "- " << historialAtendidos[i] << endl;
        }
    }
}
};

int main() {
    GestionSolicitudes* sistema= new GestionSolicitudes();
    int opcion;

    while (true) {
        cout << "Sistema de Gestión de Solicitudes de Empleo "<< endl;
        cout << "1. Añadir solicitud de empleo"<< endl;
        cout << "2. Atender solicitud de empleo"<< endl;
        cout << "3. Mostrar solicitudes pendientes"<< endl;
        cout << "4. Mostrar historial de candidatos atendidos"<< endl;
        cout << "Otro numero para salir"<< endl;
        cin >> opcion;

        if (opcion == 1) {
            string candidato;
            cout << "Ingresa el nombre del candidato: "<< endl;
            cin >> candidato;
            sistema->agregarSolicitud(candidato);
        } 
        else if (opcion == 2) {
            sistema->atenderSolicitud();
        } 
        else if (opcion == 3) {
            sistema->mostrarSolicitudesPendientes();
        } 
        else if (opcion == 4) {
            sistema->mostrarHistorialAtendidos();
        } 
        else if (opcion >= 5) {
            cout << "Saliendo del programa."<< endl;
            break;
        } 
        
    }
}

