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
#include <tuple>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    int N; // 용액의 수
    cin >> N;
    vector<int> liquid(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> liquid[i];
    }

    sort(liquid.begin(), liquid.end());

    bool stop = false; // 플래그
    ll known_answer = (~0U >> 2);
    tuple<int, int, int> ans_liquid;

    for (ll i = 0; i < N - 2 && !stop; ++i) {
        ll j = i + 1; // i의 바로 다음
        ll k = N - 1; // 마지막 용액
        while (j < k) {
            int mix_value = liquid[i] + liquid[j] + liquid[k];

            // 정답 갱신
            if (known_answer > abs(mix_value)) { // mix_value가 알려진 정답보다 0에 가깝다면
                ans_liquid = tie(i, j, k);
                known_answer = abs(mix_value);
            }

            if (mix_value > 0) {
                --k;
            } else if (mix_value < 0) {
                ++j;
            }
        }

        if (known_answer == 0) { // 최적의 정답을 찾으면 더 이상 탐색 진행 의미 X
            stop = true;
        }
    }

    for (int i = 0; i < 3; ++i) {
        cout << get<i>(ans_liquid) << " ";
    }

    return 0;
}