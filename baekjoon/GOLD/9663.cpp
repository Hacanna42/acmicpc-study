// 백준: N-Queen
// https://www.acmicpc.net/problem/9663
// 2024-01-08

#include <iostream>
int N;
int count = 0;
int col[15] = {
    0,
};

bool isSafe(int L) {
    for (int i = 0; i < L; ++i) {
        if (col[i] == col[L] || abs(col[L] - col[i]) == L - i) return false;
    }
    return true;
}

void dfs(int L) {
    if (L == N) {
        ++count;
        return;
    }
    for (int i = 0; i < N; ++i) {
        col[L] = i;
        if (isSafe(L)) {
            // 퀸이 안전하다면 다음 레벨로
            dfs(L + 1);
        }
    }
}

int main() {
    std::cin >> N;
    dfs(0);
    std::cout << count;
    return 0;
}