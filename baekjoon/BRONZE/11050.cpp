// 백준: 이항 계수 1
// https://www.acmicpc.net/problem/11050
// 2024-01-05

#include <iostream>

int factorial(int n) {
    if (n <= 1) return 1;
    return n * factorial(n - 1);
}
int main() {
    int N, M;
    std::cin >> N >> M;
    std::cout << factorial(N) / (factorial(M) * factorial(N - M));
    return 0;
}