// 백준: RGB거리
// https://www.acmicpc.net/problem/1149
// 2024-02-24
// 소마 대비

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<vector<int>> dp(N + 1);
    vector<vector<int>> prices(N + 1, vector<int>(3));
    for (int i = 1; i <= N; ++i) {
        cin >> prices[i][0] >> prices[i][1] >> prices[i][2];
    }
    /*
    1번 집의 색은 2번 집의 색과 같지 않아야 한다.
    N번 집의 색은 N-1번 집의 색과 같지 않아야 한다.
    i(2 ≤ i ≤ N-1)번 집의 색은 i-1번, i+1번 집의 색과 같지 않아야 한다.
    */

    // RGB
    // 0 - 이전 집이 R
    // 1 - 이전 집이 G
    // 2 - 이전 집이 B
    return 0;
}