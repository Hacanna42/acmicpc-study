// 백준: 평범한 배낭
// https://www.acmicpc.net/problem/12865
// 2024-01-12

#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> memo;

int main() {
    int N, K;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N >> K;
    memo.assign(K + 1, 0);
    int maxValue = 0;
    for (int i = 1; i <= N; ++i) {
        int W, V;
        std::cin >> W >> V;
        for (int j = K; j >= W; --j) {
            memo[j] = std::max(memo[j], memo[j - W] + V);
            if (memo[j] > maxValue) maxValue = memo[j];
        }
    }
    std::cout << maxValue;
    return 0;
}