// 백준: 큐 2
// https://www.acmicpc.net/problem/18258
// 2024-01-04

#include <iostream>
#include <queue>
#include <string>

int main() {
    int N;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::queue<int> queue;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::string command;
        int temp;
        std::cin >> command;
        if (command == "push") {
            std::cin >> temp;
            queue.push(temp);
        } else if (command == "pop") {
            if (!queue.empty()) {
                std::cout << queue.front() << "\n";
                queue.pop();
            } else
                std::cout << "-1"
                          << "\n";
        } else if (command == "size") {
            std::cout << queue.size() << "\n";
        } else if (command == "empty") {
            std::cout << (queue.empty() ? "1" : "0") << "\n";
        } else if (command == "front") {
            std::cout << (queue.empty() ? -1 : queue.front()) << "\n";
        } else if (command == "back") {
            std::cout << (queue.empty() ? -1 : queue.back()) << "\n";
        }
    }
    return 0;
}