// 백준: 행렬 곱셈
// https://www.acmicpc.net/problem/2740
// 2024-01-15

#include <iostream>
#include <vector>

std::vector<std::vector<int> > A;
std::vector<std::vector<int> > B;
std::vector<std::vector<long long> > AB;
int AN, AM;
int BM, BK;
void input();
void solution();
void answer();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    input();
    solution();
    answer();
    return 0;
}

void answer() {
    for (int i = 1; i <= AN; ++i) {
        for (int j = 1; j <= BK; ++j) {
            std::cout << AB[i][j] << " ";
        }
        std::cout << std::endl;
    }
}

void solution() {
    AB.assign(AN + 1, std::vector<long long>(BK + 1));
    for (int i = 1; i <= AN; ++i) {
        for (int j = 1; j <= BK; ++j) {
            for (int k = 1; k <= AM; ++k) {
                AB[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

void input() {
    std::cin >> AN >> AM;
    A.assign(AN + 1, std::vector<int>(AM + 1));
    for (int i = 1; i <= AN; ++i) {
        for (int j = 1; j <= AM; ++j) {
            std::cin >> A[i][j];
        }
    }
    std::cin >> BM >> BK;
    B.assign(BM + 1, std::vector<int>(BK + 1));
    for (int i = 1; i <= BM; ++i) {
        for (int j = 1; j <= BK; ++j) {
            std::cin >> B[i][j];
        }
    }
}