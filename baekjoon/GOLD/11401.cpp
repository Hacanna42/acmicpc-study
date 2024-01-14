// 백준: 이항 계수 3
// https://www.acmicpc.net/problem/11401
// 2024-01-14

/*
1. 수가 너무 커서 연산을 분할하고 각 연산마다 모듈러를 해야함.
- 각 단계의 (덧셈, 뺄셈, 곱셈)을 모듈러 해야하는데, 모듈러 산술에서
나눗셈은 정의되지 않아서, 나눗셈이 아니라 곱셈을 해야함.
일반적인 수학에서 나눗셈은 곱셈의 역 연산 (a*b=c equal c*b=a) 인 것처럼
모듈러의 나눗셈도 역 연산을 해야함.

2. 페르마의 소정리를 이용해서 모듈러의 역원을 구하고 나눗셈을 곱셈으로
치환해야 함.
페르마의 소정리: p가 소수이면, 모든 정수 a에 대해 a^p = mod p임.
*/

#include <iostream>
#define MOD 1000000007

long long power(long long x, long long y) {
    long long result = 1;
    x = x % MOD;

    while (y > 0) {
        if (y % 2 == 1) result = (result * x) % MOD;

        y = y >> 1;
        x = (x * x) % MOD;
    }
    return result;
}

long long modInverse(long long n) { return power(n, MOD - 2); }

long long binomialCoefficient(int N, int K) {
    if (K == 0 || K == N) return 1;

    long long numerator = 1, denominator = 1;
    for (int i = 0; i < K; ++i) {
        numerator = (numerator * (N - i)) % MOD;
        denominator = (denominator * (i + 1)) % MOD;
    }
    return (numerator * modInverse(denominator)) % MOD;
}

int main() {
    int N, K;
    std::cin >> N >> K;
    std::cout << binomialCoefficient(N, K);
    return 0;
}
