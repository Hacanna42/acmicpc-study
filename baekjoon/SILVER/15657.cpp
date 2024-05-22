// 백준: N과 M(8)
// https://www.acmicpc.net/problem/15657
// 2024-05-22

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M; // N개의 자연수 중 M개 고른 수열
vector<int> arr;
void dfs(vector<int> &path, int index) {
    if (path.size() == M) {
        for (const auto &next : path) {
            cout << next << " ";
        }
        cout << "\n";
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

    return 0;
}