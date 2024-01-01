// 백준: 좌표 정렬하기
// https://www.acmicpc.net/problem/11650
// 2024-01-01

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::vector<std::pair<int, int> > xy_list;
    int N;
    int temp_x;
    int temp_y;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::cin >> temp_x >> temp_y;
        xy_list.push_back(std::make_pair(temp_x, temp_y));
    }
    // algorithm STL의 sort 함수는 자동으로 pair에 대해서 X를 정렬하고 X가
    // 같다면 Y를 정렬한다.
    std::sort(xy_list.begin(), xy_list.end());
    for (int i = 0; i < N; ++i) {
        std::cout << xy_list[i].first << ' ' << xy_list[i].second << '\n';
    }

    return 0;
}