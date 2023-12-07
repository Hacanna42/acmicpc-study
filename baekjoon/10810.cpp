// 백준: 공 넣기
// https://www.acmicpc.net/problem/10810
// 2023-12-06

#include <iostream>
int main() {
    int n, m;
    std::cin >> n >> m;
    int* arr = new int[n];
    for (int i = 0; i < m; i++) {
        int q, w, e;
        std::cin >> q >> w >> e;
        for (int j = q - 1; j < w; j++) {
            arr[j] = e;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}