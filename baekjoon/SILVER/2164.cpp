#include <iostream>
#include <queue>

int main() {
    int N;
    std::queue<int> queue;
    std::cin >> N;
    for (int i = 1; i <= N; ++i) {
        queue.push(i);
    }

    while (queue.size() != 1) {
        queue.pop();
        int temp = queue.front();
        queue.push(temp);
        queue.pop();
    }

    std::cout << queue.front();
    return 0;
}