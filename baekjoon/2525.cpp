// 백준: 오븐 시계
// https://www.acmicpc.net/problem/2525
// 2023-11-29

#include <iostream>
int main() {
    int h, m;
    int inc_time;
    int inc_h, inc_m;
    std::cin >> h >> m >> inc_time;

    // inc_time / 60 = 추가할 H
    // inc_time % 60 = 추가할 M(만약 n+M > 60, except)
    // h%24 처리

    inc_h = inc_time / 60;
    inc_m = inc_time % 60;

    if (m + inc_m >= 60) {
        h++;
        m = (m + inc_m) % 60;
    } else {
        m += inc_m;
    }

    h += inc_h;
    h %= 24;

    std::cout << h << " " << m;

    return 0;
}