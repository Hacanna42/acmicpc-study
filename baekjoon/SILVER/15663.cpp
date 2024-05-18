// 백준: N과 M (9)
// https://www.acmicpc.net/problem/15663
// 2024-05-16

/*
주의: std::unique는 **연속된 중복 요소**를 제거함
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<vector<int>> saved_path;

void dfs(vector<int> &path, vector<int> &arr, vector<bool> &visited) {
    if (path.size() == M) {
        saved_path.push_back(path);
        return;
    }

    for (int i = 0; i < N; ++i) {
        if (!visited[i]) {
            path.push_back(arr[i]);
            visited[i] = true;
            dfs(path, arr, visited);
            path.pop_back(); // 백트래킹
            visited[i] = false;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    // sort(arr.begin(), arr.end());
    vector<bool> visited(N, false);
    vector<int> path;
    dfs(path, arr, visited);
    sort(saved_path.begin(), saved_path.end());                                       // std::unique는 연속된 중복 요소를 제거함.
    saved_path.erase(unique(saved_path.begin(), saved_path.end()), saved_path.end()); // 중복 제거
    for (const auto &path : saved_path) {
        for (const auto &next : path) {
            cout << next << " ";
        }
        cout << "\n";
    }
    return 0;
}