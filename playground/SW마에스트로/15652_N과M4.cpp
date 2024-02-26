#include <iostream>
#include <vector>
using namespace std;

int N, M;
vector<int> sequence;

void dfs(int start) {
    if (sequence.size() == M) {
        for (int &iter : sequence) {
            cout << iter << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = start; i <= N; ++i) {
        sequence.push_back(i);
        dfs(i);
        sequence.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> N >> M;
    dfs(1);
    return 0;
}