// 백준: 팩토리얼
// https://www.acmicpc.net/problem/10872
// 2024-01-05

#include <iostream>
int factorial(int n) {
    if (n <= 1) {
        return 1;
    }
    return n * factorial(n - 1);
}
int main() {
    int N;
    std::cin >> N;
    std::cout << factorial(N);
    return 0;
}