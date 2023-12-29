// 백준: 설탕 배달
// https://www.acmicpc.net/problem/2839
// 2023-12-29

#include <iostream>
int main() {
    int n;
    int answer = 5000;
    std::cin >> n;
    for (int i = 0; i < (n / 5) + 1; ++i) {
        for (int j = 0; j < (n / 3) + 1; ++j) {
            if ((i * 5) + (j * 3) == n && i + j < answer) {
                answer = i + j;
            }
        }
    }
    if (answer == 5000) answer = -1;
    std::cout << answer;
    return 0;
}