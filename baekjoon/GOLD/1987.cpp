// 백준: 알파벳
// https://www.acmicpc.net/problem/1987
// 2024-05-23

/*
전형적인 백트래킹 + DFS 문제에
unique 알파벳을 저장하는데에 제일 효율적인 unordered_set으로 알파벳 체크 + 방문체크
방문 체크 배열을 따로 만들 필요가 없다. 어차피 이미 방문한 위치의 경우 알파벳이 겹쳐서 재방문하지 못한다.
unordered_set으로 알파벳을 관리해도 TLE가 난다. 비트마스킹을 해야 한다. 32비트 정수형에서 저장할 수 있는 상태는 총 32개.
대소문자 알파벳의 개수는 26개이기 때문에 충분히 가능하다.

PS. 비트마스킹의 기초를 다지게 된 교육적인 문제.
*/

#include <iostream>
// #include <unordered_set>
#include <vector>
using namespace std;

int dr[4] = {1, -1, 0, 0};
int dc[4] = {0, 0, 1, -1};

int R, C; // R*C의 보드
vector<vector<char>> map;

int known_farthest_depth = 0;

void solution(int depth, int cur_r, int cur_c, int bitmask) {
    if (known_farthest_depth < depth)
        known_farthest_depth = depth;

    for (int i = 0; i < 4; ++i) {
        int next_r = cur_r + dr[i];
        int next_c = cur_c + dc[i];
        if (next_r >= 0 && next_c >= 0 && next_r < R && next_c < C) { // VALID CHECK
            int next_char_bit = 1 << (map[next_r][next_c] - 'A');
            if ((bitmask & next_char_bit) == 0) { // 아직 나오지 않은 알파벳
                solution(depth + 1, next_r, next_c, bitmask | next_char_bit);
                // bitmask &= ~next_char_bit; 재귀 호출 인자에서 값을 변경해서 보내기에, 백트래킹 필요 없음.
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cin >> R >> C;
    map.assign(R, vector<char>(C, '\0'));
    for (int r = 0; r < R; ++r) {
        for (int c = 0; c < C; ++c) {
            cin >> map[r][c];
        }
    }

    // unordered_set<char> set;
    int start_bitmask = 1 << (map[0][0] - 'A');
    // set.insert(map[0][0]); // 시작 지점 추가
    solution(1, 0, 0, start_bitmask);
    cout << known_farthest_depth;
    return 0;
}