// 백준: 숫자
// https://www.acmicpc.net/problem/10093
// 2024-10-15

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    ll A, B;
    cin >> A >> B;

    ll _min = std::min(A, B);
    ll _max = std::max(A, B);

    cout << ((_max - _min - 1 != -1) ? _max - _min - 1 : 0) << "\n";
    for (ll i = _min + 1; i < _max; ++i) {
        cout << i << " ";
    }

    return 0;
}