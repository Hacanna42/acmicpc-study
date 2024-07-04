// 백준: 플러그
// https://www.acmicpc.net/problem/2010
// 2024-07-02
// Written on iPad

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    int plug_sum = 0;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        plug_sum += t;
    }

    cout << plug_sum - (N - 1);
    return 0;
}