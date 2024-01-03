// 백준: 숫자 카드 2
// https://www.acmicpc.net/problem/10816
// 2024-01-03

#include <iostream>
#include <unordered_map>

int main() {
    int N, M;
    std::unordered_map<int, int> my_cards;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        my_cards[temp]++;
    }
    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        int temp;
        std::cin >> temp;
        std::cout << my_cards[temp] << " ";
    }
    return 0;
}