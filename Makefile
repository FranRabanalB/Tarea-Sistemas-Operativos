TARGET = carrera #nombre del archivo

#se especifica el tipo de compilador en este caso: compilador GNU g++ std=c++11
CXX = g++
CXXFLAGS = -std=c++11 -Wall -pthread

# Archivo.cpp
SRC = carrera.cpp

# Tarea general de Makefile
all: $(TARGET)

# Tarea de ejecutar el prgrama carrera
$(TARGET): $(SRC)
        $(CXX) $(CXXFLAGS) -o $(TARGET) $(SRC)

# Tarea principal de makefile de ejecutar el archivo  con los parametros de la >
run:
        ./$(TARGET) 100 3
