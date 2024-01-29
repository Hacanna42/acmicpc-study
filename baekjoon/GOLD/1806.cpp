// 백준: 부분합
// https://www.acmicpc.net/problem/1806
// 2024-01-29

#include <limits.h>

#include <algorithm>
#include <iostream>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, S;
    std::cin >> N >> S;
    std::vector<int> v(N, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i];
    }

    int length = INT_MAX, sum = 0;
    int start = 0, end = 0;

    while (end <= N) {
        if (sum >= S) {
            length = std::min(length, end - start);
            sum -= v[start++];
        } else {
            if (end == N) break;
            sum += v[end++];
        }
    }

    std::cout << (length == INT_MAX ? 0 : length);
    return 0;
}