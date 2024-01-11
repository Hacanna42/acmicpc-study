// 백준: 가장 긴 증가하는 부분 수열
// https://www.acmicpc.net/problem/11053
// 2024-01-11

#include <iostream>
#include <vector>
std::vector<int> nums;
std::vector<int> memo;

int dp(int n) {
    int maxLength = 1;
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) {
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
    nums.assign(N, 0);
    memo.assign(N, 1);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }
    std::cout << dp(N);
    return 0;
}