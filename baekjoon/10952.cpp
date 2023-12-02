// 백준: A+B - 5
// https://www.acmicpc.net/problem/10952
// 2023-12-02

#include <iostream>
// cin.tie(NULL) | sync_with_stdio(false) | endl 사용 금지
// 버퍼를 비우는 과정을 최소화한다.
int main() {
    int a, b;
    std::ios::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    while (true) {
        a = 0, b = 0;
        std::cin >> a >> b;
        if (a == 0 && b == 0)
            return 0;
        else
            std::cout << a + b << "\n";
    }
    return 0;
}