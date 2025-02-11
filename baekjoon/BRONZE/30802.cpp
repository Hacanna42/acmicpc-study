// 백준: 웰컴 키트
// https://www.acmicpc.net/problem/30802
// 2025-02-11

#include <cmath>
#include <iostream>
using namespace std;

int main() {
    int N;
    cin >> N;        // 참가자의 수 N
    int t_orders[6]; // 각 사이즈별 신청자 수를 담은 배열
    for (int i = 0; i < 6; ++i) {
        cin >> t_orders[i];
    }

    int T, P;
    cin >> T >> P; // 티셔츠와 펜의 묶음 수

    int t_order_count = 0;
    int p_unit_order_count = 0;

    // 티셔츠 구매 개수 계산
    for (int order_count : t_orders) {
        t_order_count += (order_count + T - 1) / T;
    }

    // 결과 출력
    cout << t_order_count << "\n";
    cout << N / P << " " << N % P << endl;

    return 0;
}