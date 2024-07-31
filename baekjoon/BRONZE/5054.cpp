// 백준: 주차의 신
// https://www.acmicpc.net/problem/5054
// 2024-07-31

/*
차를 주차하고 다시 돌아와야 하기 때문에. 어디에 주차하든 항상 답은 가장 가까이 있는 상점과 가장 멀리 있는 상점의 거리 * 2 다.
*/

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        int n; // 상점의 수 n
        cin >> n;
        int sum = 0;
        int min_pos = 100;
        int max_pos = 0;
        for (int i = 0; i < n; ++i) {
            int pos;
            cin >> pos;
            min_pos = min(min_pos, pos);
            max_pos = max(max_pos, pos);
        }
        cout << (max_pos - min_pos) * 2 << "\n";
    }
    return 0;
}