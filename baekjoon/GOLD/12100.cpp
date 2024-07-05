// 백준: 2048 (Easy)
// https://www.acmicpc.net/problem/12100
// 2024-07-05

// naive한 구현 + 백트래킹 문제.

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N;          // 보드의 크기 N * N
int answer = 0; // 정답

// LEFT 연산
vector<vector<int>> left(vector<vector<int>> map) {
    for (int r = 0; r < N; ++r) { // 각 행마다 계산
        int prev_num = 0;         // 이전 숫자
        int i = 0;                // 인덱스 관리
        for (int c = 0; c < N; ++c) {
            if (map[r][c] == 0)
                continue;                // 빈칸 스킵
            if (map[r][c] == prev_num) { // 이전 숫자와 똑같다면 합치기
                map[r][--i] = prev_num * 2;
                answer = max(answer, prev_num * 2);
                prev_num = 0; // 두번 연속 합치기 방지
                ++i;          // 다시 인덱스 증가
            } else {          // 이전 숫자와 똑같지 않다면
                map[r][i] = map[r][c];
                prev_num = map[r][c];
                ++i;
            }
        }

        // i 인덱스 이후의 요소를 모두 0으로 변경
        while (i < N) {
            map[r][i++] = 0;
        }
    }

    return map;
}

// RIGHT 연산
vector<vector<int>> right(vector<vector<int>> map) {
    for (int r = 0; r < N; ++r) { // 각 행마다 계산
        int prev_num = 0;         // 이전 숫자
        int i = N - 1;            // 인덱스 관리
        for (int c = N - 1; c >= 0; --c) {
            if (map[r][c] == 0)
                continue;                // 빈칸 스킵
            if (map[r][c] == prev_num) { // 이전 숫자와 똑같다면 합치기
                map[r][++i] = prev_num * 2;
                answer = max(answer, prev_num * 2);
                prev_num = 0; // 두번 연속 합치기 방지
                --i;          // 다시 인덱스 조정
            } else {          // 이전 숫자와 똑같지 않다면
                map[r][i] = map[r][c];
                prev_num = map[r][c];
                --i;
            }
        }

        // i 인덱스 이후의 요소를 모두 0으로 변경
        while (i >= 0) {
            map[r][i--] = 0;
        }
    }

    return map;
}

// UP 연산
vector<vector<int>> up(vector<vector<int>> map) {
    for (int c = 0; c < N; ++c) { // 각 열마다 계산
        int prev_num = 0;         // 이전 숫자
        int i = 0;                // 인덱스 관리
        for (int r = 0; r < N; ++r) {
            if (map[r][c] == 0)
                continue;                // 빈칸 스킵
            if (map[r][c] == prev_num) { // 이전 숫자와 똑같다면 합치기
                map[--i][c] = prev_num * 2;
                answer = max(answer, prev_num * 2);
                prev_num = 0; // 두번 연속 합치기 방지
                ++i;          // 다시 인덱스 증가
            } else {          // 이전 숫자와 똑같지 않다면
                map[i][c] = map[r][c];
                prev_num = map[r][c];
                ++i;
            }
        }

        // i 인덱스 이후의 요소를 모두 0으로 변경
        while (i < N) {
            map[i++][c] = 0;
        }
    }

    return map;
}

// DOWN 연산
vector<vector<int>> down(vector<vector<int>> map) {
    for (int c = 0; c < N; ++c) { // 각 열마다 계산
        int prev_num = 0;         // 이전 숫자
        int i = N - 1;            // 인덱스 관리
        for (int r = N - 1; r >= 0; --r) {
            if (map[r][c] == 0)
                continue;                // 빈칸 스킵
            if (map[r][c] == prev_num) { // 이전 숫자와 똑같다면 합치기
                map[++i][c] = prev_num * 2;
                answer = max(answer, prev_num * 2);
                prev_num = 0; // 두번 연속 합치기 방지
                --i;          // 다시 인덱스 증가
            } else {          // 이전 숫자와 똑같지 않다면
                map[i][c] = map[r][c];
                prev_num = map[r][c];
                --i;
            }
        }

        // i 인덱스 이후의 요소를 모두 0으로 변경
        while (i >= 0) {
            map[i--][c] = 0;
        }
    }

    return map;
}

void dfs(int depth, int direction, vector<vector<int>> &map) {
    if (depth == 5) {
        return;
    }

    // direction: 0(왼쪽), 1(오른쪽), 2(위), 3(아래)
    vector<vector<int>> calculated_map; // 그냥 복사해서 백트래킹 대체하자..
    if (direction == 0)
        calculated_map = left(map);
    else if (direction == 1)
        calculated_map = right(map);
    else if (direction == 2)
        calculated_map = up(map);
    else if (direction == 3)
        calculated_map = down(map);

    for (int i = 0; i < 4; ++i) // 모든 방향으로 DFS
        dfs(depth + 1, i, calculated_map);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N; // 보드의 크기 N
    vector<vector<int>> map(N, vector<int>(N, 0));
    for (int r = 0; r < N; ++r) {
        for (int c = 0; c < N; ++c) {
            cin >> map[r][c];
            answer = max(answer, map[r][c]); // 아무것도 안 합쳐질 수도 있으므로 주어진 테이블에서 최댓값을 기본값으로 설정
        }
    }

    for (int i = 0; i < 4; ++i) {
        dfs(0, i, map);
    }

    cout << answer;
}