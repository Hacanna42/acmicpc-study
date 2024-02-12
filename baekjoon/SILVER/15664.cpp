// 백준: N과 M (10)
// https://www.acmicpc.net/problem/15664
// 2024-02-12

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<vector<int>> result;
vector<int> sequence;
vector<int> nums;
// vector<bool> visited;

void dfs(int start, int depth) {
    if (depth == M) {
        if (find(result.begin(), result.end(), sequence) == result.end()) {
            result.push_back(sequence);
        }
        for (int i = 0; i < M; ++i) {
            cout << sequence[i] << ' ';
        }
        cout << "\n";
        return;
    }

    for (int i = start; i < N; ++i) {
        if (i > start && nums[i] == nums[i - 1])
            continue;
        // if (visited[i])
        //     continue;
        sequence.push_back(nums[i]);
        dfs(i + 1, depth + 1);
        sequence.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    nums.assign(N, 0);
    // visited.assign(N, false);
    for (int i = 0; i < N; ++i) {
        cin >> nums[i];
    }

    sort(nums.begin(), nums.end());
    dfs(0, 0);
    return 0;
}