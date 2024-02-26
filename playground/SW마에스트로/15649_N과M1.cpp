#include <iostream>
#include <vector>

using namespace std;
int N, M;
vector<int> sequence;
vector<bool> visited;

void dfs(int depth) {
    if (depth == M) {
        for (int num : sequence) {
            cout << num << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            sequence.push_back(i);
            dfs(depth + 1);
            visited[i] = false;
            sequence.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    visited.assign(N + 1, false);
    dfs(0);
    return 0;
}