#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int TC;
    cin >> TC;

    ll dp[101] = {-1, 1, 1, 1};
    for (int i = 4; i <= 100; ++i) {
        dp[i] = dp[i - 2] + dp[i - 3];
    }

    for (int i = 0; i < TC; ++i) {
        int N;
        cin >> N;
        cout << dp[N] << "\n";
    }
    return 0;
}