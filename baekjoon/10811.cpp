// 백준: 바구니 뒤집기
// https://www.acmicpc.net/problem/10811
// 2023-12-10

#include <iostream>
int main() {
    int n, m;
    std::cin >> n >> m;
    int* array = new int[n];
    // Initiater
    for (int i = 0; i < n; i++) {
        array[i] = i + 1;
    }

    for (int i = 0; i < m; i++) {
        int min, max;
        std::cin >> min >> max;
        int start = min - 1;
        int end = max - 1;
        while (start < end) {
            // 스왑 알고리즘
            int temp = array[start];
            array[start] = array[end];
            array[end] = temp;
            // 인덱스 이동
            start++;
            end--;
        }
    }

    for (int i = 0; i < n; i++) {
        std::cout << array[i] << " ";
    }
    return 0;
}