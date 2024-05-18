// 백준: N과 M (5)
// https://www.acmicpc.net/problem/15654
// 2024-05-16

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int N, M;

void dfs(vector<int> &path, vector<int> &arr, vector<bool> &visited) {
    if (path.size() == M) {
        for (const int &num : path) {
            cout << num << " ";
        }
        cout << "\n";
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
    cin >> N >> M; // N개의 수에서 M개를 고른 수열
    vector<int> arr(N);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());
    vector<int> path;
    vector<bool> visited(N, false);
    dfs(path, arr, visited);
    return 0;
}