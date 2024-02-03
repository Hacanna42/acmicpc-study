// 백준: 회의실 배정 2
// https://www.acmicpc.net/problem/19621
// 2024-02-03

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>
std::vector<std::pair<std::pair<int, int>, int> >
    timetable;  // <<시작 시간, 종료시간>, 인원>
std::vector<int> dp;
int N;

int maxMan(int index) {
    if (index >= N) return 0;
    if (dp[index] != -1) return dp[index];

    int take = timetable[index].second + maxMan(index + 2);
    int skip = maxMan(index + 1);
    dp[index] = std::max(take, skip);
    return dp[index];
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N;
    dp.assign(N, -1);
    for (int i = 0; i < N; ++i) {
        int start, end, num;
        std::cin >> start >> end >> num;
        timetable.push_back({{start, end}, num});
    }

    std::sort(timetable.begin(), timetable.end(),
              [](const std::pair<std::pair<int, int>, int>& a,
                 const std::pair<std::pair<int, int>, int>& b) {
                  return a.first.second < b.first.second;
              });

    std::cout << maxMan(0);
    return 0;
}