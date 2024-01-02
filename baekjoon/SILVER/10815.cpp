// 백준: 숫자 카드
// https://www.acmicpc.net/problem/10815
// 2024-01-02

#include <iostream>
#include <unordered_map>

int main() {
    int N, M;
    std::unordered_map<int, int> maps;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        maps[temp] = 1;
    }
    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        int temp;
        std::cin >> temp;
        if (maps[temp])
            std::cout << "1 ";
        else
            std::cout << "0 ";
    }
    return 0;
}