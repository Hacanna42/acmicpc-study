// 백준: 합
// https://www.acmicpc.net/problem/8393
// 2023-11-30

#include <iostream>
int main() {
    int n;
    int answer = 0;
    std::cin >> n;
    for (int i = 1; i <= n; i++) {
        answer += i;
    }
    std::cout << answer;
    return 0;
}