// 백준: 준오는 조류혐오야!!
// https://www.acmicpc.net/problem/14647
// 2024-07-31

/*
모든 9의 개수를 세고, 9가 제일 많은 라인의 9 개수만큼 빼기.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int count9(int n) {
    string t = to_string(n);
    int result = 0;
    for (int i = 0; i < t.size(); ++i) {
        if (t[i] == '9')
            ++result;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n, m;
    cin >> n >> m;
    vector<vector<int>> board(n, vector<int>(m, 0));
    int sum = 0;
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            int t;
            cin >> t;
            sum += count9(t);
            board[r][c] = t;
        }
    }

    int max_sum = 0;
    int cur_sum = 0;
    // 행 검사
    for (int r = 0; r < n; ++r) {
        for (int c = 0; c < m; ++c) {
            cur_sum += count9(board[r][c]);
        }
        max_sum = max(max_sum, cur_sum);
        cur_sum = 0;
    }

    // 열 검사
    for (int c = 0; c < m; ++c) {
        for (int r = 0; r < n; ++r) {
            cur_sum += count9(board[r][c]);
        }
        max_sum = max(max_sum, cur_sum);
        cur_sum = 0;
    }

    cout << sum - max_sum;
    return 0;
}