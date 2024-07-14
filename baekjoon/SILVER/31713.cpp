// 백준: 행운을 빌어요
// https://www.acmicpc.net/problem/31713
// 2024-07-13

/*
은근 헷갈렸던 수학, 브루트포스 문제.
*/

#include <iostream>
using namespace std;

bool check(int &stem, int &leaf) { // 현재 줄기와 잎 개수가 올바른지 체크
    return stem * 3 <= leaf && stem * 4 >= leaf;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int T;
    cin >> T;
    while (T--) {
        int stem, leaf; // 클로버 줄기와 잎 개수
        cin >> stem >> leaf;

        /*
        1. 모든 줄기에 잎을 3개씩 붙이면 부족하거나 같지만,
        몇개를 4개로 붙이면 가능한 경우 (즉 stem*3 <= leaf &&
        stem*4 >= leaf) 추가 0개로 완료

        1번이 false일 때 잎이 부족한 경우와 줄기가 부족한 경우로 나뉨
        잎 부족(stem*3 > leaf): stem*3-leaf만큼 잎 보충 후 1번
        줄기 부족(stem*4 < leaf): bruteforce로 stem을 하나씩 추가하면서
        1번 확인(check 함수), false면 잎 부족인지 줄기 부족인지 확인, 줄기 부족이면 계속 stem 추가.
        잎 부족이면 stem*3-leaf만큼 잎 보충
        */

        int answer = 0;
        while (true) {
            if (check(stem, leaf)) { // 현재 줄기와 잎으로 가능한지 체크
                cout << answer << "\n";
                break; // 정답 출력 후 종료
            } else {
                if (stem * 3 > leaf) {           // 잎이 부족함
                    answer += (stem * 3) - leaf; // 정답 업데이트 (잎 보충 개수만큼)
                    leaf += (stem * 3) - leaf;   // 실제 변수에 잎 보충
                } else if (stem * 4 < leaf) {    // 줄기가 부족함
                    ++stem;                      // 줄기 하나 추가
                    ++answer;                    // 정답 업데이트 (하나 추가함)
                }
            }
        }
    }
}