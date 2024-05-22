// 백준: 내려가기
// https://www.acmicpc.net/problem/2096
// 2024-05-22

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<vector<int>> score(3, vector<int>(N, 0)); // xy 체계
    for (int y = 0; y < N; ++y) {
        for (int x = 0; x < 3; ++x) {
            cin >> score[x][y];
        }
    }

    vector<int> max_dp(3, 0);
    vector<int> min_dp(3, 0);

    for (int i = 0; i < 3; ++i) {
        max_dp[i] = score[i][0];
        min_dp[i] = score[i][0];
    }

    /*
     MLE를 받지 않으려면 dp를 1차원 배열로 해야될 것 같다.

     길이가 3인 일차원 배열: max_dp와 min_dp를 선언하고 각각 현재 층의 각 왼쪽 / 중앙 / 오른쪽 요소를 갖도록 한다
     매 분기마다 max_dp와 min_dp에 저장되어 있는 값과 입력받은 값을 비교하며 업데이트 해나간다.

     PS. 이러한 최적화 방법을 '토글링'이라고 한다. 점화식이 이전해만을 필요로 할때 유용하다.
    */

    for (int y = 1; y < N; ++y) {
        int prev_max[3] = {max_dp[0], max_dp[1], max_dp[2]};
        int prev_min[3] = {min_dp[0], min_dp[1], min_dp[2]};

        max_dp[0] = max(prev_max[0], prev_max[1]) + score[0][y];
        max_dp[1] = max({prev_max[0], prev_max[1], prev_max[2]}) + score[1][y];
        max_dp[2] = max(prev_max[1], prev_max[2]) + score[2][y];

        min_dp[0] = min(prev_min[0], prev_min[1]) + score[0][y];
        min_dp[1] = min({prev_min[0], prev_min[1], prev_min[2]}) + score[1][y];
        min_dp[2] = min(prev_min[1], prev_min[2]) + score[2][y];
    }

    cout << max({max_dp[0], max_dp[1], max_dp[2]}) << " " << min({min_dp[0], min_dp[1], min_dp[2]});
    return 0;
}