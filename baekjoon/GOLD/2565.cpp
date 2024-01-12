// 백준: 전깃줄
// https://www.acmicpc.net/problem/2565
// 2024-01-12

#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> pole(501, 0);
std::vector<int> sequence;
std::vector<int> memo;

int LIS_DP(int n) {
    int maxLength = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (sequence[j] < sequence[i]) {
                memo[i] = std::max(memo[i], memo[j] + 1);
            }
        }
        maxLength = std::max(maxLength, memo[i]);
    }

    return maxLength;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    memo.assign(N, 1);
    for (int i = 0; i < N; ++i) {
        int A, B;
        std::cin >> A >> B;
        pole[A] = B;
    }
    for (const auto iter : pole) {
        if (iter != 0) sequence.push_back(iter);
    }
    std::cout << N - LIS_DP(N);
    return 0;
}