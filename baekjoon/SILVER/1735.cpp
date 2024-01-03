// 백준: 분수 합
// https://www.acmicpc.net/problem/1735
// 2024-01-03

#include <iostream>

// 유클리드 알고리즘
long gcd(long a, long b) {
    if (b == 0) return a;
    long r = a % b;
    a = b;
    b = r;
    return gcd(a, b);
}

long lcm(long a, long b) { return a / gcd(a, b) * b; }

int main() {
    long a, b, c, d;
    std::cin >> a >> b >> c >> d;
    long child = (a * d) + (c * b);
    long mother = b * d;
    long _gcd = gcd(child, mother);
    std::cout << child / _gcd << " " << mother / _gcd;

    return 0;
}