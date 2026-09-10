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
#include <algorithm>
#include <sys/resource.h>

// Incluir las implementaciones de los algoritmos
#include "algorithms/mergesort.cpp"
#include "algorithms/patiencesort.cpp"
#include "algorithms/quicksort.cpp"
#include "algorithms/sort.cpp"

// Obtener el uso máximo de memoria en KB (Peak RSS)
long getPeakMemoryUsageKB() {
    struct rusage usage;
    getrusage(RUSAGE_SELF, &usage);
    return usage.ru_maxrss;
}

// Función auxiliar para leer un arreglo desde un archivo txt
std::vector<int> readArrayFromFile(const std::string& filepath) {
    std::ifstream archivo(filepath);
    std::vector<int> arr;
    if (!archivo.is_open()) {
        return arr;
    }
    int val;
    while (archivo >> val) {
        arr.push_back(val);
    }
    archivo.close();
    return arr;
}

//función auxiliar para escribir un arreglo en un archivo txt
void writeArrayToFile(const std::string& filepath, const std::vector<int>& arr) {
    std::ofstream archivo(filepath);
    for (const auto& val : arr) {
        archivo << val << " ";
    }
    archivo << "\n";
    archivo.close();
}

int main() {

    std::vector<std::string> Ns = {"10", "1000", "100000", "10000000"};
    std::vector<std::string> Ts = {"ascendente", "descendente", "aleatorio"};
    std::vector<std::string> Ds = {"D1", "D7"};
    std::vector<std::string> Ms = {"a", "b", "c"};

    std::ofstream output("data/measurements/results.csv");
    if (!output.is_open()) {
        std::cerr << "Error: No se pudo crear el archivo de mediciones." << std::endl;
        return 1;
    }

    // Cabecera del archivo CSV
    output << "algorithm,n,type,domain,sample,time_ms,memory_kb\n";

    std::cout << "Iniciando mediciones de Ordenamiento..." << std::endl;

    for (const auto& n : Ns) {
        for (const auto& t : Ts) {
            for (const auto& d : Ds) {
                for (const auto& m : Ms) {
                    std::string input_path = "data/array_input/" + n + "_" + t + "_" + d + "_" + m + ".txt";
                    std::vector<int> original_arr = readArrayFromFile(input_path);

                    if (original_arr.empty()) {
                        std::cerr << "Advertencia: Archivo no encontrado o vacio: " << input_path << std::endl;
                        continue;
                    }

                    // --- 1. MERGE SORT ---
                    {
                        std::vector<int> arr = original_arr;
                        long mem_before = getPeakMemoryUsageKB();
                        
                        auto start = std::chrono::high_resolution_clock::now();
                        mergeSort(arr, 0, static_cast<int>(arr.size()) - 1);
                        auto end = std::chrono::high_resolution_clock::now();
                        
                        double time_ms = std::chrono::duration<double, std::milli>(end - start).count();
                        long mem_after = getPeakMemoryUsageKB();

                        writeArrayToFile("data/array_output/merge_" + n + "_" + t + "_" + d + "_" + m + ".txt", arr);
                        output << "MergeSort," << n << "," << t << "," << d << "," << m << "," 
                               << time_ms << "," << (mem_after - mem_before) << "\n";
                    }

                    // --- 2. QUICK SORT ---
                    {
                        if (!(n == "10000000" && (t == "ascendente" || t == "descendente"))) {
                            std::vector<int> arr = original_arr;
                            long mem_before = getPeakMemoryUsageKB();

                            auto start = std::chrono::high_resolution_clock::now();
                            quickSort(arr, 0, static_cast<int>(arr.size()) - 1);
                            auto end = std::chrono::high_resolution_clock::now();

                            double time_ms = std::chrono::duration<double, std::milli>(end - start).count();
                            long mem_after = getPeakMemoryUsageKB();

                            writeArrayToFile("data/array_output/quick_" + n + "_" + t + "_" + d + "_" + m + ".txt", arr);
                            output << "QuickSort," << n << "," << t << "," << d << "," << m << "," << time_ms << "," << (mem_after - mem_before) << "\n";
                        }
                    }
                    
                    // --- 3. PATIENCE SORT ---
                    {
                        std::vector<int> arr = original_arr;
                        long mem_before = getPeakMemoryUsageKB();

                        auto start = std::chrono::high_resolution_clock::now();
                        patienceSort(arr);
                        auto end = std::chrono::high_resolution_clock::now();

                        double time_ms = std::chrono::duration<double, std::milli>(end - start).count();
                        long mem_after = getPeakMemoryUsageKB();

                        writeArrayToFile("data/array_output/patience_" + n + "_" + t + "_" + d + "_" + m + ".txt", arr);
                        output << "PatienceSort," << n << "," << t << "," << d << "," << m << "," << time_ms << "," << (mem_after - mem_before) << "\n";
                    }

                    // --- 4. STD::SORT ---
                    {
                        std::vector<int> arr = original_arr;
                        long mem_before = getPeakMemoryUsageKB();

                        auto start = std::chrono::high_resolution_clock::now();
                        sortArray(arr);
                        auto end = std::chrono::high_resolution_clock::now();

                        double time_ms = std::chrono::duration<double, std::milli>(end - start).count();
                        long mem_after = getPeakMemoryUsageKB();

                        writeArrayToFile("data/array_output/std_" + n + "_" + t + "_" + d + "_" + m + ".txt", arr);
                        output << "StdSort," << n << "," << t << "," << d << "," << m << "," << time_ms << "," << (mem_after - mem_before) << "\n";
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