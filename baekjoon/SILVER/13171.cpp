// 백준: A
// https://www.acmicpc.net/problem/13171
// 2024-02-09

#include <iostream>
using namespace std;
typedef long long ll;
#define MOD 1000000007

ll fastpow(ll A, ll X) {
    if (X == 0)
        return 1;
    else if (X == 1)
        return A;
    else if (X % 2 == 0) {
        return (fastpow(A, X / 2) % MOD) * (fastpow(A, X / 2) % MOD) % MOD;
    } else {
        return ((fastpow(A, X - 1) % MOD) * (A % MOD)) % MOD;
    }
}

int main() {
    ll A, X;
    cin >> A >> X;
    std::cout << fastpow(A, X);
    return 0;
}