// 백준: 아기 상어
// https://www.acmicpc.net/problem/16236
// 2024-06-04

#include <functional>
#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;
#define INF (~0U >> 2)

vector<vector<int>> map;
int N; // 공간의 크기

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

struct Shark {
    int r;
    int c;
    int size = 2;
    int streak = 0;
};

int eatNearestFish(Shark &baby) {
    // 다익스트라로 현재 아기상어 위치에서 각 모든 노드까지의 위치 판단 (자기보다 큰 물고기는 지나갈 수 없다. 크기가 같은 물고기는 지나갈 순 있지만 먹을 순 없다)
    vector<vector<int>> dist(N, vector<int>(N, INF));
    // 상단에서부터 좌측 -> 우측 순서로 탐색. (거리가 가까운 물고기가 많다면, 가장 위에 있는 물고기, 그러한 물고기가 여러마리라면, 가장 왼쪽에 있는 물고기를 먹는다.)
    // 같은 최단거리라면 업데이트 하지 않음 (왼쪽 상단 물고기 우선 적용)

    // 일단 다익스트라로 dist 배열 먼저 채우자
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, greater<pair<int, pair<int, int>>>> pq; // 가중치, r, c
    dist[baby.r][baby.c] = 0;                                                                                            // 아기상어 위치 0으로 초기화
    pq.push({0, {baby.r, baby.c}});

    while (!pq.empty()) {
        int cur_r = pq.top().second.first;
        int cur_c = pq.top().second.second;
        int cur_weight = pq.top().first;
        pq.pop();

        if (cur_weight > dist[cur_r][cur_c]) // 알려진 최단 거리보다 길다면 스킵
            continue;

        for (int i = 0; i < 4; ++i) {
            int next_r = cur_r + dr[i];
            int next_c = cur_c + dc[i];
            if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < N && map[next_r][next_c] <= baby.size) { // VALID CHECK
                if (cur_weight + 1 < dist[next_r][next_c]) {
                    dist[next_r][next_c] = cur_weight + 1;
                    pq.push({cur_weight + 1, {next_r, next_c}});
                }
            }
        }
    }

    // 상단 -> 하단, 좌측 -> 우측 순서로 탐색
    int known_shortest_distance = INF;
    pair<int, int> targetPos = {-1, -1}; // 먹을 생선 좌표
    for (int ir = 0; ir < N; ++ir) {
        for (int ic = 0; ic < N; ++ic) {
            int fish = map[ir][ic];                           // 해당 칸의 정보
            if (fish != 0 && fish != 9 && fish < baby.size) { // 빈칸도 아니고 아기 상어의 위치도 아니고, 먹을 수 있는 물고기라면
                if (dist[ir][ic] < known_shortest_distance) { // 알려진 최단 거리보다 더 짧을 경우에만 갱신
                    known_shortest_distance = dist[ir][ic];   // 알려진 최단 거리 업데이트
                    targetPos = {ir, ic};                     // 타겟 업데이트
                }
            }
        }
    }

    // 탐색 완료
    if (known_shortest_distance == INF) // 만약 아무 물고기도 먹을 수 없으면 -1 리턴
        return -1;

    // 맵을 업데이트 하고 가중치 리턴
    map[baby.r][baby.c] = 0;                    // 아기상어가 있던 자리 빈칸으로 변경
    map[targetPos.first][targetPos.second] = 9; // 새로운 아기 상어의 자리 업데이트
    baby.r = targetPos.first;
    baby.c = targetPos.second; // 실질적인 아기 상어 좌표값 업데이트
    // (문제 본문:) 아기 상어는 자신의 크기와 같은 수의 물고기를 먹을 때 마다 크기가 1 증가한다.
    ++baby.streak;                  // 물고기를 먹은 횟수를 추적
    if (baby.streak == baby.size) { // 자신의 크기와 같은 수의 물고기를 먹었다면
        ++baby.size;                // 아기 상어의 크기를 키우고
        baby.streak = 0;            // 추적 변수를 0으로 초기화합니다.
    }

    return known_shortest_distance; // 가중치 리턴
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    Shark baby;
    cin >> N;
    map.assign(N, vector<int>(N, 0));
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> map[r][c];
            if (map[r][c] == 9) { // 아기 상어 위치 초기화
                baby.r = r;
                baby.c = c;
            }
        }
    }

    // 맨해튼 거리로 거리를 파악하... 려고 했으나 자기보다 큰 물고기는 지나갈 수 없으므로 다익스트라를 써야할 듯
    int T = 0; // 시간 정보
    while (true) {
        int temp = eatNearestFish(baby);
        if (temp == -1) // 먹을 물고기가 없으면 종료
            break;
        T += temp;
    }

    cout << T;
    return 0;
}