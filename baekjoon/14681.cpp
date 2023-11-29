// 백준: 사분면 고르기
// https://www.acmicpc.net/problem/14681
// 2023-11-29

#include <iostream>
int main() {
    int x, y;
    std::cin >> x >> y;
    // 1, 2
    if (y > 0) {
        if (x > 0)
            std::cout << "1";
        else
            std::cout << "2";
    }
    // 3, 4
    else if (y < 0) {
        if (x > 0)
            std::cout << "4";
        else
            std::cout << "3";
    }
    return 0;
}