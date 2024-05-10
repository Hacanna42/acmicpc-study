// 백준: 가장 가까운 세 사람의 심리적 거리
// https://www.acmicpc.net/problem/20529
// 2024-05-07

/*
1. 브루트포스 사용
2. N이 32 초과라면, 답은 무조건 0임 (비둘기집의 원리)
MBTI의 유형 수는 총 16개고, 인원이 17명이라면 하나의 유형은 최소 2명 이상의 공통 MBTI를 가진다.
*/

#include <iostream>
#include <string>
#include <vector>
using namespace std;

int getDiff(string a, string b) {
    int diff = 0;
    for (int i = 0; i < 4; ++i) {
        if (a[i] != b[i])
            ++diff;
    }
    return diff;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);

    int TC;
    cin >> TC;
    while (TC--) {
        int N; // 학생의 수
        cin >> N;

        vector<string> mbtis(N);

        // 입력
        for (int i = 0; i < N; ++i) {
            string mbti;
            cin >> mbti;
            mbtis[i] = mbti;
        }

        // 비둘기집의 원리 필터링
        if (N > 32) {
            cout << "0\n";
            continue;
        }

        // 계산
        int minDistance = (~0U >> 2);
        for (int i = 0; i < N; ++i) {
            for (int j = i + 1; j < N; ++j) {
                for (int k = j + 1; k < N; ++k) {
                    int cur_dist = getDiff(mbtis[i], mbtis[j]) + getDiff(mbtis[j], mbtis[k]) + getDiff(mbtis[i], mbtis[k]);
                    if (cur_dist < minDistance)
                        minDistance = cur_dist;
                }
            }
        }

        cout << minDistance << "\n";
    }
}