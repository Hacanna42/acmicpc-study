#include <algorithm>
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
int weight_num;
vector<int> weights;
vector<vector<bool>> dp;

void solve(int i, int weight) {
    if (i > weight_num || dp[i][weight])
        return;
    dp[i][weight] = true;
    solve(i + 1, weight);
    solve(i + 1, weight + weights[i]);
    solve(i + 1, abs(weight - weights[i]));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    cin >> weight_num;
    weights.assign(weight_num, 0);
    dp.assign(weight_num + 1, vector<bool>(40001, false));
    for (int i = 0; i < weight_num; ++i) {
        cin >> weights[i];
    }

    solve(0, 0);

    int marble_num;
    cin >> marble_num;
    for (int i = 0; i < marble_num; ++i) {
        int marble;
        cin >> marble;
        cout << (dp[weight_num][marble] ? "Y " : "N ");
    }

    return 0;
}