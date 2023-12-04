// 백준: 최소, 최대
// https://www.acmicpc.net/problem/10818
// 2023-12-04

#include <iostream>
int main() {
    int T;
    int minAnswer = 0;
    int maxAnswer = 0;
    std::cin >> T;
    for (int i = 0; i < T; i++) {
        int n;
        std::cin >> n;
        if (i == 0) {
            minAnswer = n;
            maxAnswer = n;
        }
        if (minAnswer > n) minAnswer = n;
        if (maxAnswer < n) maxAnswer = n;
    }
    std::cout << minAnswer << " " << maxAnswer;
    return 0;
}