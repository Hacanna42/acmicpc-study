// 백준: 주사위 세개
// https://www.acmicpc.net/problem/2480
// 2023-11-29

#include <algorithm>
#include <iostream>
int main() {
    int a, b, c;
    int prize = 0;
    std::cin >> a >> b >> c;
    if (a == b && b == c) {
        prize += 10000 + (a * 1000);
    } else {
        if (a == b)
            prize += 1000 + (a * 100);
        else if (b == c)
            prize += 1000 + (b * 100);
        else if (c == a)
            prize += 1000 + (c * 100);
        else {
            // std::initializer_list 이슈. C++ 17 에서만 지원하는 기능.
            prize += 100 * std::max({a, b, c});
        }
    }
    std::cout << prize;
    return 0;
}