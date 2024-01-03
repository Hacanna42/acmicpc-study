// 백준: 최소공배수
// https://www.acmicpc.net/problem/1934
// 2024-01-03

#include <iostream>

// 유클리드 알고리즘
int gcd(int a, int b) {
    if (b == 0) return a;
    int r = a % b;
    a = b;
    b = r;
    return gcd(a, b);
}

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int a, b;
        std::cin >> a >> b;
        std::cout << lcm(a, b) << "\n";
    }
    return 0;
}