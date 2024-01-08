// 백준: N과 M (4)
// https://www.acmicpc.net/problem/15652
// 2024-01-08

#include <iostream>
#include <vector>
int N, M;
int arr[9] = {
    0,
};
int visitCounter[9] = {
    0,
};
int lastSelected = 1;

void dfs(int L) {
    if (L == M) {
        for (int i = 0; i < M; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return;
    }
    for (int i = lastSelected; i <= N; ++i) {
        if (visitCounter[i] < M) {
            visitCounter[i]++;
            arr[L] = i;
            lastSelected = i;
            dfs(L + 1);
            visitCounter[i] = 0;
        }
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N >> M;
    dfs(0);
    return 0;
}