// 백준: 이교수님의 시험
// https://www.acmicpc.net/problem/10874
// 2024-09-27

/*
1. 문제의 수는 총 10개이다.
2. j번째 문제의 정답은 ((j-1) % 5) + 1 이다

ps. 교육용으로 정답지 배열을 직접 생성했다.
*/

#include <iostream>
using namespace std;

int main() {
    // 정답지 배열 생성 (1, 2, 3, 4, 5..)
    int answers[10];
    for (int i = 0; i < 10; ++i) {
        int j = i + 1; // 문제는 번호 1부터 시작함.
        answers[i] = ((j - 1) % 5) + 1;
    }

    // 비교
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N; // 학생 수 N
    cin >> N;
    for (int i = 0; i < N; ++i) { // 학생 번호
        bool flag = true;
        for (int j = 0; j < 10; ++j) {
            int t;
            cin >> t;
            if (answers[j] != t)
                flag = false; // 오답이라면 flag = false
        }
        if (flag)
            cout << i + 1 << "\n"; // 오답이 없었으면 학생 번호 출력 후 개행
    }

    return 0;
}