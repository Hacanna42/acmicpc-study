#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

// 교육적 의미로 구현 (이분탐색을 이용한 LIS)
int LIS(const vector<int> &nums) {
    vector<int> lis;
    for (int num : nums) {
        auto it = lower_bound(lis.begin(), lis.end(), num);
        if (it == lis.end())
            lis.push_back(num);
        else
            *it = num;
    }
    return lis.size();
}

int main() {
    int N;
    cin >> N;
    vector<int> dp(N, 1);
    vector<int> lis(N);
    for (int i = 0; i < N; ++i) {
        cin >> lis[i];
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < i; ++j) {
            if (lis[j] < lis[i])
                dp[i] = max(dp[j] + 1, dp[i]);
        }
    }

    cout << *max_element(dp.begin(), dp.end());
    // cout << LIS(lis);
    return 0;
}