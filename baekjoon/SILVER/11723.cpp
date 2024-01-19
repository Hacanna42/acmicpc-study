// 백준: 집합
// https://www.acmicpc.net/problem/11723
// 2024-01-19
// 미해결, 비트마스킹.. 배워야 돼

#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::set<int> set;
    int M, x;
    std::string command;

    std::cin >> M;
    for (int i = 0; i < M; ++i) {
        std::cin >> command;
        if (command == "add") {
            std::cin >> x;
            set.insert(x);
        } else if (command == "remove") {
            std::cin >> x;
            set.erase(x);
        } else if (command == "check") {
            std::cin >> x;
            std::cout << (set.count(x) ? 1 : 0) << std::endl;
        } else if (command == "toggle") {
            std::cin >> x;
            if (set.count(x)) {
                set.erase(x);
            } else {
                set.insert(x);
            }
        } else if (command == "all") {
            set.clear();
            for (int j = 1; j <= 20; ++j) {
                set.insert(j);
            }
        } else if (command == "empty") {
            set.clear();
        }
    }

    return 0;
}
