// 백준: A -> B
// https://www.acmicpc.net/problem/16953
// 2024-01-27
// 클래스 풀이

#include <iostream>
#include <queue>
#include <utility>
int A, B;

int bfs() {
    std::queue<std::pair<int, int> > q;
    q.push({A, 1});

    while (!q.empty()) {
        long long current = q.front().first;
        long long op = q.front().second;
        q.pop();

        if (current == B) {
            std::cout << op;
            return 0;
        }

        long long next = current * 2;
        if (next <= B) q.push({next, op + 1});
        next = current * 10 + 1;
        if (next <= B) q.push({next, op + 1});
    }

    std::cout << "-1";
    return 0;
}

int main() {
    std::cin >> A >> B;
    bfs();
    return 0;
}