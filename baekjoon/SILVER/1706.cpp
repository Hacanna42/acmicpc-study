// 백준: 크로스워드
// https://www.acmicpc.net/problem/1706
// 2024-02-10

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int R, C;
    cin >> R >> C;
    vector<vector<char>> matrix(R, vector<char>(C));
    vector<string> words;
    for (int i = 0; i < R; ++i) {
        string str;
        for (int j = 0; j < C; ++j) {
            cin >> matrix[i][j];
            // 장애물
            if (matrix[i][j] == '#') {
                if (str.length() > 1) {
                    words.push_back(str);
                }
                str.clear();
            } else {
                str += matrix[i][j];
            }
        }
        // 다음 줄로 넘어가지면
        if (str.length() > 1) {
            words.push_back(str);
            str.clear();
        }
    }

    // 세로 검사
    for (int j = 0; j < C; ++j) {
        string str;
        for (int i = 0; i < R; ++i) {
            if (matrix[i][j] == '#') {
                if (str.length() > 1) {
                    words.push_back(str);
                }
                str.clear();
            } else {
                str += matrix[i][j];
            }
        }
        // 다음 줄로 넘어가지면
        if (str.length() > 1) {
            words.push_back(str);
            str.clear();
        }
    }

    sort(words.begin(), words.end());
    cout << words[0];

    return 0;
}