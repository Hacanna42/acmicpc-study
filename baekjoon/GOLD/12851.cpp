// 백준: 숨바꼭질 2
// https://www.acmicpc.net/problem/12851
// 2024-05-28

/*
문제점: 방문 체크를 하면 최단 시간 방법의 수를 얻을 수 없다.
그렇다고 방문 체크를 안하면 TLE가 난다
dist 배열을 만들어서 방문 체크처럼 쓰는 건 어떨까? 같은 수에 대해서 가중치가 더 낮은 것만 통과 시키는 것.
같은 수에 도달하는데에 어떤 루트는 더 높은 가중치를 썼다면 그것은 최단 루트가 아님이 명백하다.
*/

#include <algorithm>
#include <iostream>
#include <iterator>
#include <queue>
#include <utility>
#define INF (~0U >> 2)
using namespace std;

int known_shortest_time = INF;
int shortest_time_count = 0;

void bfs(int N, int K) {
    // bool visited[140001] = {
    //     false,
    // };

    int dist[140001];
    fill(begin(dist), end(dist), INF);

    queue<pair<int, int>> q; // time, pos
    // visited[N] = true;       // 시작 지점 방문 표시
    dist[N] = 0;
    q.push({0, N});

    while (!q.empty()) {
        int cur_pos = q.front().second;
        int cur_time = q.front().first;
        q.pop();

        if (cur_pos == K) { // 목표 도달
            if (known_shortest_time == INF) {
                known_shortest_time = cur_time; // 첫 도달 시간이 무조건 가능 최단 시간
            }

            if (cur_time > known_shortest_time)
                return; // 최단 시간보다 긴 시간이 발견되면 종료
            shortest_time_count++;
        }

        if (cur_time > dist[cur_pos]) // 현재 노드까지 도달한 경로가 최적 경로가 아닌 경우
            continue;

        // dist[cur_pos] = cur_time;

        /*
        그리디적으로 봤을 때 0~10만 범위 밖에서 한 칸 가는 건 완전히 비효율적이므로 해가 될 가능성이 없다
        6만에서 *2를 해서 나머지를 마이너스로 채우는 전략은 유효할 수 있다. 따라서, 곱하기에 대해서는 방문 배열을 넉넉하게 14만까지 허용.
        */

        // movement: +, -
        if (cur_pos + 1 <= 100000 && cur_time + 1 <= dist[cur_pos + 1]) { // 경계 체크, 시간 체크(방문 겸용)
            q.push({cur_time + 1, cur_pos + 1});
            dist[cur_pos + 1] = cur_time + 1;
        }
        if (cur_pos - 1 >= 0 && cur_time + 1 <= dist[cur_pos - 1]) {
            q.push({cur_time + 1, cur_pos - 1});
            dist[cur_pos - 1] = cur_time + 1;
        }

        // movement: 2*X
        if (2 * cur_pos <= 140000 && cur_time + 1 <= dist[2 * cur_pos]) {
            q.push({cur_time + 1, 2 * cur_pos});
            dist[2 * cur_pos] = cur_time + 1;
        }
    }
}

int main() {
    int N, K; // 수빈이 위치 N, 동생 위치 K
    cin >> N >> K;
    bfs(N, K);
    cout << known_shortest_time << "\n" << shortest_time_count;
    return 0;
}