// 백준: N과 M (6)
// https://www.acmicpc.net/problem/15655
// 2024-07-13

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M;

void dfs(vector<int> &path, vector<int> &arr, int start) {
    if (path.size() == M) {
        for (const int next : path) {
            cout << next << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < N; ++i) {
        if (arr[i] == -1)
            continue;      // 중복 체크
        int temp = arr[i]; // 이전 값 저장
        arr[i] = -1;       // 방문 체크 (-1로 값 변경)
        path.push_back(temp);
        dfs(path, arr, i + 1);
        arr[i] = temp; // 값 복원 (백트래킹)
        path.pop_back();
    }

    return;
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

    sort(arr.begin(), arr.end());
    vector<int> path;
    dfs(path, arr, 0);

    return 0;
}