// 백준: 벌집
// https://www.acmicpc.net/problem/2292
// 2023-12-21

#include <iostream>
int main() {
    int n;
    std::cin >> n;
    int count = 1;
    for (int i = 1;; i++) {
        if (n <= count) {
            std::cout << i;
            break;
        }
        count = count + (6 * i);
    }
    return 0;
}

// 침착하게 패턴을 찾고 식을 정리하면 쉽게 풀 수 있다
// 근데 어려웠다.