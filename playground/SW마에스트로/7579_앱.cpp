#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N, M;
    cin >> N >> M;
    vector<int> assigned_memory(N);
    vector<int> app_cost(N);
    for (int i = 0; i < N; ++i)
        cin >> assigned_memory[i];
    for (int i = 0; i < N; ++i)
        cin >> app_cost[i];

    vector<int> dp(10001, 0); // 비용 i로 확보할 수 있는 최대 메모리
    for (int i = 0; i < N; ++i) {
        for (int j = 10001; j >= app_cost[i]; --j) {
            dp[j] = max(dp[j], dp[j - app_cost[i]] + assigned_memory[i]);
        }
    }

    for (int i = 0;; ++i) {
        if (dp[i] >= M) {
            cout << i;
            break;
        }
    }
}