# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

# Nombre del ejecutable
TARGET = matrix.exe

# Archivo fuente
SRC = matrix_multiplication.cpp

# Regla principal
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Regla para ejecutar la medición de matrices
run: $(TARGET)
	./$(TARGET)

# Limpieza de ejecutable
clean:
	rm -f $(TARGET)

.PHONY: all run clean