// 백준: 최후의 승자는 누구?
// https://www.acmicpc.net/problem/12760
// 2024-02-19

#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

int main() {
    int N, M;
    cin >> N >> M;
    vector<vector<int>> v(N, vector<int>(M, 0));
    vector<int> score(N, 0);

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            cin >> v[i][j];
        }
    }

    for (int i = 0; i < N; ++i) {
        sort(v[i].begin(), v[i].end(), greater<int>());
    }

    for (int i = 0; i < M; ++i) {
        int maxCard = 0;
        for (int j = 0; j < N; ++j) {
            maxCard = max(maxCard, v[j][i]);
        }
        for (int j = 0; j < N; ++j) {
            if (v[j][i] == maxCard) {
                score[j]++;
            }
        }
    }

    int maxScore = *max_element(score.begin(), score.end());

    for (int i = 0; i < N; ++i) {
        if (score[i] == maxScore)
            cout << i + 1 << " ";
    }

    return 0;
}
