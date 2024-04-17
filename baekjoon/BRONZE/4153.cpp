// 백준: 직각삼각형
// https://www.acmicpc.net/problem/4153
// 2024-04-18

#include <algorithm>
#include <iostream>
using namespace std;
typedef long long ll;

int pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result *= base;
        }
        base *= base;
        exp /= 2;
    }
    return result;
}

int main() {
    while (true) {
        int a, b, c;
        cin >> a >> b >> c;
        if (a == 0 && b == 0 && c == 0)
            return 0;
        int max_len = pow(max({a, b, c}), 2);
        int compare_len = 0;
        compare_len += pow(a, 2);
        compare_len += pow(b, 2);
        compare_len += pow(c, 2);
        cout << (compare_len == max_len * 2 ? "right\n" : "wrong\n");
    }
    return 0;
}