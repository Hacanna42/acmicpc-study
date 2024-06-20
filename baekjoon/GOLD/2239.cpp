// 백준: 스도쿠
// https://www.acmicpc.net/problem/2239
// 2024-06-15

/*
문제 지문에 약간의 오해가 있다. 9개의 줄에 9개의 숫자로 답을 출력하는데 이것을 '사전순'으로 출력하라고 한다.
즉, 81자리의 수가 제일 작은 경우: 스도쿠를 왼쪽 위에서부터 쭉 나열했을 때 나오는 81자리의 숫자가 작은 순서대로.
그니까 좌측 위에서부터 우측으로 탐색을 한다고 했을 때 제일 작은 숫자부터 넣어보며 가능성을 탐색해야 한다.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

bool solved = false; // 해답이 발견되는 순간 true로 변경한다.
// 백트래킹 이전에 solved 여부를 체크함으로써 해답이 발견되면 모두 백트래킹 없이 return; 되도록 한다

// VALID CHECK 함수부터 만들자
bool lineCheck(int N, int r, int c, vector<vector<int>> &map) {
    for (int i = 1; i <= 9; ++i) {
        if (map[r][i] == N || map[i][c] == N) // 현재 위치의 직선 위치에 넣고자 하는 값이 있다면
            return false;
    }
    return true;
}

bool squareCheck(int N, int r, int c, vector<vector<int>> &map) {
    int start_r = ((r - 1) / 3) * 3 + 1;
    int start_c = ((c - 1) / 3) * 3 + 1;

    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 3; ++j) {
            if (map[start_r + i][start_c + j] == N)
                return false;
        }
    }

    return true;
}

bool check(int N, int r, int c, vector<vector<int>> &map) { return (lineCheck(N, r, c, map) && squareCheck(N, r, c, map)); }

void solution(int cur_r, int cur_c, vector<vector<int>> &map) {
    // 탐색 완료: 종료
    if (solved)
        return;
    if (cur_r == 10) {
        solved = true;
        return;
    }

    // 현재 위치가 비어있지 않으면 다음으로 넘기기
    if (map[cur_r][cur_c] != 0) {
        if (cur_c != 9) // 마지막 열이 아니라면 +1 탐색
            solution(cur_r, cur_c + 1, map);
        else // 마지막 열이라면 다음 행으로
            solution(cur_r + 1, 1, map);
        return;
    }

    // 현재 위치가 비어있다면:
    for (int n = 1; n <= 9; ++n) {
        if (check(n, cur_r, cur_c, map)) { // 넣어도 괜찮은 값 발견
            map[cur_r][cur_c] = n;         // 맵 업데이트
            // 재귀적으로 DFS 가지 생성
            if (cur_c != 9) // 다음 열
                solution(cur_r, cur_c + 1, map);
            else // 다음 행
                solution(cur_r + 1, 1, map);
            if (solved) // 만약 DFS의 제일 끝에서 해답이 나왔으면, solved 변수를 true로 바꾸는데. 백트래킹 이전에 가지치기를 해줘야 해답 데이터를 가져올 수 있음에 주의. 백트래킹 이후에 return하면 모든
                        // 데이터가 원본으로 돌아온다.
                return;
            map[cur_r][cur_c] = 0; // 답이 안나오면 백트래킹
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<vector<int>> map(10, vector<int>(10)); // 1-based index
    for (int r = 1; r <= 9; ++r) {
        string line;
        cin >> line;
        for (int c = 1; c <= 9; ++c) {
            map[r][c] = line[c - 1] - '0';
        }
    }

    solution(1, 1, map);

    for (int r = 1; r <= 9; ++r) {
        for (int c = 1; c <= 9; ++c) {
            cout << map[r][c];
        }
        cout << '\n';
    }

    return 0;
}