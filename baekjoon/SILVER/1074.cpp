// 백준: Z
// https://www.acmicpc.net/problem/1074
// 2024-04-26

#include <iostream>
using namespace std;

int solve(int n, int r, int c) {
    // 기저 조건
    if (n == 0) {
        return 0;
    }
    int half = 1 << (n - 1); // n-1의 거듭 제곱 구하기 (절반)
    int size = half * half;  // 한 분면의 크기

    if (r < half && c < half) { // 왼쪽 상단
        return solve(n - 1, r, c);
    } else if (r < half && c >= half) { // 오른쪽 상단
        return size + solve(n - 1, r, c - half);
    } else if (r >= half && c < half) { // 왼쪽 하단
        return 2 * size + solve(n - 1, r - half, c);
    } else { // 오른쪽 하단
        return 3 * size + solve(n - 1, r - half, c - half);
    }
}

int main() {
    int N, r, c;
    cin >> N >> r >> c;
    cout << solve(N, r, c);
    return 0;
}