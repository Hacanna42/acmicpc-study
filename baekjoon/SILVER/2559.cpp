// 백준: 수열
// https://www.acmicpc.net/problem/2559
// 2024-01-12

#include <iostream>
#include <vector>

std::vector<int> prefixSum;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, range;
    std::cin >> N >> range;
    prefixSum.assign(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        int temp;
        std::cin >> temp;
        prefixSum[i] = prefixSum[i - 1] + temp;
    }
    int max = -20000000;
    for (int i = 1; i <= N - range + 1; ++i) {
        int currentSum = prefixSum[i + range - 1] - prefixSum[i - 1];
        if (currentSum > max) max = currentSum;
    }

    std::cout << max;
    return 0;
}