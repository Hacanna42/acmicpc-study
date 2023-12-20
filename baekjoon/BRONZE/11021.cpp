// 백준: A+B - 7
// https://www.acmicpc.net/problem/11021
// 2023-12-1

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
        std::cout << "Case #" << i + 1 << ": " << a + b << "\n";
    }
    return 0;
}