// 백준: 괄호
// https://www.acmicpc.net/problem/9012
// 2024-01-04

#include <iostream>
#include <stack>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::stack<int> stack;
        std::string str;
        bool bad = false;
        std::cin >> str;
        for (int j = 0; j < str.length(); ++j) {
            if (str[j] == '(')
                stack.push(1);
            else if (str[j] == ')' && !stack.empty())
                stack.pop();
            else {
                bad = true;
                break;
            }
        }
        if (!stack.empty() || bad)
            std::cout << "NO"
                      << "\n";
        else
            std::cout << "YES"
                      << "\n";
    }
    return 0;
}