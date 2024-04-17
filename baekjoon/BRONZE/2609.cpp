// 백준: 최대공약수와 최소공배수
// https://www.acmicpc.net/problem/2609
// 2024-04-18

#include <iostream>
// #include <numeric>
using namespace std;
typedef long long ll;

ll gcd(ll a, ll b) {
    while (b != 0) {
        ll t = b;
        b = a % b;
        a = t;
    }
    return a;
}

ll lcm(ll a, ll b) { return a / gcd(a, b) * b; }

int main() {
    ll a, b;
    cin >> a >> b;
    cout << gcd(a, b) << "\n" << lcm(a, b);
    return 0;
}