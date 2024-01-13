// 백준: 체스판 다시 칠하기 2
// https://www.acmicpc.net/problem/25682
// 2024-01-13

/*
문제를 풀기 전에, 꼭 2D 누적합 알고리즘을 알아야한다.
이렇게 쉽게 구현하는 방법이 있었다니.
*/

#include <algorithm>
#include <iostream>

int N, M, K, answer = 2000001;
int prefix_sum[2001][2001];

void input();
void find();

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    input();
    find();
    std::cout << answer;
    return 0;
}

void input() {
    std::cin >> N >> M >> K;
    for (int i = 1; i <= N; ++i) {
        for (int j = 1; j <= M; ++j) {
            char color;
            std::cin >> color;
            // 색이 올바르면
            if (((i + j) % 2 != 0 && color == 'B') ||
                ((i + j) % 2 == 0 && color != 'B'))
                prefix_sum[i][j] = 1;
            // 2차원 누적합 공식
            prefix_sum[i][j] += prefix_sum[i - 1][j] + prefix_sum[i][j - 1] -
                                prefix_sum[i - 1][j - 1];
        }
    }
}

void find() {
    for (int i = K; i <= N; ++i) {
        for (int j = K; j <= M; ++j) {
            int temp = prefix_sum[i][j] - prefix_sum[i - K][j] -
                       prefix_sum[i][j - K] + prefix_sum[i - K][j - K];
            temp = std::min(K * K - temp, temp);
            answer = std::min(temp, answer);
        }
    }
}