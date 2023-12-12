// 백준: 평균
// https://www.acmicpc.net/problem/1546
// 2023-12-11

// #include <iomanip>
#include <iostream>
int main() {
    int n = 0;
    float max = 0;
    std::cin >> n;
    float* array = new float[n];

    for (int i = 0; i < n; i++) {
        std::cin >> array[i];
        if (array[i] > max) {
            max = array[i];
        }
    }

    float sum = 0;
    for (int i = 0; i < n; i++) {
        sum += (array[i] / max) * 100;
    }
    // std::cout << std::fixed << std::setprecision(1);
    std::cout << sum / static_cast<float>(n);
    delete[] array;
    return 0;
}