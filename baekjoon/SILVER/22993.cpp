// 백준: 서든어택 3
// https://www.acmicpc.net/problem/22993
// 2024-03-29

#include <algorithm>
#include <iostream>
#include <vector>
typedef long long ll;
using namespace std;

int main() {
    ll joonPower;
    int N;
    cin >> N;
    vector<ll> powers(N - 1, 0);

    cin >> joonPower;

    for (int i = 0; i < N - 1; ++i) {
        cin >> powers[i];
    }

    sort(powers.begin(), powers.end());

    // 가장 작은 플레이어의 힘을 흡수하면서 끝까지 싸운다
    for (int i = 0; i < N - 1; ++i) {
        if (joonPower > powers[i]) { // 준원이가 이겼다면
            joonPower += powers[i];  // 파워 흡수하고 다음으로 스킵
        } else {
            cout << "No";
            return 0;
        }
    }

    cout << "Yes";
    return 0;
}