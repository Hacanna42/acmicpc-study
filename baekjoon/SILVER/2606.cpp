// 백준: 바이러스
// https://www.acmicpc.net/problem/2606
// 2024-01-19
// 미해결 - 내일

#include <iostream>
#include <set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    std::set<int> set;
    set.insert(1);
    for (int i = 0; i < M; ++i) {
        int a, b;
        std::cin >> a >> b;
        if (set.find(a) != set.end()) {
            set.insert(b);
        }
    }
    std::cout << set.size() - 1;
    return 0;
}