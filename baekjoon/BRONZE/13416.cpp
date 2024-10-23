// 백준: 주식 투자
// https://www.acmicpc.net/problem/13416
// 2024-10-23

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        int T;
        cin >> T;
        ll sum = 0;
        while (T--) {
            ll A, B, C;
            cin >> A >> B >> C;
            sum += max({A, B, C, 0ll});
        }
        cout << sum << "\n";
    }
    return 0;
}