// 백준: 연속구간
// https://www.acmicpc.net/problem/2495
// 2024-07-31

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int loop = 3;
    while (loop--) {
        string s;
        cin >> s;
        int prev = 0;
        int max_streak = 1;
        int cur_streak = 1;
        for (int i = 0; i < s.size(); ++i) {
            int cur_num = s[i] - '0';
            if (prev == cur_num) {
                ++cur_streak;
                max_streak = max(max_streak, cur_streak);
            } else { // 다르다면
                cur_streak = 1;
            }
            prev = cur_num;
        }

        cout << max_streak << "\n";
    }
    return 0;
}