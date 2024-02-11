// 백준: 사각 사각
// https://www.acmicpc.net/problem/3359
// 2024-02-11

#include <algorithm>
#include <iostream>
#include <utility>
#include <vector>

using namespace std;
typedef long long ll;

int main() {
    ll n;
    cin >> n;
    vector<ll> dp(n);
    vector<ll> temp(n);
    vector<pair<ll, ll>> v(n);
    for (ll i = 0; i < n; ++i) {
        cin >> v[i].first >> v[i].second;
        if (v[i].first > v[i].second) {
            swap(v[i].first, v[i].second);
        }
    }

    // 처음 ㄱ 부분으로 초기화 (긴 부분이 윗면으로)
    dp[0] = v[0].second + v[0].first;
    temp[0] = v[0].first; // 마지막 옆에 붙은 면
    for (ll i = 1; i < n; ++i) {
        // 긴 변이 아래에 오는 경우 | 위에 오는 경우
        ll diff_f = abs(v[i].first - temp[i - 1]); // 겹치는 면
        ll diff_s = abs(v[i].second - temp[i - 1]);

        ll case_f = (dp[i - 1] - diff_f) + (v[i].first * 2) + v[i].second;
        ll case_s = (dp[i - 1] - diff_s) + (v[i].second * 2) + v[i].first;

        if (case_f >= case_s)
            temp[i] = v[i].first;
        else
            temp[i] = v[i].second;

        dp[i] = max(case_f, case_s);
    }

    cout << dp[n - 1];
    return 0;
}