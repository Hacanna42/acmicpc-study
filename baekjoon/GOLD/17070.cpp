// 백준: 파이프 옮기기 1
// https://www.acmicpc.net/problem/17070
// 2024-05-23

/*
그냥 DFS 탐색 브루트포스 문제
DP로도 풀 수 있는데  이 문제는 N이 작아서 그냥 완탐으로 풀어도 된다.
*/

#include <iostream>
#include <vector>
using namespace std;

int N; // N*N 크기의 맵
vector<vector<int>> map;
int cnt = 0;

// 이전 파이프가 가로로 놓여있을 때 다음 파이프의 가능한 위치
int horizontal_dr[2] = {0, 1};
int horizontal_dc[2] = {1, 1};
// 이전 파이프가 세로로 놓여있을 때
int vertical_dr[2] = {1, 1};
int vertical_dc[2] = {0, 1};
// 이전 파이프가 대각선으로 놓여있을 때
int diagonal_dr[3] = {0, 1, 1};
int diagonal_dc[3] = {1, 0, 1};

int getPipeDirection(int &start_r, int &start_c, int &end_r, int &end_c) { // 가로: -1, 세로: 1, 대각선: 0
    if (start_r == end_r && end_c - start_c == 1)                          // 가로
        return -1;
    else if (start_c == end_c && end_r - start_r == 1) // 세로
        return 1;
    else
        return 0;
}

void solution(int start_r, int start_c, int end_r, int end_c) {
    // 현재 파이프의 방향 알아내기
    int cur_direction = getPipeDirection(start_r, start_c, end_r, end_c);

    if (cur_direction == 0 && (map[end_r - 1][end_c] == 1 || map[end_r][end_c - 1] == 1)) // 대각선 벽지 긁었다면 종료
        return;

    if (end_r == N && end_c == N) { // 목표 지점 도착하면 카운트 증가하고 종료
        ++cnt;
        return;
    }

    // 가로
    if (cur_direction == -1) {
        for (int i = 0; i < 2; ++i) {
            int next_end_r = end_r + horizontal_dr[i];
            int next_end_c = end_c + horizontal_dc[i];
            if (next_end_r <= N && next_end_c <= N && map[next_end_r][next_end_c] == 0) { // VALID CHECK
                solution(end_r, end_c, next_end_r, next_end_c);
            }
        }
    }

    // 세로
    else if (cur_direction == 1) {
        for (int i = 0; i < 2; ++i) {
            int next_end_r = end_r + vertical_dr[i];
            int next_end_c = end_c + vertical_dc[i];
            if (next_end_r <= N && next_end_c <= N && map[next_end_r][next_end_c] == 0) { // VALID CHECK
                solution(end_r, end_c, next_end_r, next_end_c);
            }
        }
    }

    // 대각선
    else if (cur_direction == 0) {
        for (int i = 0; i < 3; ++i) {
            int next_end_r = end_r + diagonal_dr[i];
            int next_end_c = end_c + diagonal_dc[i];
            if (next_end_r <= N && next_end_c <= N && map[next_end_r][next_end_c] == 0) {
                solution(end_r, end_c, next_end_r, next_end_c);
            }
        }
    }

    return;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> N;
    map.assign(N + 1, vector<int>(N + 1, 0)); // index from 1
    for (int r = 1; r <= N; ++r) {
        for (int c = 1; c <= N; ++c) {
            cin >> map[r][c];
        }
    }

    solution(1, 1, 1, 2);
    cout << cnt;
    return 0;
}