// 백준: 오아시스 재결합
// https://www.acmicpc.net/problem/3015
// 2024-01-22

#include <iostream>
#include <stack>
#include <utility>
#include <vector>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    int N;
    std::cin >> N;
    std::vector<int> mans(N, 0);
    for (int i = 0; i < N; ++i) {
        std::cin >> mans[i];
    }

    long long pairs = 0;
    std::stack<std::pair<int, int>> stack;
    for (int i = 0; i < N; ++i) {
        int count = 1;
        // 앞 사람이 나보다 키가 작거나 같으면 서로 볼 수 있다
        while (!stack.empty() && stack.top().first <= mans[i]) {
            pairs += stack.top().second;
            if (stack.top().first == mans[i]) {
                count += stack.top().second;
            }
            stack.pop();
        }
        if (!stack.empty()) {
            ++pairs;
        }

        stack.push(std::make_pair(mans[i], count));
    }

    std::cout << pairs;
    return 0;
}