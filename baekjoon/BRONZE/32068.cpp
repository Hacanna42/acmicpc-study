// 백준: 보물 찾기
// https://www.acmicpc.net/problem/32068
// 2024-10-16

// 마지막 TC를 시뮬레이션으로 풀 수 없을 것 같다. 수학 공식을 찾아야 한다.

/*
1단계에서 바로 끝나는 경우: pos의 값이 처음부터 L이나 R일때.
2~3단계에서 끝나는 경우: +1, -1 중 하나일 때
4~5: +2, -2
6~7: +3, -3

즉 일단 pos에서 L과 R까지의 거리 중 제일 짧은 걸 구해야 함.
만약 둘 다 같다면? R일 경우 -1.
*/

#include <algorithm>
#include <cmath>
#include <iostream>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int TC;
    cin >> TC;
    while (TC--) {
        int L, R, pos;
        cin >> L >> R >> pos;
        int dist_L = abs(L - pos); // L < POS < R 이기 때문에 성립함
        int dist_R = abs(R - pos);

        if (dist_L == 0 || dist_R == 0) { // 시작부터 이미 보물의 위치에 있는 경우
            cout << "1\n";                // 1 단계 출력
            continue;
        }

        if (dist_L < dist_R) { // L이 더 가까운 경우
            cout << (dist_L * 2) + 1 << "\n";
            continue;
        }

        else if (dist_L > dist_R) { // R이 더 가까운 경우
            cout << (dist_R * 2) << "\n";
        }

        else { // 두 거리가 똑같은 경우
            cout << dist_L * 2 << "\n";
        }
    }

    return 0;
}

/* 시뮬레이션 버전
int getNextPos(int pos, int step) {
    if (step % 2 == 0) { // 짝수라면 x-1칸 이동
        return pos + (step - 1);
    } else {
        return pos - (step - 1);
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int TC;
    cin >> TC;
    while (TC--) {
        int L, R, pos;
        cin >> L >> R >> pos;

        int step = 1;
        while (true) {
            // 보물을 찾았는지 체크
            if (pos == L || pos == R)
                break;
            ++step; // 스텝 +1
            pos = getNextPos(pos, step);
        }
        cout << step << "\n";
    }
    return 0;
}
*/