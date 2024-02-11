// 백준: 사각 사각
// https://www.acmicpc.net/problem/3359
// 2024-02-11

/*
마지막 변의 길이는 빼야했다 ... :(
너무 어렵게 생각했다. 으아아아ㅏㄱ
*/

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int n;
    cin >> n;
    vector<vector<int>> dp(n, vector<int>(2, 0));
    vector<int> temp(n);
    vector<vector<int>> rectangles(n, vector<int>(2, 0));
    for (int i = 0; i < n; ++i) {
        cin >> rectangles[i][0] >> rectangles[i][1];
        if (rectangles[i][0] > rectangles[i][1]) {
            swap(rectangles[i][0], rectangles[i][1]);
        }
    }

    dp[0][0] = rectangles[0][0];
    dp[0][1] = rectangles[0][1];
    for (int i = 1; i < n; ++i) {
        dp[i][0] = rectangles[i][0] + max(dp[i - 1][0] + abs(rectangles[i - 1][1] - rectangles[i][1]), dp[i - 1][1] + abs(rectangles[i - 1][0] - rectangles[i][1]));
        dp[i][1] = rectangles[i][1] + max(dp[i - 1][0] + abs(rectangles[i - 1][1] - rectangles[i][0]), dp[i - 1][1] + abs(rectangles[i - 1][0] - rectangles[i][0]));
    }

    cout << max(dp[n - 1][0], dp[n - 1][1]);
    return 0;
}