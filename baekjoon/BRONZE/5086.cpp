// 백준: 배수와 약수
// https://www.acmicpc.net/problem/5086
// 2023-12-22

// 나머지 연산자를 이용하면 쉽게 배수와 약수를 판별할 수 있다.
#include <iostream>
int main() {
    int A, B;
    while (true) {
        std::cin >> A >> B;
        if (A == 0 && B == 0) break;
        if (A % B == 0) {
            std::cout << "multiple" << std::endl;
        } else if (B % A == 0) {
            std::cout << "factor" << std::endl;
        } else
            std::cout << "neither" << std::endl;
    }
    return 0;
}