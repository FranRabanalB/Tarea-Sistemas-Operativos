#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <mutex>
#include <algorithm>

using namespace std;

// Variables globales
mutex mtx; //Asiga un "Alias" a la libreria mutex
vector<pair<int, string>> posiciones;  // Guarda el orden de llegada a la meta
int lugar_actual = 1; // Variable que guarda la posicion de llegada

// Funcion para que cada auto avance
void carrera(int id, int distancia_total) {
    int distancia_recorrida = 0;

    //Ejecucion mientras la distancia recorrida por el auto sea menor a la distancia total dada, es decir, que el auto siga corriendo.
    while (distancia_recorrida < distancia_total) { 
        // Generar distancia y tiempo aleatorios
        int distancia_avance = rand() % 10 + 1; // Nro aleatorio entre 1 y 10 
        int tiempo_espera = rand() % 401 + 100; // Nro aleatorio entre 100 y 500 ms

        // Actualizar la distancia del auto
        distancia_recorrida += distancia_avance; //se le suma la distancia aleatoria generada a la distancia total recorrida del auto
        
        //Validación para que la distancia total recorrida no sea mayor a la distancia de la carrera
        if (distancia_recorrida > distancia_total) {
            distancia_recorrida = distancia_total;
        }

        // Bloquear para mostrar el progreso
        mtx.lock(); //Bloquea a los otros hilos del programa para darle la prioridad al proceso que ejecute esta linea

        // Imprime cual auto es el que avanza, cuanto se desplaza y la distancia total recorrida.
        cout << "Auto" << id << " avanza " << distancia_avance << " metros (total: " << distancia_recorrida << " metros)" << endl;  
        
        mtx.unlock(); //Desbloquea a los otros hilos para que puedan seguir ejecutandose

        // Simular un cambio de velocidad con un sleep de duracion aleatoria, generada anteriormente, en milisegundos.
        // solo cuando la distancia recorrida sea distinta a la distancia total de la carrera
        if(distancia_recorrida != distancia_total){
            this_thread::sleep_for(chrono::milliseconds(tiempo_espera));
        }
        
    }

    // Cuando el auto llega a la meta.
    mtx.lock(); //Bloquea los demas hilos
    
    // Imprime cual es el auto que avanza, cuanto se desplaza y en que lugar llega a la meta.
    cout << "Auto" << id << " avanza " << distancia_recorrida << " metros y termina la carrera en el lugar " << lugar_actual << "!" << endl;
    
    posiciones.push_back({id, "Auto " + to_string(id)}); //Agrega al vector posiciones la id y el nombre del auto.
    lugar_actual++; //Aumenta en 1 la posicion que obtendra el siguiente auto que cruce la meta.
    mtx.unlock(); //Desbloquea los demas hilos
}

int main(int argc, char* argv[]) {

    //Validacion que se asegura de que los augumentos escritos en la ejecucion sean los necesarios
    if (argc != 3) {
        //En el caso de no ser los necesarios, Imprime el uso del programa
        cout << "Uso: ./carrera <distancia_total> <numero_autos>" << endl; 
        return 1;
    }


    int distancia_total = stoi(argv[1]); //Se le asigna el 2do argumento a la distancia total
    int num_autos = stoi(argv[2]); // Se le asigna el 3er argumento a la cantidad de autos en la carrera

    vector<thread> autos; //Declara un vector llamado autos que almacenará hilos independientes.

    // Iniciar la carrera
    for (int i = 0; i < num_autos; ++i) {
        // Se agrega al vector autos un thread por cada repeticion del ciclo for.
        autos.push_back(thread(carrera, i, distancia_total)); //el argumento "thread(carrera, i, distancia_total)"
        //crea un hilo que ejecuta la funcion carrera que utiliza "i" y "distancia_total" como parametros para la función "carrera".
    }

    // Esperar a que todos los autos terminen
    for (auto& t : autos) {
        t.join(); // Espera a que todos los hilos dentro del vector autos finalicen.
    }

    // Mostrar resultados finales
    cout << "\nResultado final:\n";
    cout << "Lugar\tAuto\n";
    cout << "---------------\n";
    for (int i = 0; i < posiciones.size(); ++i) {
        //Imprime la posicion de llegada a la meta de cada auto
        cout << i + 1 << "\t" << posiciones[i].second << endl; //"posiciones[i].second" indica el segundo valor del vector posiciones
                                                               //en este caso el nombre del auto (ej: 1  Auto 0)

    }
    return 0;
}