// 백준: 두 용액
// https://www.acmicpc.net/problem/2470
// 2024-01-29

#include <limits.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    std::vector<int> v(N, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> v[i];
    }

    std::sort(v.begin(), v.end());

    long min = LONG_MAX;
    std::pair<int, int> answer;
    int start = 0, end = N - 1;
    long abs_sum;
    while (start < end) {
        abs_sum = std::abs(v[start] + v[end]);
        if (abs_sum == 0) {
            answer = {v[start], v[end]};
            break;
        }
        if (abs_sum < min) {
            min = abs_sum;
            answer = {v[start], v[end]};
        }
        if (v[start] + v[end] > 0) {
            end--;
        } else if (v[start] + v[end] < 0) {
            start++;
        }
    }

    std::cout << answer.first << " " << answer.second;
    return 0;
}