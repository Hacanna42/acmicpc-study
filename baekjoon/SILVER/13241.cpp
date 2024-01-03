// 백준: 최소공배수
// https://www.acmicpc.net/problem/13241
// 2024-01-03

#include <iostream>

// 유클리드 알고리즘
long long gcd(long long a, long long b) {
    if (b == 0) return a;
    long long r = a % b;
    a = b;
    b = r;
    return gcd(a, b);
}

long long lcm(long long a, long long b) { return a / gcd(a, b) * b; }

int main() {
    long long a, b;
    std::cin >> a >> b;
    std::cout << lcm(a, b);
    return 0;
}