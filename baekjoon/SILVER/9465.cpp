// 백준: 스티커
// https://www.acmicpc.net/problem/9465
// 2024-05-16

/*
풀기전에 데이터의 크기를 봤어야 했다. 완전 탐색으로는 풀 수 없다.
DP로 풀어야 한다.

현재의 선택이 미래에 어떤 영향을 미치는 지 생각해야 한다.
매 분기점마다 두가지의 선택을 할 수 있다: 현재 열 c의 위쪽 스티커를 떼거나, 아래쪽 스티커를 떼거나
현재 열의 위쪽 스티커를 뗀다면, 다음 열에서는 위쪽 스티커를 뗄 수 없다. 따라서 현재 열에서 위쪽 스티커를 뗀다면, 이전 열의 위쪽 스티커를 뗀 최댓값을 사용하면 안된다.
그렇다고 이전 열의 아래쪽 스티커를 뗀 최댓값을 무조건 사용해도 안된다. 왜냐하면, 현재 열의 위쪽 스티커를 떼면 이전 열은 아래 스티커를 떼는 게 확정이라고 착각하기 쉽지만,
현재 열의 위쪽 스티커를 뗀 것으로 인해 이전 열의 아래 스티커를 떼면, 결국엔 전-전-열의 아래 스티커를 뗄 수 없기 때문에, 전-전-열의 아래 스티커가 높은 점수를 가진 경우
중간 열의 스티커 위쪽, 아래쪽을 모두 떼지 않는 방법이 유효할 수 있기 때문이다.

즉.
1. 현재 행의 위쪽 스티커를 떼고, 다음 행의 아래쪽 스티커를 떼거나
2. 현재 행의 아래쪽 스티커를 떼고, 다음 행의 위쪽 스티커를 떼거나
3. 현재 행의 위쪽 스티커를 떼고, 다음 행을 뜯지 않고, 다다음 행의 아래쪽 스티커를 떼거나 (만약 중간 행의 스티커를 뜯는다면 무조건 아래쪽이었을 거고, 그러면 끝 행의 아래쪽 스티커를 뗄 수없다)
4. 현재 행의 아래쪽 스티커를 떼고, 다음 행을 뜯지 않고, 다다음 행의 위쪽 스티커를 떼거나.

총 4개의 방법이 있다.

따라서
dp[0][c] = 마지막으로 위쪽 스티커를 뗐을 때의 최댓값.
dp[1][c] = 마지막으로 아래쪽 스티커를 뗐을 때의 최솟값.

dp[0][c] = max(dp[1][c-1], dp[1][c-2]) + 현재 스티커 점수
dp[1][c] = max(dp[0][c-1], dp[0][c-2]) + 현재 스티커 점수
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        int n;
        cin >> n;
        vector<vector<int>> sticker(2, vector<int>(n));
        vector<vector<int>> dp(2, vector<int>(n));
        for (int r = 0; r < 2; ++r) { // 스티커는 2*n 사이즈
            for (int c = 0; c < n; ++c) {
                cin >> sticker[r][c];
            }
        }

        // BASE CASE
        dp[0][0] = sticker[0][0]; // 위 스티커를 뗀 값
        dp[1][0] = sticker[1][0]; // 아래 스티커를 뗀 값

        if (n > 1) {
            dp[0][1] = sticker[1][0] + sticker[0][1];
            dp[1][1] = sticker[0][0] + sticker[1][1];
        }

        for (int c = 2; c < n; ++c) {
            dp[0][c] = sticker[0][c] + max(dp[1][c - 1], dp[1][c - 2]);
            dp[1][c] = sticker[1][c] + max(dp[0][c - 1], dp[0][c - 2]);
        }

        cout << max(dp[0][n - 1], dp[1][n - 1]) << "\n";
    }
    return 0;
}