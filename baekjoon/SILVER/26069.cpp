// 백준: 붙임성 좋은 총총이
// https://www.acmicpc.net/problem/26069
// 2024-01-06

#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    int N;
    std::unordered_set<std::string> set;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    set.insert("ChongChong");
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::string first, second;
        std::cin >> first >> second;
        bool a = set.find(first) == set.end() ? false : true;
        bool b = set.find(second) == set.end() ? false : true;
        if (a && b) {
            // skip
        } else if (a)
            set.insert(second);
        else if (b)
            set.insert(first);
    }

    std::cout << set.size();
    return 0;
}