// 백준: 나머지
// https://www.acmicpc.net/problem/3052
// 2023-12-09

#include <iostream>
int main() {
    int uniqueCount = 0;
    bool seenRemainders[42] = {false};
    int arr_remainder[10] = {0};
    for (int i = 0; i < 10; i++) {
        std::cin >> arr_remainder[i];
        arr_remainder[i] %= 42;
    }
    for (int i = 0; i < 10; i++) {
        if (seenRemainders[arr_remainder[i]] == false) {
            uniqueCount++;
            seenRemainders[arr_remainder[i]] = true;
        }
    }
    std::cout << uniqueCount;

    return 0;
}