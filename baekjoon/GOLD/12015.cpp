// 백준: 가장 긴 증가하는 부분 수열 2
// https://www.acmicpc.net/problem/12015
// 2024-01-17

/* LIS를 이진탐색으로 풀어보자
lower_bound가 핵심인데, STL로도 풀어보고 직접 구현해서도 풀어봤다.
*/

#include <algorithm>
#include <iostream>
#include <vector>

int lower_bound(std::vector<int>& v, int low, int high, int target);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::vector<int> LIS;
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        if (!LIS.empty() && LIS.back() < temp) LIS.push_back(temp);
        // else {
        // STL 사용
        //     auto it = std::lower_bound(LIS.begin(), LIS.end(), temp);
        //     if (it == LIS.end())
        //         LIS.push_back(temp);
        //     else
        //         *it = temp;
        // }

        // 직접 구현
        else if (!LIS.empty()) {
            LIS[lower_bound(LIS, 0, LIS.size(), temp)] = temp;
        } else
            LIS.push_back(temp);
    }
    std::cout << LIS.size();
    return 0;
}

int lower_bound(std::vector<int>& v, int low, int high, int target) {
    while (low <= high) {
        int mid = low + (high - low) / 2;
        if (v[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}