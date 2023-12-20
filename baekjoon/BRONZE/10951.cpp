// 백준: A+B - 4
// https://www.acmicpc.net/problem/10951
// 2023-12-02

#include <iostream>
int main() {
    while (true) {
        int a, b;
        std::cin >> a >> b;
        if (std::cin.eof()) break;
        std::cout << a + b << std::endl;
    }
    return 0;
}