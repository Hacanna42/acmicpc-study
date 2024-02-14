#include <algorithm>
#include <string>
#include <vector>
using namespace std;

/*
첫번째 집을 터는 경우와, 두번째 집을 터는 경우를 동시에 고려하지 않고
나눠서 고려한다.
동시에 고려하면 dp를 2차원 벡터로 써야해서 TLE가 난다.
*/

int solution(vector<int> money) {
    int n = money.size();
    vector<int> dp(n);

    // 먼저, 첫번째 집을 터는 경우
    dp[0] = money[0];
    dp[1] = money[0];                 // 두번째 집은 털 수 없다.
    for (int i = 2; i < n - 1; ++i) { // N-2까지(마지막 집은 털 수 없으니까)
                                      // 루프를 돌리면서 현재 집을 터는 것이 이득인지, 스킵이 이득인지 판단
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);
    }

    // answer 변수에 첫번째 집을 터는 경우의 최댓값을 저장
    int answer = dp[n - 2];

    // 이제, 첫번째 집을 안 터는 경우
    dp[0] = 0;
    dp[1] = money[1];

    for (int i = 2; i < money.size(); ++i) // 마지막 집을 털 수 있으니까, 마지막 인덱스까지 루프
        dp[i] = max(dp[i - 2] + money[i], dp[i - 1]);

    answer = max(answer, dp[money.size() - 1]); // 첫번째 집을 턴 경우와, 안 턴 경우의 두가지 우주 중 더 큰 값을 반환

    return answer;
}