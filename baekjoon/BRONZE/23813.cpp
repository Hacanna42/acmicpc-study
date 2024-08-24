// 백준: 회전
// https://www.acmicpc.net/problem/23813
// 2024-08-24
// 미완

#include <cmath>
#include <iostream>
#include <string>
using namespace std;
typedef long long ll;

int getFirstDigit(int n) {
    while (n >= 10) {
        n /= 10;
    }
    return n;
}

int main() {
    int N;
    cin >> N;
    int len = to_string(N).length() - 1;
    int cur = N;

    ll answer = 0;
    // while (true) {
    cur -= pow(10, len) * getFirstDigit(cur);
    cout << cur;

    // }
    return 0;
}