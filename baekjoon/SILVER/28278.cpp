// 백준: 스택 2
// https://www.acmicpc.net/problem/28278
// 2024-01-04

#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        switch (temp) {
            case 1:
                int temp2;
                std::cin >> temp2;
                stack.push(temp2);
                break;
            case 2:
                if (!stack.empty()) {
                    std::cout << stack.top() << "\n";
                    stack.pop();
                } else
                    std::cout << "-1"
                              << "\n";
                break;
            case 3:
                std::cout << stack.size() << "\n";
                break;
            case 4:
                std::cout << (stack.empty() ? "1" : "0") << "\n";
                break;
            case 5:
                std::cout << (!stack.empty() ? stack.top() : -1) << "\n";
                break;
        }
    }
    return 0;
}