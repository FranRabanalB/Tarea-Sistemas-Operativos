# Tarea-Sistemas-Operativos
## Simulador de Carrera de Autos Francisca Rabanal y Gabriel Vigueras.

### Descripción

Este programa simula una carrera de autos utilizando programación multihebras en C++ en el sistema Linux. Cada automóvil compite en una hebra distinta y avanza una distancia aleatoria en intervalos de tiempo también aleatorios. El programa muestra el progreso de cada auto en tiempo real y, al finalizar la carrera, muestra el orden de llegada.

> [!IMPORTANT]
> **Requisitos**
>  - Sistema operativo Linux
> - Compilador GNU g++ con soporte para C++11 o superior
> - Biblioteca estándar de hebras de C++ (<thread>)

### Instrucciones de Compilación y Ejecución
1. Compilacion sin make
   - Para compilar este programa se requiere de un compilador GNU g++ std=c++11 o superior en nuestro sistema Linux
   - luego ejecutar el codigo con el comando g++ carrera.cpp -o carrera (si este no llega a funcionar usar g++ -std=c++11 carrera.cpp -o carrera -pthread)
   - y ejecutar con ejemplo de  ./carrera con ejemplo 100 3

2. Uso de Makefile
   - para esta tarea se necesita compilar el archivo c++ con un archivo Makefile para automatizar el proceso de compilación de nuestro programa
   - compilar con el comando : make
   - ejecutar con: make run (donde se ejecuta ya con parametros por defecto siendo estos 100 metros de distancia y 3 autos que compiten)



