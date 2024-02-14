#include <algorithm>
#include <string>
#include <vector>

using namespace std;

int solution(vector<vector<int>> triangle) {
    vector<vector<int>> dp(triangle.size(), vector<int>(triangle.size()));
    dp[0][0] = triangle[0][0];
    for (int i = 1; i < triangle.size(); ++i) {
        for (int j = 0; j <= i; ++j) {
            if (j == 0)
                dp[i][j] = dp[i - 1][j] + triangle[i][j];
            else if (j == i)
                dp[i][j] = dp[i - 1][j - 1] + triangle[i][j];
            else
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][j - 1]) + triangle[i][j];
        }
    }
    int answer = 0;
    for (int i = 0; i < dp[triangle.size() - 1].size(); ++i) {
        answer = max(answer, dp[triangle.size() - 1][i]);
    }

    return answer;
}