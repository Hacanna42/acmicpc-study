// 백준: 카드 숫자 곱의 경우의 수
// https://www.acmicpc.net/problem/25370
// 2024-02-03

#include <iostream>
#include <set>

std::set<int> set;

void findCombinations(int L, int result) {
    if (L == 0) {
        set.insert(result);
        return;
    }

    for (int i = 1; i <= 9; ++i) {
        findCombinations(L - 1, result * i);
    }
}

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int n;
    std::cin >> n;
    findCombinations(n, 1);
    std::cout << set.size();
    return 0;
}