// 백준: 피보나치 수 5
// https://www.acmicpc.net/problem/10870
// 2024-01-07

#include <iostream>

int fibonaci(int n) {
    if (n == 0) return 0;
    if (n == 1) return 1;
    return fibonaci(n - 1) + fibonaci(n - 2);
}

int main() {
    int N;
    std::cin >> N;
    std::cout << fibonaci(N);
    return 0;
}