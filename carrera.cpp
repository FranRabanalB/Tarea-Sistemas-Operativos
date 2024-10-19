#include <iostream>
#include <thread>
#include <vector>
#include <cstdlib>
#include <chrono>
#include <mutex>
#include <algorithm>

using namespace std;

// Variables globales
mutex mtx;
vector<pair<int, string>> posiciones;  // Guarda el orden de llegada
int lugar_actual = 1; // Variable que guarda el lugar actual de llegada

// FunciÃ³n que simula el avance de cada auto
void carrera(int id, int distancia_total) {
    int distancia_recorrida = 0;

    while (distancia_recorrida < distancia_total) {
        // Generar distancia y tiempo aleatorios
        int distancia_avance = rand() % 10 + 1;
        int tiempo_espera = rand() % 401 + 100; // entre 100 y 500 ms

        // Actualizar la distancia
        distancia_recorrida += distancia_avance;
        if (distancia_recorrida > distancia_total) {
            distancia_recorrida = distancia_total;
        }

        // Bloquear para mostrar el progreso
        mtx.lock();
        cout << "Auto" << id << " avanza " << distancia_avance << " metros (total: " << distancia_recorrida << " metros)" << endl;
        mtx.unlock();

        // Simular la pausa
        this_thread::sleep_for(chrono::milliseconds(tiempo_espera));
    }

    // Al llegar a la meta, bloquear para actualizar posiciones y mostrar el mensaje de llegada
    mtx.lock();
    cout << "Auto" << id << " avanza " << distancia_recorrida << " metros y termina la carrera en el lugar " << lugar_actual << "!" << endl;
    posiciones.push_back({id, "Auto" + to_string(id)});
    lugar_actual++;
    mtx.unlock();
}

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "Uso: ./carrera <distancia_total> <numero_autos>" << endl;
        return 1;
    }

    int distancia_total = stoi(argv[1]);
    int num_autos = stoi(argv[2]);

    vector<thread> autos;

    // Iniciar la carrera
    for (int i = 0; i < num_autos; ++i) {
        autos.push_back(thread(carrera, i, distancia_total));
    }

    // Esperar a que todos los autos terminen
    for (auto& t : autos) {
        t.join();
    }

    // Mostrar resultados finales
    cout << "\nResultado final:\n";
    cout << "Lugar\tAuto\n";
    cout << "---------------\n";
    for (int i = 0; i < posiciones.size(); ++i) {
        cout << i + 1 << "\t" << posiciones[i].second << endl;
    }
    return 0;
}