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
    std::cou.tie(nullptr);
    int T;
    std::cin >> T;
    for (int i = 0; i < T; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::cout << pow_mod(a, b, 10) << "\n";
    }
    return 0;
}