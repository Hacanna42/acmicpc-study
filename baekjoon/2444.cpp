// 백준: 별 찍기 - 7
// https://www.acmicpc.net/problem/2444
// 2023-11-14

#include <iostream>

int main() {
    int count = 0;
    std::cin >> count;

    // 위 삼각형
    for (int i = 0; i < count; i++) {
        for (int j = i; j < count - 1; j++) {
            std::cout << " ";
        }
        for (int j = 0; j < i + 1; j++) {
            std::cout << "*";
        }
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }

    // 아래 역삼각형
    for (int i = count - 1; i >= 0; i--) {
        for (int j = i; j < count; j++) {
            std::cout << " ";
        }

        for (int j = 0; j < i - 1; j++) {
            std::cout << "*";
        }
        for (int j = 0; j < i; j++) {
            std::cout << "*";
        }
        std::cout << std::endl;
    }
}