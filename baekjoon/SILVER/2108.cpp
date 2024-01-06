// 백준: 통계학
// https://www.acmicpc.net/problem/2108
// 2024-01-06

#include <algorithm>
#include <cmath>
#include <iostream>
#include <map>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::vector<int> v;
    std::cin >> N;
    double sum = 0;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        v.push_back(temp);
        sum += temp;
    }

    std::sort(v.begin(), v.end());

    // 산술평균값
    sum = std::round(sum / static_cast<double>(N));
    if (sum == -0) sum = 0;
    // 중앙값
    auto iter_center = v.begin() + (v.size() / 2);
    int center = *iter_center;
    // 최빈값
    std::vector<int> freq(8001);
    std::vector<int> freq_list;
    int freq_value = 0;
    for (int i = 0; i < N; ++i) {
        freq[v[i] + 4000]++;
    }
    int max = 0;
    for (int i = 0; i < 8001; ++i) {
        if (freq[i] > max) {
            max = freq[i];
        }
    }
    for (int i = 0; i < 8001; ++i) {
        if (freq[i] == max) {
            freq_list.push_back(i - 4000);
        }
    }
    if (freq_list.size() != 1) {
        std::sort(freq_list.begin(), freq_list.end());
        freq_value = freq_list[1];
    } else
        freq_value = freq_list[0];
    // 범위
    int range = v.back() - v.front();

    // 출력
    std::cout << sum << "\n" << center << "\n" << freq_value << "\n" << range;

    return 0;
}