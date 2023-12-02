// 백준: 2439
// https://www.acmicpc.net/problem/2439
// 2023-12-02

#include <iostream>
int main() {
    int n;
    std::cin >> n;
    for (int i = n; i > 0; i--) {
        for (int j = 1; j < i; j++) {
            std::cout << " ";
        }
        for (int j = 0; j <= n - i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
    return 0;
}