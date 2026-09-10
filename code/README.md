Autor: Franco Antonio Guerrero Gómez
Rol: 202473628-0

# Documentación

Este directorio contiene la implementación en C++ de los algoritmos a estudiar, los programas principales para orquestar la ejecución y recolección de mediciones, los scripts de apoyo en Python para generación de entradas y análisis grafico comparativo, y las referencias bibliográficas asociadas a cada algoritmo.

## Entrega

La entrega se realiza vía **aula.usm.cl** en formato `.zip`.

## Multiplicación de Matrices

### Programa Principal
Ubicado en 'matrix_multiplication/' el archivo 'matrix_multiplication.cpp' se encarga de leer las matrices en formato .txt que estan ubicadas en 'matrix_multiplication/data/matrix_input/', para reescribirlas como matrices
formada por vectores que sirvan de entrada para los algoritmos 'naive.cpp' y 'strassen.cpp'.

Se analiza cada caso por separado, escribiendo las matrices resultantes de los algoritmos en la ubicacion 'matrix_multiplication/data/matrix_output/', y midiendo en cada caso el tiempo de ejecucion en milisegundos usando la libreria '<chrono>' y el pico de memoria en KB mediante la funcion 'getrusage()' de lacabecera POSIX '<sys/resource.h>'.

Estos últimos resultados de rendimiento son escritos en el archivo 'results.csv' ubicado en 'matrix_multiplication/data/measurements/'.

### Scripts

Ubicados en 'matrix_multiplication/scripts/', tenemos dos archivos .py, el primero de ellos es 'matrix_generator.py', con el cual se generan las matrices que serviran de entradas para los algoritmos de multiplicación de matrices en formato .txt, segun las dimensiones $n \in \{16, 64, 256, 1024\}$, para los distintos tipos de matriz ('densa', 'diagonal', 'dispersa') y dominios (D0, D10).

El segundo archivo es 'plot_generator.py', el cual se encarga de automatizar el proceso de generar graficos de los resultados experimentales, esto lo hace leyendo los resultados escritos en 'matrix_multiplication/data/measurements/results.csv' para comparar resultados en igualdad de condiciones y generar gráficos comparativos de tiempo de ejecución y memoria utilizada vs la dimensión $n$, guardando estos mismos en formato .png en 'matrix_multiplication/data/plots/'.

## Ordenamiento de Arreglo Unidimensional

### Programa Principal (`sorting.cpp`)

Ubicado en 'sorting/' el archivo 'sorting.cpp' se encarga de leer los arreglos en formato .txt que estan ubicados en 'sorting/data/array_input/', para reescribirlos como un vector que sirvan de entrada para los algoritmos 'mergesort.cpp', 'patiencesort.cpp', 'quicksort.spp' y 'sort.cpp'.

Se analiza cada caso por separado, escribiendo los arreglos resultantes de los algoritmos en la ubicacion 'sorting/data/array_output/', y midiendo en cada caso el tiempo de ejecucion en milisegundos usando la libreria '<chrono>' y el pico de memoria en KB mediante la funcion 'getrusage()' de lacabecera POSIX '<sys/resource.h>'.

Estos últimos resultados de rendimiento son escritos en el archivo 'results.csv' ubicado en 'sorting/data/measurements/'.

### Scripts

Ubicados en 'sorting/scripts/', tenemos dos archivos .py, el primero de ellos es 'array_generator.py', con el cual se generan los arreglos que serviran de entradas para los algoritmos de ordenamiento en formato .txt, segun los tamaños $n \in \{10^1, 10^3, 10^5, 10^7\}$, para los distintos ordenamientos iniciales ('ascendente', 'descendente', 'aleatorio') y dominios (D1, D7).

El segundo archivo es 'plot_generator.py', el cual se encarga de automatizar el proceso de generar graficos de los resultados experimentales, esto lo hace leyendo los resultados escritos en 'sorting/data/measurements/results.csv' para comparar resultados en igualdad de condiciones y generar gráficos comparativos de tiempo de ejecución y memoria utilizada vs el largo $n$, guardando estos mismos en formato .png en 'sorting/data/plots/'.