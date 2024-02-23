#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;
/*
계단은 한 번에 한 계단씩 또는 두 계단씩 오를 수 있다. 즉, 한 계단을 밟으면서 이어서 다음 계단이나, 다음 다음 계단으로 오를 수 있다.
연속된 세 개의 계단을 모두 밟아서는 안 된다. 단, 시작점은 계단에 포함되지 않는다.
마지막 도착 계단은 반드시 밟아야 한다.
*/
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int stairs_num = 0;
    cin >> stairs_num;
    vector<int> scores(stairs_num);
    vector<vector<int>> dp(stairs_num, vector<int>(3)); // 이전 계단을 밟았는지 여부가 이후의 해에 영향을 주므로 2차원 배열로 관리
    // dp[i][0] = i번째 계단을 밟지 않았을 때
    // dp[i][1] = i번째 계단을 밟고, 그 이전 계단은 밟지 않았을 때
    // dp[i][2] = i번째 계단을 밟고, 그 이전 계단도 밟았을 때

    for (int i = 0; i < stairs_num; ++i) {
        cin >> scores[i];
    }

    dp[0][1] = scores[0];
    dp[0][2] = 0; // 불가능하기에

    if (stairs_num > 1) {
        dp[1][1] = scores[1];
        dp[1][2] = scores[0] + scores[1];
    }

    for (int i = 2; i < stairs_num; ++i) {
        // i번째 계단을 밟고, 그 이전 계단은 밟지 않는 경우
        dp[i][1] = max(dp[i - 2][1], dp[i - 2][2]) + scores[i];
        // i번째 계단을 밟고, 그 이전 계단도 밟는 경우
        dp[i][2] = dp[i - 1][1] + scores[i];
    }

    cout << max(dp[stairs_num - 1][1], dp[stairs_num - 1][2]);
    return 0;
}