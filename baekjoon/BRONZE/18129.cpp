// 백준: 이상한 암호코드
// https://www.acmicpc.net/board/view/151259
// 2024-10-18

#include <cctype>
#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    string S;
    int K;
    cin >> S >> K;

    int streak = 1;
    string answer;

    unordered_map<char, bool> map;

    for (int i = 1; i < S.size(); ++i) {
        int cur_char = tolower(S[i]);
        int prev_char = tolower(S[i - 1]);

        if (cur_char == prev_char)
            ++streak; // 저번 문자와 같다면 연속 기록 연장

        if (cur_char != prev_char) { // 문자의 전환점에서 판단
            if (map[prev_char])
                continue;          // 치환 기록 있다면 넘기기
            map[prev_char] = true; // 치환 기록 표시
            if (streak >= K) {     // streak가 K보다 클때
                answer += "1";     // 1 넣기
            } else {
                answer += "0"; // K보다 작다면 0 넣기
            }
            streak = 1; // 연속 기록 초기화
        }
    }

    // 마지막 인덱스 판단
    if (!map[tolower(S[S.size() - 1])])
        answer += (streak >= K) ? "1" : "0";

    cout << answer;

    return 0;
}