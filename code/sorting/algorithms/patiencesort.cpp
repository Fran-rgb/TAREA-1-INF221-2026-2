/*
 * Fuente / Referencia: Patience Sorting algorithm (Aldous & Diaconis, 1999)
 * Algoritmo: Patience Sort utilizando min-heap / k-way merge
 */

#include <vector>
#include <algorithm>
#include <queue>

void patienceSort(std::vector<int>& arr) {
    if (arr.empty()) return;

    std::vector<std::vector<int>> piles;

    for (int x : arr) {
        // Buscar la primera pila cuya carta superior sea >= x
        auto it = std::lower_bound(piles.begin(), piles.end(), x,
            [](const std::vector<int>& pile, int val) {
                return pile.back() < val;
            });

        if (it == piles.end()) {
            piles.push_back({x});
        } else {
            it->push_back(x);
        }
    }

    // Min-heap para realizar la fusión k-way de las pilas
    using Element = std::pair<int, std::pair<int, int>>; // {valor, {pila_idx, elem_idx}}
    std::priority_queue<Element, std::vector<Element>, std::greater<Element>> pq;

    for (size_t i = 0; i < piles.size(); ++i) {
        pq.push({piles[i].back(), {i, piles[i].size() - 1}});
    }

    int idx = 0;
    while (!pq.empty()) {
        auto [val, pos] = pq.top();
        pq.pop();
        
        arr[idx++] = val;
        
        int pile_idx = pos.first;
        int elem_idx = pos.second;

        if (elem_idx > 0) {
            pq.push({piles[pile_idx][elem_idx - 1], {pile_idx, elem_idx - 1}});
        }
    }
}