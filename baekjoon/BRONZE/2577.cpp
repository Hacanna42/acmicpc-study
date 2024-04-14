// 백준: 숫자의 개수
// https://www.acmicpc.net/problem/2577
// 2024-04-14

#include <iostream>
#include <string>
using namespace std;

int main() {
    int count[10] = {
        0,
    };
    int A, B, C;
    cin >> A >> B >> C;
    string t = to_string(A * B * C);
    for (int i = 0; i < t.length(); ++i) {
        count[(t[i] - '0')]++;
    }

    for (const int i : count) {
        cout << i << "\n";
    }
    return 0;
}