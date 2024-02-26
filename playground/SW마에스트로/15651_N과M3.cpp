#include <iostream>
#include <vector>
using namespace std;
int N, M;
vector<int> sequence;

void dfs(int depth) {
    if (depth == M) {
        for (int &iter : sequence) {
            cout << iter << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= N; ++i) {
        sequence.push_back(i);
        dfs(depth + 1);
        sequence.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    dfs(0);
    return 0;
}