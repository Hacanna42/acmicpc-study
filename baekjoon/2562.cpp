// 백준: 최댓값
// https://www.acmicpc.net/problem/2562
// 2023-12-04

#include <iostream>
int main() {
    int count = 1;
    int n = 0;
    int max_c = 0;
    int max_i = 0;

    while (count < 10) {
        std::cin >> n;
        if (n > max_i) {
            max_c = count;
            max_i = n;
        }
        count++;
    }
    std::cout << max_i << "\n" << max_c;
    return 0;
}