// 백준: 과제 안 내신 분..?
// https://www.acmicpc.net/problem/5597
// 2023-12-08

#include <iostream>
int main() {
    int arr[30] = {0};
    for (int i = 0; i < 28; i++) {
        int n;
        std::cin >> n;
        arr[n - 1] = 1;
    }

    for (int i = 0; i < 30; i++) {
        if (arr[i] == 0) {
            std::cout << i + 1 << std::endl;
        }
    }
    return 0;
}