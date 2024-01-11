// 백준: 가장 긴 바이토닉 부분 수열
// https://www.acmicpc.net/problem/11054
// 2024-01-11

#include <algorithm>
#include <iostream>
#include <vector>
std::vector<int> nums;
std::vector<int> LIS;
std::vector<int> LDS;
int dp(int n) {
    for (int i = 1; i < n; ++i) {
        for (int j = 0; j < i; ++j) {
            if (nums[j] < nums[i]) LIS[i] = std::max(LIS[i], LIS[j] + 1);
        }
    }
    for (int i = n - 1; i >= 0; --i) {
        for (int j = n - 1; j > i; --j) {
            if (nums[j] < nums[i]) LDS[i] = std::max(LDS[i], LDS[j] + 1);
        }
    }

    int max = 1;
    for (int i = 0; i < n; ++i) {
        int temp = LIS[i] + LDS[i] - 1;
        if (temp > max) max = temp;
    }
    return max;
}
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    nums.assign(N, 0);
    LIS.assign(N, 1);
    LDS.assign(N, 1);
    for (int i = 0; i < N; ++i) {
        std::cin >> nums[i];
    }
    std::cout << dp(N);
    return 0;
}