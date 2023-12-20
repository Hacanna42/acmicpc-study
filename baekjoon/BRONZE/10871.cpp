// 백준: X보다 작은 수
// https://www.acmicpc.net/problem/10871
// 2023-12-02

#include <iostream>
int main() {
    int n;
    int limit;
    std::cin >> n >> limit;
    int *arr = new int[n];
    for (int i = 0; i < n; i++) {
        int a;
        std::cin >> a;
        if (a < limit) {
            std::cout << a << " ";
        }
    }

    return 0;
}