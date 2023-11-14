// 백준: 별 찍기 - 7
// https://www.acmicpc.net/problem/2444
// 2023-11-14

#include <algorithm>
#include <iostream>
#include <string>

int main() {
    int n;
    std::cin >> n;

    // 위쪽 부분
    for (int i = 1; i <= n; ++i) {
        std::cout << std::string(std::max(0, n - i), ' ')
                  << std::string(std::max(0, i * 2 - 1), '*') << std::endl;
    }

    // 아래쪽 부분
    for (int i = 1; i < n; ++i) {
        std::cout << std::string(std::max(0, i), ' ')
                  << std::string(std::max(0, (n - i) * 2 - 1), '*')
                  << std::endl;
    }

    return 0;
}
