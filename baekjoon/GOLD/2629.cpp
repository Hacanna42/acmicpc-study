// 백준: 양팔저울
// https://www.acmicpc.net/problem/2629
// 2024-01-20

#include <cmath>
#include <iostream>
#include <vector>

int weight_num, weight, marble_num, marble;
std::vector<int> weights;
// std::vector<int> marbles;
std::vector<std::vector<bool> > dp(31, std::vector<bool>(40001, false));

void solve(int i, int weight) {
    if (i > weight_num || dp[i][weight]) return;  // 기저조건
    dp[i][weight] = true;
    solve(i + 1, weight);
    solve(i + 1, weight + weights[i]);
    solve(i + 1, std::abs(weight - weights[i]));
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> weight_num;
    for (int i = 0; i < weight_num; ++i) {
        std::cin >> weight;
        weights.push_back(weight);
    }

    solve(0, 0);

    std::cin >> marble_num;
    for (int i = 0; i < marble_num; ++i) {
        std::cin >> marble;
        std::cout << (dp[weight_num][marble] ? "Y" : "N") << " ";
        // marbles.push_back(marble);
    }

    return 0;
}