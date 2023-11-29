// 백준: 알람 시계
// https://www.acmicpc.net/problem/2884
// 2023-11-29

#include <iostream>
int main() {
    int h, m;
    std::cin >> h >> m;
    if (m >= 45)
        m = m - 45;
    else {
        h--;
        m += 15;
    }
    if (h == -1) {
        h = 23;
    }

    std::cout << h << " " << m;
    return 0;
}