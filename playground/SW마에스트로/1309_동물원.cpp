#include <iostream>
using namespace std;

int main() {
    int dp[100001] = {1, 3};
    int N;
    cin >> N;
    for (int i = 2; i <= N; ++i) {
        dp[i] = (dp[i - 1] * 2 + dp[i - 2]) % 9901;
    }
    cout << dp[N];
    return 0;
}