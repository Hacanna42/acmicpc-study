// 백준: 빠른 A+B
// https://www.acmicpc.net/problem/15552
// 2023-11-30

#include <iostream>
// cin.tie(NULL) | sync_with_stdio(false) | endl 사용 금지
// 버퍼를 비우는 과정을 최소화한다.
int main() {
    int t;
    int a, b;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> t;
    for (int i = 0; i < t; i++) {
        a = 0, b = 0;
        std::cin >> a >> b;
        std::cout << a + b << "\n";
    }
    return 0;
}