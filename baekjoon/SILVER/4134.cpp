// 백준: 다음 소수
// https://www.acmicpc.net/problem/4134
// 2024-01-03

#include <cmath>
#include <iostream>

/*
모든 소수는 6k ± 1이다.
따라서, 각 i에 대해 i와 i+2를 확인하면
모든 소수를 가장 효율적으로 파악할 수 있다.
*/
bool isPrime(long n) {
    if (n <= 1) return false;
    if (n <= 3) return true;
    if (n % 2 == 0 || n % 3 == 0) return false;
    for (long i = 5; i * i <= n; i += 6) {
        if (n % i == 0 || n % (i + 2) == 0) return false;
    }
    return true;
}

int main() {
    long N;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N;
    for (long i = 0; i < N; ++i) {
        long temp;
        std::cin >> temp;
        while (true) {
            if (isPrime(temp)) break;
            ++temp;
        }
        std::cout << temp << "\n";
    }
    return 0;
}