// 백준: 가장 긴 증가하는 부분 수열 4
// https://www.acmicpc.net/problem/14002
// 2024-01-30
// 보류

#include <iostream>
#include <vector>
std::vector<int> arr;

int main() {
    int len;
    std::cin >> len;
    for (int i = 0; i < len; ++i) {
        int temp;
        int len = 0;
        std::cin >> temp;
        arr.push_back(temp);
        for (int j = 0; j < 1; ++j) {
            if (dp[j] < dp[i]) len = std::max(dp[j], len);
        }
        dp[i] = len + 1;
    }

    std::cout << getLIS(len);

    return 0;
}