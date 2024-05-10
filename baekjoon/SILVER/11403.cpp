// 백준: 경로 찾기
// https://www.acmicpc.net/problem/11403
// 2024-05-07

#include <iostream>
#include <vector>
using namespace std;

int main() {
    // 주의: 방향 그래프
    int N; // 정점의 개수 N
    cin >> N;
    vector<vector<int>> adj(N + 1, vector<int>(N + 1, 0));
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cin >> adj[i][j];
        }
    }

    for (int k = 1; k <= N; ++k) {
        for (int i = 1; i <= N; ++i) {
            for (int j = 1; j <= N; ++j) {
                if (adj[i][k] && adj[k][j]) // i -> k -> j 가 가능하다면 (1이라면)
                    adj[i][j] = 1;
            }
        }
    }

    // 결과 출력
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= N; ++j) {
            cout << adj[i][j] << " ";
        }
        cout << "\n";
    }

    return 0;
}