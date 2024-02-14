#include <algorithm>
#include <limits.h>
#include <string>
#include <utility>
#include <vector>
using namespace std;

/*
dp[start][end] : start~end의 최소, 최댓값 pair (시작 인덱스: 0)
*/

int solution(vector<string> arr) {
    int n = arr.size() / 2 + 1;
    vector<vector<pair<int, int>>> dp(n, vector<pair<int, int>>(n, {INT_MAX, INT_MIN}));
    for (int i = 0; i < arr.size(); i += 2) {
        int num = stoi(arr[i]);
        dp[i / 2][i / 2] = {num, num};
    }

    for (int len = 1; len <= n; ++len) {
        for (int start = 0; start + len < n; ++start) {
            int end = start + len;
            // dp[start][end] = {INT_MAX, INT_MIN};
            for (int mid = start; mid < end; ++mid) {
                int leftMin = dp[start][mid].first;
                int leftMax = dp[start][mid].second;
                int rightMin = dp[mid + 1][end].first;
                int rightMax = dp[mid + 1][end].second;

                char op = arr[mid * 2 + 1][0];

                if (op == '-') {
                    dp[start][end].first = min(dp[start][end].first, leftMin - rightMax);
                    dp[start][end].second = max(dp[start][end].second, leftMax - rightMin);
                } else {
                    dp[start][end].first = min(dp[start][end].first, leftMin + rightMin);
                    dp[start][end].second = max(dp[start][end].second, leftMax + rightMax);
                }
            }
        }
    }

    return dp[0][n - 1].second;
}