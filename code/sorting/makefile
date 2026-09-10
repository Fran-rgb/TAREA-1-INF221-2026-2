# Compilador y banderas
CXX = g++
CXXFLAGS = -std=c++17 -O2 -Wall

# Nombre del ejecutable
TARGET = sorting.exe

# Archivo fuente
SRC = sorting.cpp

# Regla principal
all: $(TARGET)

$(TARGET): $(SRC)
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

# Regla para ejecutar la medición de ordenamiento
run: $(TARGET)
	./$(TARGET)

# Limpieza de ejecutable
clean:
	rm -f $(TARGET)

.PHONY: all run clean