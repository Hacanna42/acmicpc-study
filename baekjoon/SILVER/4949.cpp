// 백준: 균형잡힌 세상
// https://www.acmicpc.net/problem/4949
// 2024-01-04

#include <iostream>
#include <stack>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    while (true) {
        std::string line;
        std::getline(std::cin, line);
        std::stack<int> stack;
        bool bad = false;
        if (line.length() == 1 && line[0] == '.') break;
        for (int i = 0; i < line.length(); ++i) {
            // 소괄호나 대괄호 시작인 경우
            if (line[i] == '(' || line[i] == '[') {
                stack.push(line[i] == '(' ? 1 : 2);
            }
            // 소괄호나 대괄호 종료인 경우
            else if (line[i] == ')') {
                if (!stack.empty() && stack.top() == 1) {
                    stack.pop();
                } else {
                    bad = true;
                    break;
                }
            } else if (line[i] == ']') {
                if (!stack.empty() && stack.top() == 2) {
                    stack.pop();
                } else {
                    bad = true;
                    break;
                }
            }
        }
        if (stack.empty() && !bad)
            std::cout << "yes"
                      << "\n";
        else
            std::cout << "no"
                      << "\n";
    }
    return 0;
}