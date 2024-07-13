// 백준: 단어 퍼즐
// https://www.acmicpc.net/problem/9946
// 2024-07-12

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int i = 0;
    while (++i) {
        string a, b;
        cin >> a >> b;
        if (a == "END")
            break;
        sort(a.begin(), a.end());
        sort(b.begin(), b.end());
        cout << "Case " << i << ": " << (a == b ? "same" : "different") << "\n";
    }
    return 0;
}