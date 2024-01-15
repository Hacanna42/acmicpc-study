// 백준: 피보나치 수 6
// https://www.acmicpc.net/problem/11444
// 2024-01-15

#include <iostream>
#include <vector>
#define MOD 1000000007

void matMul(std::vector<std::vector<long long> >& C,
            const std::vector<std::vector<long long> >& A,
            const std::vector<std::vector<long long> >& B);
void power(std::vector<std::vector<long long> >& A, long long B);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::vector<std::vector<long long> > A(2, std::vector<long long>(2));
    A[0][0] = 1;
    A[0][1] = 1;
    A[1][0] = 1;
    A[1][1] = 0;
    long long N;
    std::cin >> N;
    power(A, N);
    std::cout << A[0][1];
    return 0;
}

void matMul(std::vector<std::vector<long long> >& C,
            const std::vector<std::vector<long long> >& A,
            const std::vector<std::vector<long long> >& B) {
    std::vector<std::vector<long long> > temp(2, std::vector<long long>(2));
    for (long long i = 0; i < 2; ++i) {
        for (long long j = 0; j < 2; ++j) {
            for (long long k = 0; k < 2; ++k) {
                temp[i][j] = (temp[i][j] + (long long)A[i][k] * B[k][j]) % MOD;
            }
        }
    }
    C = temp;
}

void power(std::vector<std::vector<long long> >& A, long long B) {
    std::vector<std::vector<long long> > result(2,
                                                std::vector<long long>(2, 0));
    // 단위 행렬 초기화
    result[0][0] = 1;
    result[1][1] = 1;

    while (B > 0) {
        if (B % 2 == 1) matMul(result, result, A);
        matMul(A, A, A);
        B /= 2;
    }
    A = result;
}