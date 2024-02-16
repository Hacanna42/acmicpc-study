// 백준: 인공지능 시계
// https://www.acmicpc.net/problem/2530
// 2024-02-16

#include <iostream>
using namespace std;

int main() {
    int A, B, C, D;
    cin >> A >> B >> C >> D;

    int totalSeconds = A * 3600 + B * 60 + C + D;
    A = (totalSeconds / 3600) % 24;
    B = (totalSeconds % 3600) / 60;
    C = totalSeconds % 60;

    cout << A << " " << B << " " << C;
    return 0;
}
