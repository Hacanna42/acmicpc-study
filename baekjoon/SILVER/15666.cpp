// 백준: N과 M(12)
// https://www.acmicpc.net/problem/15666
// 2024-05-22

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M; // N개의 자연수 중 M개 고른 수열
vector<int> arr;
vector<vector<int>> paths;
void dfs(vector<int> &path, int index) {
    if (path.size() == M) {
        paths.push_back(path);
        return;
    }

    for (int i = index; i < N; ++i) {
        path.push_back(arr[i]);
        dfs(path, i);
        path.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    arr.assign(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }
    sort(arr.begin(), arr.end());

    vector<int> path;
    dfs(path, 0);

    sort(paths.begin(), paths.end());
    paths.erase(unique(paths.begin(), paths.end()), paths.end());

    for (const auto &path : paths) {
        for (const auto &next : path) {
            cout << next << " ";
        }
        cout << "\n";
    }

    return 0;
}