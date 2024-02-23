#include <string>
#include <vector>

using namespace std;

int solution(int n, vector<vector<int>> results) {
    int answer = 0;
    vector<vector<int>> graph(n + 1, vector<int>(n + 1));
    // 플로이드-와셜
    for (const auto &result : results) {
        graph[result[0]][result[1]] = 1;
        graph[result[1]][result[0]] = -1;
    }

    for (int k = 1; k <= n; ++k) {         // 거치는 사람
        for (int i = 1; i <= n; ++i) {     // A
            for (int j = 1; j <= n; ++j) { // B
                if (graph[i][k] == 1 && graph[k][j] == 1)
                    graph[i][j] = 1;
                else if (graph[i][k] == -1 && graph[k][j] == -1)
                    graph[i][j] = -1;
            }
        }
    }

    for (int r = 1; r <= n; ++r) {
        int count = 0;
        for (int c = 1; c <= n; ++c) {
            if (graph[r][c] != 0)
                ++count;
        }
        if (count == n - 1)
            ++answer;
    }

    return answer;
}