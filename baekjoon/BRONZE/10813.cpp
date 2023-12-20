// 백준: 공 바꾸기
// https://www.acmicpc.net/problem/10813
// 2023-12-07

#include <iostream>
int main() {
    int n, m;
    std::cin >> n >> m;
    int* arr = new int[n];
    for (int i = 0; i < n; i++) {
        arr[i] = i + 1;
    }
    for (int i = 1; i < m + 1; i++) {
        int q, w;
        std::cin >> q >> w;
        int temp = arr[w - 1];
        arr[w - 1] = arr[q - 1];
        arr[q - 1] = temp;
    }

    for (int i = 0; i < n; i++) {
        std::cout << arr[i] << " ";
    }
    delete[] arr;
    return 0;
}