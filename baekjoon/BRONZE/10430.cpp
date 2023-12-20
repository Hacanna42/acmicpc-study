// 백준: 나머지
// https://www.acmicpc.net/problem/10430
// 2023-11-24

#include <iostream>
int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    std::cout << (a + b) % c << std::endl
              << ((a % c + b % c)) % c << std::endl
              << (a * b) % c << std::endl
              << ((a % c) * (b % c)) % c;
    return 0;
}