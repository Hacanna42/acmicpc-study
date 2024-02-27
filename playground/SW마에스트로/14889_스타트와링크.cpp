#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

vector<vector<int>> S;
int N;
int answer = (~0U >> 2);

int calculate(const vector<int> &team) {
    int score = 0;
    for (int i = 0; i < team.size(); ++i) {
        for (int j = 0; j < team.size(); ++j) {
            score += S[team[i]][team[j]];
        }
    }
    return score;
}

void dfs(int depth, vector<int> &team, vector<bool> &visited, int selected) {
    if (depth == N / 2) {
        vector<int> team_compare;
        for (int i = 1; i <= N; ++i) {
            if (find(team.begin(), team.end(), i) == team.end())
                team_compare.push_back(i);
        }
        answer = min(answer, abs(calculate(team) - calculate(team_compare)));
        return;
    }

    for (int i = selected; i <= N; ++i) {
        if (!visited[i]) { // 방문하지 않았다면
            visited[i] = true;
            team.push_back(i);
            dfs(depth + 1, team, visited, i);
            visited[i] = false;
            team.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N;
    S.assign(N + 1, vector<int>(N + 1, 0));

    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> S[i][j];
        }
    }
    vector<int> team;
    vector<bool> visited(N + 1, false);
    dfs(0, team, visited, 1);
    cout << answer;

    return 0;
}