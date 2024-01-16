// 백준: 공유기 설치
// https://www.acmicpc.net/problem/2110
// 2024-01-16

#include <algorithm>
#include <iostream>
#include <vector>

int binary_search(std::vector<int>& houses, int low, int high, int target);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, C;
    std::vector<int> houses;
    std::cin >> N >> C;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        houses.push_back(temp);
    }

    std::sort(houses.begin(), houses.end());
    std::cout << binary_search(houses, 1, houses[N - 1] + houses[0], C);
    return 0;
}

int binary_search(std::vector<int>& houses, int low, int high, int target) {
    int answer = 0;
    while (low <= high) {
        int mid = (low + high) / 2;
        int count = 1;
        int prev_house = houses[0];
        for (int i = 1; i < houses.size(); ++i) {
            if (houses[i] - prev_house >= mid) {
                ++count;
                prev_house = houses[i];
            }
        }

        if (count >= target) {
            low = mid + 1;
            answer = std::max(answer, mid);
        } else
            high = mid - 1;
    }
    return answer;
}