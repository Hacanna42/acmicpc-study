// 백준: 소인수분해
// https://www.acmicpc.net/problem/11653
// 2023-12-22

#include <iostream>

int main() {
    int N;
    std::cin >> N;
    int i = 2;
    while (true) {
        if (N % i == 0) {
            std::cout << i << std::endl;
            N /= i;
        } else
            i++;
        if (N == 1) break;
    }
    return 0;
}