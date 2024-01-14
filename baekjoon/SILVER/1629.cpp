// 백준: 곱셈
// https://www.acmicpc.net/problem/1629
// 2024-01-14

#include <iostream>

long long power(long long a, long long b, long long c) {
    if (b == 0) return 1;
    long long val = power(a, b / 2, c);
    val = val * val % c;
    if (b % 2 == 0) return val;
    return val * a % c;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    long long A, B, C;
    std::cin >> A >> B >> C;
    std::cout << power(A, B, C);
    return 0;
}
