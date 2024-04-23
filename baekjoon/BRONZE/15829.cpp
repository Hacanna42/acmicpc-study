// 백준: Hashing
// https://www.acmicpc.net/problem/15829
// 2024-04-23

#define r 31
#define M 1'234'567'891
#include <iostream>
using namespace std;
typedef long long ll;

ll p(ll base, ll exp) {
    ll result = 1;
    while (exp != 0) {
        if (exp % 2 == 1)
            result = (base * result) % M;
        base = (base * base) % M;
        exp /= 2;
    }
    return result;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int L;
    cin >> L;
    ll result = 0;
    for (int i = 0; i < L; ++i) {
        char next;
        cin >> next;
        result += ((ll)(next - '`') * (ll)p(r, i)) % M;
        result %= M;
    }

    cout << result;

    return 0;
}