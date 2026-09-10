Autor: Franco Antonio Guerrero Gómez
Rol: 202473628-0

# TAREA 1 INF221 2026-2

## Estructura del Repositorio

Este directorio contiene las implementaciones en C++ de los algoritmos de multiplicación de matrices y ordenamiento de arreglos, los scripts para la automatización de ejecuciones y mediciones, los programas en Python para generación de instancias y gráficos, así como las fuentes bibliográficas utilizadas.

A continuación, se describe la estructura del repositorio:

```bash
├── code
├── report
└── README.md
```

### `code`
Contiene los archivos que conforman la entrega de la tarea. En ella, se implementaron los algoritmos solicitados, la generacion de instancias para usarlos, los algoritmos que los utilizan y miden los tiempos de ejecucion y memoria respectivamente usados. También se incluye la generacion de graficos comparativos a partir de la recolección de datos.

### `report`
En esta carpeta se encuentra el informe realizado sobre la Tarea en formato latex, donde el documento "report.pdf" es generado a partir de la jerarquia de archivos .tex presente en la carpeta.

## Instrucciones para compilar

### Requisitos del sistema

Sistema Operativo: Linux / WSL.
Compilador C++: g++ con soporte para C++17.
Python: Python 3.8+ con los paquetes de:
pip install numpy pandas matplotlib seaborn

### Pasos a seguir

Primero se deben generar las instancias de arreglos y matrices, para ello, desde 'code/' usar los comandos: 'python3 sorting/scripts/array_generator.py' y 'python3 matrix_multiplication/scripts/matrix_generator.py'.

Luego, podemos compilar todo desde el makefile de 'code/' usando el comando 'make' y luego ejecutar usando el comando 'make run-all', si se quierer limpiar los ejecutables usar el comando 'make clean'.

Por último, para la generación de graficos comparativos, usaremos los comandos 'python3 sorting/scripts/plot_generator.py', 'python3 matrix_multiplication/scripts/plot_generator.py'

## Referencias Bibliográficas

1. **Cormen, T. H., Leiserson, C. E., Rivest, R. L., & Stein, C.** (2022). *Introduction to Algorithms* (4th ed.). MIT Press. (Merge Sort, Quick Sort, Naive Matrix Multiplication y Strassen Algorithm).
2. **Aldous, D., & Diaconis, P.** (1999). Longest increasing subsequences: From patience sorting to the Baik-Deift-Johansson theorem. *Bulletin of the American Mathematical Society*, 36(4), 413-432. (Patience Sort).
3. **Musser, D. R.** (1997). Introspective sorting and selection algorithms. *Software: Practice and Experience*, 27(8), 983-993. (`std::sort` / Introsort).
4. **Strassen, V.** (1969). Gaussian elimination is not optimal. *Numerische Mathematik*, 13(4), 354-356. (Algoritmo de Strassen).