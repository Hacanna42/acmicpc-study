// 백준: queuestack
// https://www.acmicpc.net/problem/24511
// 2024-01-05

#include <deque>
#include <iostream>
#include <queue>

int main() {
    std::queue<int> queue;
    std::deque<int> deque;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);

    // 입력
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int is_q;
        std::cin >> is_q;
        if (is_q == 0) {
            queue.push(i);
        }
    }
    for (int i = 0; i < N; ++i) {
        int e;
        std::cin >> e;
        if (!queue.empty() && queue.front() == i) {
            deque.push_back(e);
            queue.pop();
        }
    }

    // Stack은 아무런 상태값도 변화하지 않기에 신경쓸 필요가 없다.
    // Queue를 거치면 자료를 삽입 후 원래 있던 자료를 꺼낸다.
    // 알고리즘
    int M;
    std::cin >> M;
    while (M--) {
        int insert;
        std::cin >> insert;
        deque.push_front(insert);
        std::cout << deque.back() << " ";
        deque.pop_back();
    }
    return 0;
}