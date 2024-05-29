// 백준: Σ
// https://www.acmicpc.net/problem/13172
// 2024-05-29

/*
페르마의 소정리를 지금 이해하려고 하지 말자.
결론:
1. 기약 분수 만들기 (유클리드 호제법)
2. 모듈러 역원 구하기: a*((b^x-2)%x)
*/

#include <iostream>
#include <vector>
using namespace std;
typedef unsigned long long ll;
#define X 1'000'000'007

/* 중요 !!
GCD(a, b) = A와 B의 최대공약수
r = a mod b 일때
GCD(a, b) = GCD(b, r) 이다.
*/
ll gcd(ll a, ll b) {
    while (b != 0) {
        int r = a % b;
        a = b;
        b = r;
    }
    return a;
}

ll my_pow(ll base, ll exp) {
    ll result = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            result = (result * base) % X;
        }
        base = (base * base) % X;
        exp /= 2;
    }
    return result;
}

int main() {
    int M; // 주사위의 수
    cin >> M;
    ll answer = 0;
    while (M--) {
        ll N, S; // N면체 주사위, 각 눈의 합 S
        cin >> N >> S;
        ll g = gcd(N, S); // 기약분수화
        N /= g;           // 분모 b
        S /= g;           // 분자 a
        // a * (b^X-2)%X
        answer += S * my_pow(N, X - 2) % X;
        answer %= X;
    }
    cout << answer;
    return 0;
}