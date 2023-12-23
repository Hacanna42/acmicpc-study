// 백준: 삼각형과 세 변
// https://www.acmicpc.net/problem/5073
// 2023-12-23

#include <iostream>
int main() {
    while (true) {
        int a, b, c, max, sum;
        std::cin >> a >> b >> c;
        max = std::max(std::max(a, b), c);
        sum = a + b + c;
        if (a + b + c == 0)
            break;
        else {
            if (a == b && b == c)
                std::cout << "Equilateral" << std::endl;
            else if (sum - max <= max)
                std::cout << "Invalid" << std::endl;
            else if (a != b && a != c && b != c)
                std::cout << "Scalene" << std::endl;
            else
                std::cout << "Isosceles" << std::endl;
        }
    }
    return 0;
}