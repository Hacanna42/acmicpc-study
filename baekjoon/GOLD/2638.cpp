// 백준: 치즈
// https://www.acmicpc.net/problem/2638
// 2024-06-03

/*
간단한 BFS 탐색인데, 외부 공기와 내부 공기를 어떻게 구분할 것인가?
내 생각:
2차원 정수 벡터로 맵을 저장한다.
[0: 공기, 1: 치즈, -1: 맵 가장자리, 2: 외부 공기]
여기서 외부 공기란 맵의 가장자리와 인접해 있는 공기이기 때문에,
각 공기에 대해서 맵의 가장자리와 닿는 루트가 있다면 외부. 아니라면 내부 공기라고 판단할 수 있다.

문제의 본문에서 "모눈종이의 맨 가장자리에는 치즈가 놓이지 않는 것으로 가정한다." 라고 했음으로
맵의 가장자리를 -1로 표시할 수 있다(외부)

탐색 이전에 모든 -1 혹은 2로부터 인접 BFS 탐색을 시작해서 만나는 모든 공기(0)를 외부 공기(2)로 대체한다.
모든 치즈에 대해서 인접한 외부 공기(2)혹은 가장자리(-1)를 검색한다. 2변 이상이 인접해있으면 치즈 격자를 삭제한다.

유의사항: 치즈가 녹는 현상은 동시에 일어난다. 순서가 영향을 미치지 않는다.
*/

#include <iostream>
#include <queue>
#include <utility>
#include <vector>
using namespace std;

int N, M;                // 모눈종이 크기 N*M
vector<vector<int>> map; // 모눈종이 맵

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

void determineOutsideAir() { // 외부 공기 판단
    // 방문 배열은 필요 없을 것 같다: map의 정보를 2로 바꾸는 것이 방문 배열의 역할을 함
    // 모든 -1, 2에 대해서 주변 0으로 BFS. 2로 치환
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            if (map[r][c] == -1 || map[r][c] == 2) { // -1 혹은 2 발견
                queue<pair<int, int>> q;
                q.push({r, c});
                // BFS 시작
                while (!q.empty()) {
                    int cur_r = q.front().first;
                    int cur_c = q.front().second; // 여기서 q의 (r, c)값을 cur_r, cur_c로 정의했는데 아래의 if문에서는 for문의 인덱스 r, c를 쓰고 있었다. 실수.
                    q.pop();
                    for (int i = 0; i < 4; ++i) {
                        int next_r = cur_r + dr[i];
                        int next_c = cur_c + dc[i];
                        if (next_r > 0 && next_c > 0 && next_r < N && next_c < M && map[next_r][next_c] == 0) { // VALID CHECK
                            map[next_r][next_c] = 2;                                                            // 외부 공기라고 표시
                            q.push({next_r, next_c});
                        }
                    }
                }
            }
        }
    }
}

bool cheeseMeltSimulation() { // 치즈 녹음 시뮬레이션
    // 원본 맵을 보존하기 위해서, 녹을 치즈를 바로 맵에서 지우지 않고 좌표를 저장해놨다가 모든 치즈에 대한 연산이 끝난 뒤 맵을 업데이트한다.
    vector<pair<int, int>> meltedCheese;

    // 맵에서 치즈를 찾는다 (가장자리 제외)
    int cheeseCount = 0; // 맵의 치즈 개수를 추적하기 위한 함수
    for (int r = 1; r < N - 1; ++r) {
        for (int c = 1; c < M - 1; ++c) {
            if (map[r][c] == 1) { // 현재 (r, c)가 치즈라면
                ++cheeseCount;    // 치즈 개수 업데이트
                int outsideAirCount = 0;
                for (int i = 0; i < 4; ++i) { // 인접 격자에 2(외부공기) 혹은 가장자리(-1)가 있는지 확인
                    int next_r = r + dr[i];
                    int next_c = c + dc[i];
                    if (next_r >= 0 && next_c >= 0 && next_r < N && next_c < M && (map[next_r][next_c] == 2 || map[next_r][next_c] == -1)) { // VALID CHECK
                        ++outsideAirCount;                                                                                                   // 카운트 증가
                    }
                }
                if (outsideAirCount >= 2)
                    meltedCheese.push_back({r, c}); // 2변 이상 외부 공기와 맞닿아 있다면 현재 격자를 녹은 치즈 목록에 추가
            }
        }
    }

    if (meltedCheese.size() == cheeseCount) // 녹은 치즈가 맵에 남아있던 치즈 개수와 같다면, 모든 치즈가 녹은 것이므로 true 반환.
        return true;

    // 녹은 치즈를 맵에 반영한다
    for (const auto &next : meltedCheese)
        map[next.first][next.second] = 2;

    return false;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> N >> M; // 모눈종이 크기 N*M
    map.assign(N, vector<int>(M, 0));

    // 맵 입력받기
    int cheeseCount = 0;
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < M; ++c) {
            cin >> map[r][c];
            if (map[r][c] == 1)
                ++cheeseCount;
        }
    }

    if (cheeseCount == 0) { // 엣지 케이스 처리 : 치즈가 아예 없을 때
        cout << "0";
        return 0;
    }

    // 가장자리를 - 1로 표시
    for (int c = 0; c < M; ++c) {
        map[0][c] = -1;
        map[N - 1][c] = -1;
    }
    for (int r = 0; r < N; ++r) {
        map[r][0] = -1;
        map[r][M - 1] = -1;
    }

    int counter = 1;
    while (true) {
        determineOutsideAir();        // 외부 공기 업데이트
        if (cheeseMeltSimulation()) { // false면 치즈 남아있음, true면 치즈 없음.
            break;
        }
        ++counter;
    }

    cout << counter;

    return 0;
}