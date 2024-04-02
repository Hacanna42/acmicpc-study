// 백준: 성택이의 은밀한 비밀번호
// https://www.acmicpc.net/problem/25372
// 2024-03-31

#include <iostream>
#include <string>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        string t;
        cin >> t;
        cout << ((t.length() >= 6 && t.length() <= 9) ? "yes\n" : "no\n");
    }
    return 0;
}