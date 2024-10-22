// 백준: 수열
// https://www.acmicpc.net/problem/2491
// 2024-10-22

#include <algorithm>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N;
    cin >> N;
    vector<int> arr(N);
    // 입력
    for (int i = 0; i < N; ++i) {
        cin >> arr[i];
    }

    vector<int> inc(N, 1);
    vector<int> dec(N, 1);

    for (int i = 1; i < N; ++i) {
        if (arr[i] >= arr[i - 1]) { // 증가
            inc[i] = inc[i - 1] + 1;
        }

        if (arr[i] <= arr[i - 1]) { // 감소
            dec[i] = dec[i - 1] + 1;
        }
    }

    int max_inc = *max_element(inc.begin(), inc.end());
    int max_dec = *max_element(dec.begin(), dec.end());
    cout << max(max_inc, max_dec);
    return 0;
}