// 백준: 두부 게임 (Tofu Game)
// https://www.acmicpc.net/problem/14564
// 2024-10-17

/* 문제 설명이 뭔가 부족한 것 같다.
두부 술게임을 모른다면 이해하기 힘들다.
... 처음엔 시뮬레이션으로 구현했는데*/

#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int N, M, A;
    cin >> N >> M >> A;

    int standard_mo = (M / 2) + 1; // 기준 모
    A--;

    while (true) {
        int mo;
        cin >> mo;
        if (mo == standard_mo) {
            cout << 0;
            break;
        }

        A = (N + A + mo - (M / 2) - 1) % N;
        cout << A + 1 << "\n";
    }
}