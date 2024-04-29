// 백준: 패션왕 신해빈
// https://www.acmicpc.net/problem/9375
// 2024-04-28

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

/*
1. 각 범주에서 가능한 선택지의 수를 모두 곱한다 (입지 않았을 때 포함)
2. 모두 입지 않는 (알몸) 상태는 불가하므로 -1 한다.
*/

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int N;
        cin >> N;
        unordered_map<string, int> map;
        for (int i = 0; i < N; ++i) {
            string type;
            cin.ignore(25, ' ');
            cin >> type;
            map[type]++;
        }

        int result = 1;
        for (auto it = map.begin(); it != map.end(); ++it) {
            result *= (it->second + 1);
        }

        cout << result - 1 << "\n";
    }
    return 0;
}