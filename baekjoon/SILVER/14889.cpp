// 백준: 스타트와 링크
// https://www.acmicpc.net/problem/14889
// 2024-01-09

#include <limits.h>

#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>

int N;
int answer = INT_MAX;
std::vector<std::vector<int> > v;
std::vector<int> speclist;

void dfs(int idx, int L, std::vector<bool>& team) {
    if (L == N / 2) {
        int start = 0, link = 0;
        for (int i = 0; i < N; ++i) {
            for (int j = 0; j < N; ++j) {
                if (team[i] && team[j]) start += v[i][j];
                if (!team[i] && !team[j]) link += v[i][j];
            }
        }
        answer = std::min(answer, abs(start - link));
        return;
    }

    for (int i = idx; i < N; ++i) {
        if (!team[i]) {
            team[i] = true;
            dfs(i + 1, L + 1, team);
            team[i] = false;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N;
    v.assign(N, std::vector<int>(N));
    std::vector<bool> team(N, false);
    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < N; ++j) {
            std::cin >> v[i][j];
        }
    }

    dfs(0, 0, team);
    std::cout << answer;
    return 0;
}