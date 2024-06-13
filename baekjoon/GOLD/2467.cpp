// 백준: 용액
// https://www.acmicpc.net/problem/2467
// 2024-06-13

/*
투 포인터 접근법: 두 인덱스를 적절히 바꿔가며 탐색
abs를 적용하지 않은 용액값의 합이 양수면 좀 더 낮은 수치의 산성 용액을 사용해야 함을, 음수면 좀 더 낮은 수치의 알칼리성 용액을 사용해야 함을 의미한다.
*/
#include <cmath>
#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N;
    vector<int> liquid(N);
    for (int i = 0; i < N; ++i) {
        cin >> liquid[i];
    }

    int i = 0, j = N - 1; // 인덱스
    int ans_i = i, ans_j = j;
    int known_small_value = abs(liquid[i] + liquid[j]);
    while (i < j) {
        int cur_value = liquid[i] + liquid[j];
        if (abs(cur_value) < known_small_value) {
            ans_i = i;
            ans_j = j;
            known_small_value = abs(cur_value);
        }
        if (cur_value > 0)
            --j;
        else
            ++i;
    }

    cout << liquid[ans_i] << " " << liquid[ans_j];
    return 0;
}