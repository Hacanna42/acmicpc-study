// 백준: 팩토리얼 2
// https://www.acmicpc.net/problem/27433
// 2024-01-07

#include <iostream>

long recursive(int n) {
    if (n <= 1) return 1;
    return n * recursive(n - 1);
}

int main() {
    int N;
    std::cin >> N;
    std::cout << recursive(N);
    return 0;
}