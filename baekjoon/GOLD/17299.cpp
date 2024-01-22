// 백준: 오등큰수
// https://www.acmicpc.net/problem/17299
// 2024-01-22

#include <iostream>
#include <stack>
#include <vector>

int main() {
    int N;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N;
    std::vector<int> ngf(N + 1, -1);
    std::vector<int> count(1000001, 0);
    std::vector<int> s(N + 1, 0);
    for (int i = 1; i <= N; ++i) {
        int temp;
        std::cin >> temp;
        s[i] = temp;
        count[temp]++;
    }
    std::stack<int> stack;
    for (int i = 1; i <= N; ++i) {
        while (!stack.empty() && count[s[stack.top()]] < count[s[i]]) {
            ngf[stack.top()] = s[i];
            stack.pop();
        }
        stack.push(i);
    }

    for (int i = 1; i <= N; ++i) {
        std::cout << ngf[i] << " ";
    }
    return 0;
}