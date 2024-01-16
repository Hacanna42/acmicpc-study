// 백준: 나무 자르기
// https://www.acmicpc.net/problem/2805
// 2024-01-16

#include <iostream>
#include <vector>
std::vector<int> trees;

int binary_search(std::vector<int>& trees, long long high, int target);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M;
    long long max = 0;
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        long long temp;
        std::cin >> temp;
        if (temp > max) max = temp;
        trees.push_back(temp);
    }

    std::cout << binary_search(trees, max - 1, M);
    return 0;
}

int binary_search(std::vector<int>& trees, long long high, int target) {
    long long low = 1;
    while (low <= high) {
        long long mid = (low + high) / 2;
        long long earns = 0;
        for (int i = 0; i < trees.size(); ++i) {
            if (trees[i] - mid > 0) earns += trees[i] - mid;
        }

        if (earns >= target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return high;
}