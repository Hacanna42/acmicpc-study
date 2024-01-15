// 백준: 행렬 제곱
// https://www.acmicpc.net/problem/10830
// 2024-01-15

#include <iostream>
#include <vector>
#define MOD 1000;

std::vector<std::vector<long long>> A;
std::vector<std::vector<long long>> AA;

long long N, B;

void input();
void solution();

void matMul(std::vector<std::vector<long long>> &C,
            const std::vector<std::vector<long long>> &A,
            const std::vector<std::vector<long long>> &B) {
    std::vector<std::vector<long long>> temp(N, std::vector<long long>(N, 0));
    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < N; ++j) {
            for (long long k = 0; k < N; ++k) {
                temp[i][j] = (temp[i][j] + (long long)A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    C = temp;
}

void power(std::vector<std::vector<long long>> &A, long long B) {
    std::vector<std::vector<long long>> result(N, std::vector<long long>(N, 0));
    // 단위 행렬로 초기화
    for (long long i = 0; i < N; ++i) result[i][i] = 1;

    while (B > 0) {
        if (B % 2 == 1) matMul(result, result, A);
        matMul(A, A, A);
        B /= 2;
    }
    A = result;
}

void input() {
    std::cin >> N >> B;
    A.assign(N, std::vector<long long>(N));
    AA.assign(N, std::vector<long long>(N));
    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < N; ++j) {
            std::cin >> A[i][j];
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    input();
    power(A, B);
    AA = A;
    for (long long i = 0; i < N; ++i) {
        for (long long j = 0; j < N; ++j) {
            std::cout << AA[i][j] << " ";
        }
        std::cout << std::endl;
    }
    return 0;
}
