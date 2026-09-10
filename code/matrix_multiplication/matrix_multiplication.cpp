/*
 * Referencias y Fuentes:
 * - Medición de tiempo: <chrono> de C++11.
 * - Medición de memoria: sys/resource.h (getrusage - POSIX/Linux).
 * - Algoritmos incluidos desde la carpeta 'algorithms/'.
 */

#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include <chrono>
#include <sys/resource.h>

// algoritmos
#include "algorithms/naive.cpp"
#include "algorithms/strassen.cpp"

// Obtener el uso máximo de memoria en KB (Peak RSS)
long getPeakMemoryUsageKB() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

// Función auxiliar para escribir una matriz en un archivo txt
void writeMatrixToFile(const std::string& filepath, const std::vector<std::vector<int>>& matrix) {
    std::ofstream archivo(filepath);
    for (const auto& row : matrix) {
        for (const auto& val : row) {
            archivo << val << " ";
        }
        archivo << "\n";
    }
    archivo.close();
}

// Función auxiliar para cargar una matriz desde un archivo txt
std::vector<std::vector<int>> readMatrixFromFile(const std::string& filepath, int n) {
    std::ifstream archivo(filepath);
    std::vector<std::vector<int>> matrix(n, std::vector<int>(n, 0));
    
    if (!archivo.is_open()) {
        return {};
    }

    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j) {
            if (!(archivo >> matrix[i][j])) {
                break;
            }
        }
    }
    archivo.close();
    return matrix;
}

int main() {
    std::vector<int> Ns = {16, 64, 256, 1024};
    std::vector<std::string> Ts = {"dispersa", "diagonal", "densa"};
    std::vector<std::string> Ds = {"D0", "D10"};
    std::vector<std::string> Ms = {"a", "b", "c"};

    std::ofstream output("data/measurements/results.csv");
    if (!output.is_open()) {
        std::cerr << "Error: No se pudo crear el archivo de mediciones." << std::endl;
        return 1;
    }

    // Cabecera del archivo CSV
    output << "algorithm,n,type,domain,sample,time_ms,memory_kb\n";

    std::cout << "Iniciando mediciones de multiplicacion de Matrices..." << std::endl;

    for (int n : Ns) {
        std::string n_str = std::to_string(n);
        for (const auto& t : Ts) {
            for (const auto& d : Ds) {
                for (const auto& m : Ms) {
                    
                    std::string path_m1 = "data/matrix_input/" + n_str + "_" + t + "_" + d + "_" + m + "_1.txt";
                    std::string path_m2 = "data/matrix_input/" + n_str + "_" + t + "_" + d + "_" + m + "_2.txt";

                    auto A = readMatrixFromFile(path_m1, n);
                    auto B = readMatrixFromFile(path_m2, n);

                    if (A.empty() || B.empty()) {
                        std::cerr << "Advertencia: Archivo no encontrado o incompleto: " << path_m1 << std::endl;
                        continue;
                    }

                    // --- 1. NAIVE MULTIPLICATION ---
                    {
                        long mem_before = getPeakMemoryUsageKB();
                        auto start = std::chrono::high_resolution_clock::now();
                        
                        auto C_naive = multiplyNaive(A, B, n);
                        
                        auto end = std::chrono::high_resolution_clock::now();
                        long mem_after = getPeakMemoryUsageKB();

                        double time_ms = std::chrono::duration<double, std::milli>(end - start).count();

                        writeMatrixToFile("data/matrix_output/naive_" + n_str + "_" + t + "_" + d + "_" + m + ".txt", C_naive);
                        output << "Naive," << n << "," << t << "," << d << "," << m << "," << time_ms << "," << (mem_after - mem_before) << "\n";
                    }

                    // --- 2. STRASSEN MULTIPLICATION ---
                    {
                        long mem_before = getPeakMemoryUsageKB();
                        auto start = std::chrono::high_resolution_clock::now();
                        
                        auto C_strassen = strassen(A, B, n);
                        
                        auto end = std::chrono::high_resolution_clock::now();
                        long mem_after = getPeakMemoryUsageKB();

                        double time_ms = std::chrono::duration<double, std::milli>(end - start).count();

                        writeMatrixToFile("data/matrix_output/strassen_" + n_str + "_" + t + "_" + d + "_" + m + ".txt", C_strassen);
                        output << "Strassen," << n << "," << t << "," << d << "," << m << "," << time_ms << "," << (mem_after - mem_before) << "\n";
                    }

                }
            }
        }
        std::cout << "Mediciones finalizadas para n = " << n << std::endl;
    }

    output.close();
    std::cout << "Proceso finalizado." << std::endl;
    return 0;
}