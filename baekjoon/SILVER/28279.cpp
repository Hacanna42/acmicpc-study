// 백준: 덱 2
// https://www.acmicpc.net/problem/28279
// 2024-01-04

#include <deque>
#include <iostream>

int main() {
    std::deque<int> deque;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int command;
        int temp;
        std::cin >> command;
        switch (command) {
            case 1:
                std::cin >> temp;
                deque.push_front(temp);
                break;
            case 2:
                std::cin >> temp;
                deque.push_back(temp);
                break;
            case 3:
                if (!deque.empty()) {
                    std::cout << deque.front() << "\n";
                    deque.pop_front();
                } else
                    std::cout << "-1\n";
                break;
            case 4:
                if (!deque.empty()) {
                    std::cout << deque.back() << "\n";
                    deque.pop_back();
                } else
                    std::cout << "-1\n";
                break;
            case 5:
                std::cout << deque.size() << "\n";
                break;
            case 6:
                std::cout << (deque.empty() ? "1" : "0") << "\n";
                break;
            case 7:
                std::cout << (deque.empty() ? -1 : deque.front()) << "\n";
                break;
            case 8:
                std::cout << (deque.empty() ? -1 : deque.back()) << "\n";
                break;
        }
    }
    return 0;
}