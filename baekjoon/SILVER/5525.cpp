// 백준: IOIOI
// https://www.acmicpc.net/problem/5525
// 2024-04-29

#include <iostream>
#include <string>
using namespace std;

int N, M;
string S;
int pattern_len;
int prev_complete_index = -1; // 탐색 완료한 인덱스 표시 (최적화)
int problem_index = -1;       // 문제 발생한 인덱스 표시 (최적화)

bool check(int start_index) {
    int end_index = start_index + pattern_len; // start_index부터 end_index 미만까지 loop
    if (start_index < prev_complete_index) {   // 시작 인덱스가 이미 탐색 되었다면
        start_index = prev_complete_index - 1; // 탐색이 끝난곳부터 탐색
    }

    if (end_index > M)
        return false; // 범위 초과

    /*
    탐색이 끝난 곳 (prev_complete_index)나, 탐색을 시작한 곳 (check() 호출)의 인덱스는
    무조건 'I' 부터 시작한다고 확신할 수 있다.
    */
    int holder = 0;
    for (; start_index < end_index; ++start_index, ++holder) {
        // holder가 짝수일 때는 I여야만 하고, 홀수일 때는 O여야만 함.
        if ((holder % 2 == 0 && S[start_index] != 'I') || (holder % 2 == 1 && S[start_index] != 'O')) {
            problem_index = start_index;
            return false;
        }
    }

    // 통과
    prev_complete_index = end_index;
    return true;
}

int main() {
    ios_base::sync_with_stdio(false); // 입출력 최적화
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M >> S;

    int i = 0;
    int cnt = 0;
    pattern_len = N * 2 + 1;
    while (i <= M - pattern_len) {
        if (S[i] == 'I') {
            if (check(i)) {
                ++cnt;
                ++i; // 만약 VALID 했다면, 다음 문자열은 무조건 'O' 이기 때문에 한번 스킵한다.
            } else {
                // 만약 중간에 틀렸다면, 문제 인덱스 이전까지 유효한 문자가 있을 수 없으므로 스킵
                if (i < problem_index) {
                    i = problem_index;
                    continue;
                }
            }
        }
        ++i;
    }

    cout << cnt;
    return 0;
}