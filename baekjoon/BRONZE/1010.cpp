// 백준: 다리 놓기
// https://www.acmicpc.net/problem/1010
// 2024-01-05

#include <iostream>

long long binomialCoefficient(int N, int K) {
    long long result = 1;
    for (int i = 1; i <= K; i++) {
        result *= N - (K - i);
        result /= i;
    }
    return result;
}

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        long long K, N;
        std::cin >> K >> N;
        std::cout << binomialCoefficient(N, K) << "\n";
    }
    return 0;
}