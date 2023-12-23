// 백준: 세 막대
// https://www.acmicpc.net/problem/14215
// 2023-12-23

#include <iostream>
int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int sum = a + b + c;
    int max = std::max(std::max(a, b), c);
    if (sum - max <= max) sum += sum - (max * 2) - 1;
    std::cout << sum;
    return 0;
}