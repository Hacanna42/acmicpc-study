// 백준: 베르트랑 공준
// https://www.acmicpc.net/problem/4948
// 2024-01-03

#include <iostream>

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
    long a;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    while (true) {
        std::cin >> a;
        long count = 0;
        if (a != 0) {
            for (long i = a + 1; i <= a * 2; ++i) {
                if (isPrime(i)) ++count;
            }
            std::cout << count << "\n";
        } else
            break;
    }

    return 0;
}