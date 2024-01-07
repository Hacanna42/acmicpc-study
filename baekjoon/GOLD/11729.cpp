// 백준: 하노이 탑 이동 순서
// https://www.acmicpc.net/problem/11729
// 2024-01-07

#include <iostream>

void hanoi(int n, int start, int to, int bypass) {
    if (n == 1)
        std::cout << start << " " << to << "\n";
    else {
        hanoi(n - 1, start, bypass, to);
        std::cout << start << " " << to << "\n";
        hanoi(n - 1, bypass, to, start);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    std::cout << (1 << N) - 1 << "\n";
    hanoi(N, 1, 3, 2);
    return 0;
}