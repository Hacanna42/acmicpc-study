// 백준: 공
// https://www.acmicpc.net/problem/1547
// 2024-10-28

#include <algorithm>
#include <iostream>
using namespace std;

int main() {
    int M, A, B;
    cin >> M;

    int ball[] = {0, 1, 0, 0};

    for (int i = 0; i < M; i++) {
        cin >> A >> B;
        swap(ball[A], ball[B]);
    }

    for (int i = 1; i < 4; i++) {
        if (ball[i] == 1)
            cout << i;
    }

    return 0;
}