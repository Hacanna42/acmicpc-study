// 백준: 숨바꼭질 4
// https://www.acmicpc.net/problem/13913
// 2204-07-07

// 간단한 BFS 역추적 문제.

#include <algorithm>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cout.tie(nullptr);
    int N; // 수빈이의 위치 N
    int K; // 동생의 위치 K
    cin >> N >> K;
    vector<int> path(140001, -1); // 역추적 기록

    queue<pair<int, int>> q;              // pair: pos, weight
    vector<int> dist(140001, (~0U >> 2)); // 방문 체크. 똑같은 노드에 더 긴시간에 도달했으면 거르기
    q.push({N, 0});
    int T;
    while (!q.empty()) {
        int cur_pos = q.front().first;
        int cur_time = q.front().second;
        q.pop();

        if (cur_pos == K) {
            T = cur_time;
            break;
        }

        // 걷기: +1
        if (cur_pos + 1 < 140000 && dist[cur_pos + 1] > cur_time + 1) {
            q.push({cur_pos + 1, cur_time + 1});
            dist[cur_pos + 1] = cur_time + 1;
            path[cur_pos + 1] = cur_pos;
        }
        // 걷기: -1
        if (cur_pos - 1 >= 0 && dist[cur_pos - 1] > cur_time + 1) {
            q.push({cur_pos - 1, cur_time + 1});
            dist[cur_pos - 1] = cur_time + 1;
            path[cur_pos - 1] = cur_pos;
        }
        // 순간이동: 2*X
        if (cur_pos * 2 < 140000 && dist[cur_pos * 2] > cur_time + 1) {
            q.push({cur_pos * 2, cur_time + 1});
            dist[cur_pos * 2] = cur_time + 1;
            path[cur_pos * 2] = cur_pos;
        }
    }

    cout << T << "\n";
    vector<int> temp;

    int cur = K;       // 동생 위치에서 시작
    while (cur != N) { // 수빈이 위치 도달까지 반복
        temp.push_back(cur);
        cur = path[cur];
    }

    reverse(temp.begin(), temp.end());
    cout << N << " ";
    for (const int &next : temp) {
        cout << next << " ";
    }

    return 0;
}