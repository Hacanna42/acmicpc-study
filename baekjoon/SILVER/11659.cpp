// 백준: 구간 합 구하기 4
// https://www.acmicpc.net/problem/11659
// 2024-01-12

#include <iostream>
#include <vector>

std::vector<long long> prefixSum;
std::vector<long long> numbers;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    prefixSum.assign(N + 1, 0);
    numbers.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> numbers[i];
    }
    long long sum = 0;
    for (int i = 1; i <= N; ++i) {
        sum += numbers[i - 1];
        prefixSum[i] = sum;
    }
    for (int k = 0; k < M; ++k) {
        int i, j;
        std::cin >> i >> j;
        std::cout << prefixSum[j] - prefixSum[i - 1] << "\n";
    }
    return 0;
}