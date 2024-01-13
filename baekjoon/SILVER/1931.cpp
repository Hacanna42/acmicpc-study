// 백준: 회의실 배정
// https://www.acmicpc.net/problem/1931
// 2024-01-13

#include <algorithm>
#include <deque>
#include <iostream>
#include <utility>

bool compare(const std::pair<int, int>& a, const std::pair<int, int>& b) {
    if (a.second == b.second) return a.first < b.first;
    return a.second < b.second;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::deque<std::pair<int, int> > timetable;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int start, end;
        std::cin >> start >> end;
        timetable.push_back(std::make_pair(start, end));
    }

    std::sort(timetable.begin(), timetable.end(), compare);

    int count = 0;
    int current_time = 0;
    for (const auto& iter : timetable) {
        if (current_time <= iter.first) {
            ++count;
            current_time = iter.second;
        }
    }

    std::cout << count;
    return 0;
}