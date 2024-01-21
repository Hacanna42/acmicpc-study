// 백준: 앱
// https://www.acmicpc.net/problem/7579
// 2024-01-21

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

#define COST_LIMIT 10001

int N, M;
std::vector<int> assigned_memory;
std::vector<int> app_cost;
std::vector<int> dp;

void input();
void solve();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    input();
    solve();
    for (int i = 0; i <= COST_LIMIT; ++i) {
        if (dp[i] >= M) {
            std::cout << i;
            break;
        }
    }
    return 0;
}

void solve() {
    dp.assign(COST_LIMIT, 0);
    for (int i = 0; i < N; ++i) {
        for (int j = COST_LIMIT - 1; j >= app_cost[i]; --j) {
            dp[j] = std::max(dp[j], dp[j - app_cost[i]] + assigned_memory[i]);
        }
    }
}

void input() {
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int temp = 0;
        std::cin >> temp;
        assigned_memory.push_back(temp);
    }
    for (int i = 0; i < N; ++i) {
        int temp = 0;
        std::cin >> temp;
        app_cost.push_back(temp);
    }
}