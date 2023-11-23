// 백준: A/B
// https://www.acmicpc.net/problem/1008
// 2023-11-23

#include <iomanip>
#include <iostream>
int main() {
    double a, b;
    std::cin >> a >> b;
    std::cout << std::fixed << std::setprecision(9) << a / b;
    return 0;
}