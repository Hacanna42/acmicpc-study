// 백준: 수 정렬하기 2(without STL)
// https://www.acmicpc.net/problem/2751
// 2024-01-02

#include <algorithm>
#include <iostream>
#include <vector>

void quickSort(std::vector<int>& arr, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 1.8;
        int pivot = arr[mid];
        int pL = low - 1;
        int pR = high + 1;
        // 교차까지 정렬하며 분할
        while (true) {
            do {
                pL++;
            } while (arr[pL] < pivot);
            do {
                pR--;
            } while (arr[pR] > pivot);

            if (pL >= pR) break;

            std::swap(arr[pL], arr[pR]);
        }

        // 분할된 값을 갖고 재귀 실행
        quickSort(arr, low, pR);
        quickSort(arr, pR + 1, high);
    }
}

int main() {
    std::vector<int> v;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int t;
        std::cin >> t;
        v.push_back(t);
    }
    quickSort(v, 0, v.size() - 1);
    for (size_t i = 0; i < v.size(); ++i) {
        std::cout << v[i] << "\n";
    }
    return 0;
}