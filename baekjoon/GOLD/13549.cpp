// 백준: 숨바꼭질 3
// https://www.acmicpc.net/problem/13549
// 2024-01-27
// 0-1 BFS 입문 문제 (혹은 다익스트라로 해결 가능)

/*
deque를 사용해서 가중치가 0이면 덱의 앞에, 1이면 뒤에 추가하면서
이동 비용이 없는 이동을 최우선으로 고려하도록 함.
*/

#define map_size 150000

#include <deque>
#include <iostream>
#include <utility>
#include <vector>

int N, K;
std::vector<std::pair<bool, bool> > visited(map_size,
                                            {false,
                                             false});  // PAIR = 걷기 | 순간이동

int bfs() {
    std::deque<std::pair<int, int> > d;
    d.push_front({N, 0});
    visited[N].first = true;
    int answer = 0;
    while (!d.empty()) {
        int current_pos = d.front().first;
        int current_dist = d.front().second;
        d.pop_front();
        answer = current_dist;
        if (current_pos == K) break;

        // 걷기 이동
        for (int i = -1; i < 2; i += 2) {
            int next_pos = current_pos + i;
            if (next_pos >= 0 && next_pos <= map_size &&
                !visited[next_pos].first) {
                d.push_back({next_pos, current_dist + 1});
                visited[next_pos].first = true;
            }
        }

        // 순간 이동
        int next_pos = current_pos * 2;
        if (next_pos <= map_size && !visited[next_pos].second) {
            d.push_front({next_pos, current_dist});
            visited[next_pos].second = true;
        }
    }
    return answer;
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N >> K;
    std::cout << bfs();
    return 0;
}