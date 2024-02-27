#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string S;
    getline(cin, S);
    vector<vector<int>> dp(26, vector<int>((S.size() + 1)));

    for (int i = 1; i <= S.size(); ++i) { // 각 문자에 대해 순회
        // 누적합 업데이트
        for (int a = 0; a < 26; ++a) {
            dp[a][i] = dp[a][i - 1];
        }
        // 해당 문자를 누적합에 추가
        int cur_alp = S[i - 1] - 'a';
        dp[cur_alp][i] = dp[cur_alp][i - 1] + 1;
    }

    int TC;
    cin >> TC;
    while (TC--) {
        char temp;
        int start, end;
        cin >> temp >> start >> end;
        end += 1; // 인덱스 조정
        int who = temp - 'a';
        cout << dp[who][end] - dp[who][start] << "\n";
    }
    return 0;
}