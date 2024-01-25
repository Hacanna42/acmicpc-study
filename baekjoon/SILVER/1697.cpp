// 백준: 숨바꼭질
// https://www.acmicpc.net/problem/1697
// 2024-01-25

#include <iostream>
#include <queue>
#include <utility>
#include <vector>

std::vector<bool> visited(100001, false);
int dx[2] = {-1, 1};
int K;

int bfs(int n) {
    std::queue<std::pair<int, int> > q;
    int time = 0;
    q.push({n, 0});
    visited[n] = true;

    while (!q.empty()) {
        int current = q.front().first;
        int time = q.front().second;
        q.pop();
        if (current == K) {
            return time;
        }
        for (int i = 0; i < 3; ++i) {
            int next_x;
            if (i != 2) {
                next_x = current + dx[i];
            } else
                next_x = current * 2;

            if (next_x >= 0 && next_x <= 100000 && !visited[next_x]) {
                q.push({next_x, time + 1});
                visited[next_x] = true;
            }
        }
    }
    return -1;
}

int main() {
    int N;
    std::cin >> N >> K;
    std::cout << bfs(N);
}