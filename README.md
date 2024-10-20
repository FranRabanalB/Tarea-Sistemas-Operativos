# Tarea-Sistemas-Operativos
## Simulador de Carrera de Autos Francisca Rabanal y Gabriel Vigueras.

### Descripción

Este programa simula una carrera de autos utilizando programación multihebras en C++ en el sistema Linux. Cada automóvil compite en una hebra distinta y avanza una distancia aleatoria en intervalos de tiempo también aleatorios. El programa muestra el progreso de cada auto en tiempo real y, al finalizar la carrera, muestra el orden de llegada.

> [!IMPORTANT]
> **Requisitos**
> - Sistema operativo Linux
> - Compilador GNU g++ con soporte para C++11 o superior
> - Biblioteca estándar de hebras de C++ (thread)

### Instrucciones de Compilación y Ejecución
1. Uso de Makefile
   - Para esta tarea se necesita compilar el archivo c++ con un archivo Makefile para automatizar el proceso de compilación de nuestro programa
   - Compilar con el comando:
```cpp
 make
```
   - Finalmente ejecutar
```cpp
./carrera <distancia> <Numero de autos>
```
  


