// 백준: 분산처리
// https://www.acmicpc.net/problem/1009
// 2024-02-11

#include <cmath>
#include <iostream>

long long powMod(long long a, long long b, long long m) {
    if (b == 0)
        return 1;
    long long half = powMod(a, b / 2, m);
    long long result = (half * half) % m;
    if (b % 2 == 1)
        result = (result * a) % m;
    return result;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        long long a, b;
        std::cin >> a >> b;
        int result = powMod(a, b, 10);
        if (result == 0)
            result = 10;
        std::cout << result << "\n";
    }
    return 0;
}