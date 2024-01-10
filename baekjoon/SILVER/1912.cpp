// 백준: 연속합
// https://www.acmicpc.net/problem/1912
// 2024-01-10

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> sequence;
std::vector<int> memo;

int dp() {
    memo[0] = sequence[0];
    int max = sequence[0];
    for (int i = 1; i < sequence.size(); ++i) {
        memo[i] = std::max(memo[i - 1] + sequence[i], sequence[i]);
        max = std::max(memo[i], max);
    }
    return max;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    memo.assign(N, 0);
    sequence.assign(N, INT_MIN);
    for (int i = 0; i < N; ++i) {
        std::cin >> sequence[i];
    }
    std::cout << dp();
    return 0;
}