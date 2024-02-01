// 백준: LCS 2
// https://www.acmicpc.net/problem/9252
// 2024-02-01

#include <algorithm>
#include <iostream>
#include <string>
int dp[1001][1001] = {
    0,
};

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::string t1, t2;
    std::cin >> t1 >> t2;
    std::string str1 = " " + t1;
    std::string str2 = " " + t2;

    for (int i = 1; i < str2.size(); ++i) {
        for (int j = 1; j < str1.size(); ++j) {
            if (str1[j] == str2[i])
                dp[i][j] = dp[i - 1][j - 1] + 1;
            else
                dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]);
        }
    }

    // 역추적
    /*
    역추적 과정에서, dp[row][col]의 값이 dp[row-1][col]거나 dp[row][col-1]인
    경우 현재 문자는 LCS에 기여하지 않음을 나타낸다.
    두 문자가 같지 않을경우 dp[i][j] = std::max(dp[i - 1][j], dp[i][j - 1]); 로
    dp를 설정하기 때문이다. 따라서, dp[i][j] == dp[i - 1][j - 1] + 1; 경우에는
    해당 문자가 LCS에 기여함을 확인할 수 있다. LCS는 어렵다 ... 표로 정리하면
    이해는 되는데, 직관적이지가 않아서 힘들다 :(
    */
    int col = str1.size() - 1;
    int row = str2.size() - 1;
    std::string answer;

    while (dp[row][col]) {
        if (dp[row][col] == dp[row - 1][col])
            row--;
        else if (dp[row][col] == dp[row][col - 1])
            col--;
        else {
            answer += str2[row];
            col--;
            row--;
        }
    }

    std::cout << dp[str2.size() - 1][str1.size() - 1] << "\n";
    for (int i = answer.size() - 1; i >= 0; --i) {
        std::cout << answer[i];
    }

    return 0;
}