// 백준: 알고리즘 수업 - 병합 정렬 1
// https://www.acmicpc.net/problem/24060
// 2024-01-07

#include <iostream>
#include <vector>

void merge(std::vector<int>& v, int p, int q, int r, int& c, int& answer,
           int& goal_count) {
    std::vector<int> tmp(r - p + 1);
    int i = p, j = q + 1, t = 0;

    while (i <= q && j <= r) {
        if (v[i] <= v[j]) {
            tmp[t++] = v[i++];
        } else {
            tmp[t++] = v[j++];
        }
    }
    while (i <= q) tmp[t++] = v[i++];
    while (j <= r) tmp[t++] = v[j++];

    for (i = p, t = 0; i <= r; ++i, ++t, ++c) {
        if (c == goal_count) answer = tmp[t];
        v[i] = tmp[t];
    }
}

void merge_sort(std::vector<int>& v, int p, int r, int& c, int& answer,
                int& goal_count) {
    if (p < r) {
        int q = (p + r) / 2;
        merge_sort(v, p, q, c, answer, goal_count);
        merge_sort(v, q + 1, r, c, answer, goal_count);
        merge(v, p, q, r, c, answer, goal_count);
    }
}

int main() {
    int count = 1;
    int goal_count;
    int answer = -1;
    std::vector<int> v;
    int N;
    std::cin >> N >> goal_count;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        v.push_back(temp);
    }
    merge_sort(v, 0, v.size() - 1, count, answer, goal_count);

    std::cout << answer;
    return 0;
}
