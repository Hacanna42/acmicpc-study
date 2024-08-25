// 백준: 회전
// https://www.acmicpc.net/problem/23813
// 2024-08-25

#include <cmath>
#include <iostream>
#include <vector>
using namespace std;
typedef long long ll;

int main() {
    ll N;
    cin >> N;

    int original_N = N; // 원본 N 저장

    // 자리수 계산
    int digitCount = 0;
    int temp = N;
    while (temp > 0) {
        ++digitCount;
        temp /= 10;
    }

    ll answer = 0;
    // 회전
    do {
        answer += N;
        N = (N / 10) + (N % 10) * pow(10, digitCount - 1);
    } while (N != original_N);

    cout << answer;
}