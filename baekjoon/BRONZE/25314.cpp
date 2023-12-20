// 백준: 코딩은 체육과목 입니다
// https://www.acmicpc.net/problem/25314
// 2023-11-30

#include <iostream>
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n / 4; i++) {
        std::cout << "long ";
    }
    std::cout << "int";
    return 0;
}