Autor: Franco Antonio Guerrero Gómez
Rol: 202473628-0

# AlgoReportTemplate

## Descripción

Este repositorio contiene el mini-informe correspondiente a la Tarea 1 de la asignatura Algoritmos y Complejidad del Departamento de Informática de la USM San Joaquin y el código latex que lo conforma. 

### Estructura del Repositorio

```bash
.
├── author.tex
├── preamble.tex
├── README.md
├── references.bib
├── report.pdf
├── report.tex
└── sections
    ├── abstract.tex
    ├── appendix1.tex
    ├── conclusions.tex
    ├── experiment_intro.tex
    ├── experiment_results.tex
    ├── implementations.tex
    └── introduccion.tex

2 directories, 13 files

```

## Instrucciones de Compilación

El informe fue desarrollado y probado utilizando WSL (Windows Subsystem for Linux) con la distribución texlive-full.

Para compilar y generar correctamente el archivo report.pdf a partir de los archivos .tex prensentes en el repositorio, se debe ejecutar el comando 'pdflatex report.tex' desde la direccion 'report/' con la distribución texlive-full instalada previamente.