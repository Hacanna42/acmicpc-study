// 백준: 마인크래프트
// https://www.acmicpc.net/problem/18111
// 2024-04-24

/* 유형 추측
1. 많은 조건 분기
2. 그리디

-

가설
먼저 어떤 높이로 층을 맞출 것인지 정해야 한다.

1. 각 높이를 내림차순으로 분류 (이거, 계수 정렬 쓰면 효율적일 것 같다(Counting sort))
각 높이가 얼마나 빈번하게 나왔는지 계수 정렬하고, 많이 나온 순의 층부터 탐색하면 되지 않을까?
제일 빈번하게 나온 층에 맞추는 게 제일 빠를 것이라는 걸 그리디하게 증명할 수 없다.
2. 순회하면서 어떤 층에서의 비용이 제일 적은지 브루트포스 탐색 (가지치기)
3. 그 층에서의 비용 출력
*/

#include <iostream>
// #include <set> // unique한 층을 정렬하기 위해서 사용 (계수 정렬로 대체)
#include <algorithm>
#include <functional>
#include <limits.h>
#include <utility>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M, B; // N*M 맵, B개의 기본제공 블럭
    cin >> N >> M >> B;
    vector<vector<int>> map(N, vector<int>(M));

    // 계수 정렬 (Counting sort)
    // 단순히 계수하고 내림차순하면 n^2의 순회를 필요로 하므로 pair로 인덱스를 기록하고 sort한다.
    vector<pair<int, int>> floors(257);
    for (int i = 0; i <= 256; ++i) {
        floors[i] = {0, i};
    }

    // set을 계수 정렬로 대체함
    // set<int> unique_floors;

    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            int temp;
            cin >> temp;
            map[r][c] = temp;
            floors[temp].first++;
            // unique_floors.insert(temp);
        }
    }

    // 층 빈도를 내림차순으로 정렬
    sort(floors.begin(), floors.end(), [](const pair<int, int> &a, const pair<int, int> &b) { return a.first > b.first; });

    // floors 디버그 체크
    // for (const auto &next : floors) {
    //     cout << next.first << "\n" << next.second << "\n\n***\n\n";
    //     if (next.first == 0)
    //         break;
    // }

    // 최단 시간 저장
    ll known_min_time = LLONG_MAX;
    int known_min_floor = -1;

    // 가장 빈도가 높은 층 순으로 탐색
    for (int i = 0; i <= 256; ++i) {
        int time = 0;                      // 소요된 시간
        int goal_floor = floors[i].second; // 현재 탐색할 목표 층
        if (floors[i].first == 0) {        // 만약 현재 목표 층이 한번도 나온적이 없으면 탐색 종료
            break;
        }
        // 맵을 순회하면서 비용 계산
        // 블록 제거 : 2초
        // 블록 설치 : 1초 (B 소모, B가 없으면 해당 층 진행 불가능)

        bool gg = false;
        for (int r = 0; r < N && !gg; ++r) {
            for (int c = 0; c < M && !gg; ++c) {
                int cur_floor = map[r][c];   // 현재 탐색중인 칸
                if (cur_floor == goal_floor) // 현재 칸이 이미 목표 층이라면 스킵
                    continue;
                else if (cur_floor > goal_floor) {        // 현재 칸이 목표 층보다 높다면
                    time += (cur_floor - goal_floor) * 2; // 부숴야 할 블럭에 2초씩 적용
                    B += cur_floor - goal_floor;          // 인벤토리에 부순 블럭 추가
                } else if (cur_floor < goal_floor) {      // 현재 칸이 목표 층보다 낮다면
                    B += cur_floor - goal_floor;          // 칸의 차를 B에 업데이트
                    time += goal_floor - cur_floor;       // 설치 시간 1초 적용
                    if (B < 0) {                          // 방금의 계산으로 B가 음수가 됐다면 이번 층 포기
                        gg = true;                        // GG
                        break;
                    }
                    if (time > known_min_time) {
                        gg = true;
                        break; // 방금의 작업으로 알려진 최단 시간을 초과했다면 이번 층 포기
                    }
                }
            }
        }

        // 탐색이 끝났고, 해당 목표 층이 가능했다면
        if (!gg) {
            if (time < known_min_time) { // 소요된 시간이 알려진 시간보다 빠르다면
                known_min_time = time;
                known_min_floor = goal_floor;
            } else if (time == known_min_time) { // 복수 정답이면 높은 층을 정답으로
                known_min_floor = max(known_min_floor, goal_floor);
            }
        }
    }

    cout << known_min_time << " " << known_min_floor;

    return 0;
    // 이미 존재하는 층 별로 탐색
    // for (set<int>::iterator it = unique_floors.begin(); it != unique_floors.end(); ++it) {
    //     int cur_floor = *it; // 현재 탐색할 목표 층
    // }
}