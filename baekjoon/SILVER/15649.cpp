// 백준: N과 M(1)
// https://www.acmicpc.net/problem/15649
// 2024-01-08

#include <iostream>
#include <vector>

int N, M;
int arr[9] = {
    0,
};
bool visited[9] = {
    0,
};

void dfs(int L) {
    if (L == M) {
        for (int i = 0; i < M; ++i) {
            std::cout << arr[i] << " ";
        }
        std::cout << "\n";
        return;
    }
    for (int i = 1; i <= N; ++i) {
        if (!visited[i]) {
            visited[i] = true;
            arr[L] = i;
            dfs(L + 1);
            visited[i] = false;
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