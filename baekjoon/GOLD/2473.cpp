// 백준: 세 용액
// https://www.acmicpc.net/problem/2473
// 2024-06-29

/*
전형적인 투 포인터 문제의 변형
세개의 포인터를 선언: i, j, k
i를 고정시켜 놓고 j와 k를 이용해서 투 포인터 탐색.
*/

#include <algorithm>
#include <cmath>
#include <iostream>
#include <limits.h>
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N; // 용액의 수
    cin >> N;
    vector<ll> liquid(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> liquid[i];
    }

    sort(liquid.begin(), liquid.end());

    bool stop = false;           // 플래그
    ll known_answer = LLONG_MAX; // (~0U >> 2)로 최댓값을 설정하면 안된다.. (INT_MAX) liquid 3개를 합치면 INT_MAX를 넘을 수 있다.
    tuple<ll, ll, ll> ans_liquid;

    for (ll i = 0; i < N - 2 && !stop; ++i) {
        ll j = i + 1; // i의 바로 다음
        ll k = N - 1; // 마지막 용액
        while (j < k) {
            ll mix_value = liquid[i] + liquid[j] + liquid[k];

            // 정답 갱신
            if (known_answer > abs(mix_value)) { // mix_value가 알려진 정답보다 0에 가깝다면
                ans_liquid = tie(liquid[i], liquid[j], liquid[k]);
                known_answer = abs(mix_value);
            }

            if (mix_value > 0) {
                --k;
            } else {
                ++j;
            }
        }

        if (known_answer == 0) {
            stop = true;
            break;
        }
    }

    cout << get<0>(ans_liquid) << " " << get<1>(ans_liquid) << " " << get<2>(ans_liquid);

    return 0;
}