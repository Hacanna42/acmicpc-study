// 백준: 가장 긴 막대 자석
// https://www.acmicpc.net/problem/26122
// 2024-10-19

#include <algorithm>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int K;
    string S;
    cin >> K >> S;

    int count_N = 0;
    int count_S = 0;

    int answer = 0;

    for (int i = 0; i < K; ++i) {
        // 현재 문자와 이전 문자
        char cur = S[i];
        char prev = ((i != 0) ? S[i - 1] : ' ');

        // 문자 개수 카운트
        ((cur == 'N') ? ++count_N : ++count_S);

        // 문자가 전환 될 때, 이전의 동일한 극의 값은 의미 없어짐
        if (cur == 'S' && prev == 'N')
            count_S = 1;
        if (cur == 'N' && prev == 'S')
            count_N = 1;

        // 둘 중에 작은 값이, 자석이 될 수 있는 값
        answer = max(answer, min(count_N, count_S));
    }

    cout << answer * 2;
    return 0;
}