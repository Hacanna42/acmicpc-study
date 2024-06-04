// 백준: 미세먼지 안녕!
// https://www.acmicpc.net/problem/17144
// 2024-06-02
// 재밌어 보이는 시뮬레이션 구현 문제!

/* 1초에 일어나는 일
1. 미세먼지가 확산된다.
2. 공기청정기가 작동한다.

공기청정기는 항상 1번 열에 설치되어 있다.


인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
확산되는 양은 A/5이고 소수점은 버린다. 즉, ⌊A/5⌋이다.
(r, c)에 남은 미세먼지의 양은 A - ⌊A/5⌋×(확산된 방향의 개수) 이다.

주의사항: 확산은 동시에 일어나고, 확산 이전에 있었던 미세먼지에 대해서만 일어나고, 순서에 영향을 받지 않는다 (원본 맵에서 일어난다음, 가중치를 합한다)

공기청정기 작동:  공기 청정기에서는 바람이 나온다. 위쪽 공기청정기의 바람은 반시계 방향 순환, 아래쪽은 시계 방향으로 순환한다.
바람이 불면 미세먼지는 바람의 방향대로 모두 한칸씩 이동한다. 공기 청정기에서 부는 바람은 미세먼지가 없는 바람이고, 공기 청정기로 들어간 바람은 모두 정화된다.
*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int R, C, T; // R*C 맵, T초 후 미세먼지 양
vector<vector<int>> map;

int dr[4] = {1, -1, 0, 0}; // 인접 탐색 배열
int dc[4] = {0, 0, 1, -1};

pair<int, int> conditioner_upper_pos = make_pair(-1, -1); // 공기 청정기 위쪽 좌표
pair<int, int> conditioner_below_pos;

pair<int, int> getNextPos(int cur_r, int cur_c, bool clockDir) { // 다음 바람 방향을 구하는 함수
    // clockDir ? 시계 : 반시계
    if (clockDir) {
        if (cur_r != 1 && cur_c != 1 && cur_r != R && cur_c != C) // 그 어느 모서리도 아니라면
            return make_pair(cur_r, cur_c + 1);                   // 오른쪽으로
        if (cur_c == C && cur_r != R)                             // 오른쪽 끝이지만, 모서리는 아니라면
            return make_pair(cur_r + 1, cur_c);                   // 아래로
        if (cur_r == R && cur_c != 1)                             // 아래쪽 끝이지만, 모서리는 아니라면
            return make_pair(cur_r, cur_c - 1);                   // 왼쪽으로
        else                                                      // 왼쪽 끝이라면
            return make_pair(cur_r - 1, cur_c);                   // 위로
    } else {
        if (cur_r != 1 && cur_c != 1 && cur_r != R && cur_c != C) // 그 어느 모서리도 아니라면
            return make_pair(cur_r, cur_c + 1);                   // 오른쪽으로
        if (cur_c == C && cur_r != 1)                             // 오른쪽 끝이지만, 모서리는 아니라면
            return make_pair(cur_r - 1, cur_c);                   // 위쪽으로
        if (cur_r == 1 && cur_c != 1)                             // 위쪽 끝이지만, 모서리는 아니라면
            return make_pair(cur_r, cur_c - 1);                   // 왼쪽으로
        else                                                      // 왼쪽 끝이라면
            return make_pair(cur_r + 1, cur_c);                   // 아래로
    }
}

void diffusionSimulation() { // 미세먼지 확산 시뮬레이션
    vector<vector<int>> dust_prefix(R + 1, vector<int>(C + 1, 0));
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {               // 원본 맵에서, 미세먼지 위치 탐색
            if (map[r][c] != -1 && map[r][c] != 0) { // -1: 공기청정기도 아니고, 0: 비어있지도 않다면
                int spread_count = 0;                // 확산 횟수
                int spread_amount = map[r][c] / 5;   // 확산량
                if (spread_amount == 0)
                    continue; // 최적화: 확산 될 미세먼지양이 부족하면 그냥 스킵
                for (int i = 0; i < 4; ++i) {
                    int next_r = r + dr[i];
                    int next_c = c + dc[i];

                    if (next_r > 0 && next_c > 0 && next_r <= R && next_c <= C && map[next_r][next_c] != -1) { // VALID CHECK
                        dust_prefix[next_r][next_c] += spread_amount;                                          // ⌊A/5⌋ 만큼 확산
                        ++spread_count;
                    }
                }
                // 확산 이후, 출처 미세먼지량 감소: A - ⌊A/5⌋×(확산된 방향의 개수)
                dust_prefix[r][c] -= spread_amount * spread_count;
            }
        }
    }

    // 원본 맵의 모든 미세먼지 위치에서 확산 시뮬레이션 완료했으면, 원본 맵을 dust_prefix 만큼 합산
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            map[r][c] += dust_prefix[r][c];
        }
    }
}

void windSimulation() { // 공기청정기 바람 시뮬레이션
    // 위쪽 공기청정기 (반시계)
    int cur_r = conditioner_upper_pos.first;
    int cur_c = conditioner_upper_pos.second;
    int prev_dust = 0;                // 이전 공간의 먼지
    cur_c += 1;                       // 오른쪽으로 이동하며 시작
    while (map[cur_r][cur_c] != -1) { // 공기청정기에 다시 도달할 때까지 반복
        // 현재 먼지를 prev_dust에 저장하고, 이전 먼지를 현재 공간에 대치
        int temp = prev_dust;
        prev_dust = map[cur_r][cur_c];
        map[cur_r][cur_c] = temp;

        pair<int, int> nextPos = getNextPos(cur_r, cur_c, false);
        cur_r = nextPos.first;
        cur_c = nextPos.second;
    }

    // 아래쪽 공기청정기 (시계)
    cur_r = conditioner_below_pos.first;
    cur_c = conditioner_below_pos.second;
    prev_dust = 0;                    // 이전 공간의 먼지
    cur_c += 1;                       // 오른쪽으로 이동하며 시작
    while (map[cur_r][cur_c] != -1) { // 공기청정기에 다시 도달할 때까지 반복
        // 현재 먼지를 prev_dust에 저장하고, 이전 먼지를 현재 공간에 대치
        int temp = prev_dust;
        prev_dust = map[cur_r][cur_c];
        map[cur_r][cur_c] = temp;

        pair<int, int> nextPos = getNextPos(cur_r, cur_c, true);
        cur_r = nextPos.first;
        cur_c = nextPos.second;
    }
}

int main() {
    // 1-based index
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C >> T; // R*C 맵, T초 후 미세먼지 양
    map.assign(R + 1, vector<int>(C + 1, 0));
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            cin >> map[r][c];
            if (map[r][c] == -1 && conditioner_upper_pos.first == -1) { // 아직 공기청정기 좌표가 등록되지 않았다면
                conditioner_upper_pos = {r, c};
                conditioner_below_pos = {r + 1, c};
            }
        }
    }

    while (T--) { // T초동안 시뮬레이션
        diffusionSimulation();
        windSimulation();
    }

    // 남아있는 미세먼지 양 계산
    int dust_count = 2; // 공기청정기(-1)이 두개 있으니까 경감 위해서 2로 초기화
    for (int r = 1; r <= R; ++r) {
        for (int c = 1; c <= C; ++c) {
            dust_count += map[r][c];
        }
    }

    cout << dust_count;

    return 0;
}