// 백준: 소수 구하기
// https://www.acmicpc.net/problem/1929
// 2024-01-03

#include <iostream>

bool isPrime(int n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (int i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }

    return true;
}

int main() {
    int a, b;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> a >> b;
    for (int i = a; i <= b; ++i) {
        if (isPrime(i)) std::cout << i << "\n";
    }
    return 0;
}