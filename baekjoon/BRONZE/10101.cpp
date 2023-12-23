// 백준: 삼각형 외우기
// https://www.acmicpc.net/problem/10101
// 2023-12-23

#include <iostream>
int main() {
    int a, b, c;
    std::cin >> a >> b >> c;
    int sum = a + b + c;
    if (sum == 180) {
        if (a == b && b == c)
            std::cout << "Equilateral";
        else if (a != b && b != c && a != c)
            std::cout << "Scalene";
        else
            std::cout << "Isosceles";
    } else
        std::cout << "Error";
    return 0;
}