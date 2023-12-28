// 백준: 수학은 비대면강의입니다
// https://www.acmicpc.net/problem/19532
// 2023-12-28

#include <iostream>
int main() {
    int a, b, c, d, e, f;
    std::cin >> a >> b >> c >> d >> e >> f;
    for (int x = -999; x <= 999; ++x) {
        for (int y = -999; y <= 999; ++y) {
            if ((a * x) + (b * y) == c && (d * x) + (e * y) == f) {
                std::cout << x << " " << y;
            }
        }
    }
    return 0;
}