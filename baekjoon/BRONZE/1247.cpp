// 백준: 부호
// https://www.acmicpc.net/problem/1247
// 2024-07-26

// 언더플로우와 오버플로우 횟수를 기록한다. 오버 플로우가 더 많이 났다면 양수, 반대면 음수.
// 더할 수와 현재 합계가 양수인데, 더했을때 음수가 되면 오버 플로우, 반대면 언더 플로우.

#include <iostream>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int loop = 3;
    while (loop--) {
        ll N;
        cin >> N;
        ll flow = 0;
        ll sum = 0;
        for (int i = 0; i < N; ++i) {
            ll n;
            cin >> n;
            ll prev = sum;
            sum += n;
            if (n > 0 && prev > 0 && sum < 0)
                flow++;
            if (n < 0 && prev < 0 && sum > 0)
                flow--;
        }

        if (flow == 0) {
            if (sum == 0)
                cout << "0\n";
            else
                cout << (sum > 0 ? "+\n" : "-\n");
        } else {
            cout << (flow > 0 ? "+\n" : "-\n");
        }
    }
    return 0;
}