// 백준: 조화평균
// https://www.acmicpc.net/problem/2090
// 2024-02-18

#include <iostream>
#include <numeric>

using namespace std;
typedef long long ll;

// 연습 겸 구현
int gcd(int a, int b) { return b == 0 ? a : gcd(b, a % b); }

int lcm(int a, int b) { return a / gcd(a, b) * b; }

int main() {
    ll N;
    cin >> N;
    ll A[N];
    ll denominator = 1; // 분모 초기화
    for (ll i = 0; i < N; ++i) {
        cin >> A[i];
        // 최소공배수를 계산하여 분모 업데이트
        denominator = lcm(denominator, A[i]);
    }

    ll numerator = 0;
    for (ll i = 0; i < N; ++i) {
        numerator += denominator / A[i];
    }
    int temp = gcd(denominator, numerator);
    denominator /= temp;
    numerator /= temp;
    cout << denominator << "/" << numerator;

    return 0;
}
