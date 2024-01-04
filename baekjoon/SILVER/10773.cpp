// 백준: 제로
// https://www.acmicpc.net/problem/10773
// 2024-01-04

#include <iostream>
#include <stack>

int main() {
    std::stack<int> stack;
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        if (temp != 0)
            stack.push(temp);
        else
            stack.pop();
    }
    int sum = 0;
    while (!stack.empty()) {
        sum += stack.top();
        stack.pop();
    }
    std::cout << sum;
    return 0;
}