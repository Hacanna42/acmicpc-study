// 백준: 별 찍기 10
// https://www.acmicpc.net/problem/2447
// 2024-01-07

#include <iostream>
void printPattern(int i, int j, int n) {
    if ((i / n) % 3 == 1 && (j / n) % 3 == 1) {
        std::cout << " ";
    } else if (n / 3 == 0)
        std::cout << "*";
    else
        printPattern(i, j, n / 3);
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            printPattern(i, j, N);
        }
        std::cout << "\n";
    }
    return 0;
}