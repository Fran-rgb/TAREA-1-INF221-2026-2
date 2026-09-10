/*
Fuente/Referencia: Cormen et al. - Introduction to Algorithms (CLRS)
Algoritmo: Multiplicación de matrices Naive
*/

#include <vector>

std::vector<std::vector<int>> multiplyNaive(
    const std::vector<std::vector<int>>& A, 
    const std::vector<std::vector<int>>& B, 
    int n) 
{
    std::vector<std::vector<int>> C(n, std::vector<int>(n, 0));
    for (int i = 0; i < n; ++i) {
        for (int k = 0; k < n; ++k) {
            for (int j = 0; j < n; ++j) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}