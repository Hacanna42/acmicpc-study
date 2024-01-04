#include <iostream>
#include <queue>

int main() {
    int a, b;
    std::queue<int> queue;
    std::cin >> a >> b;
    for (int i = 1; i <= a; ++i) {
        queue.push(i);
    }

    // 계산
    std::cout << "<";
    for (int i = 0; i < a; ++i) {
        for (int j = 1; j < b; ++j) {
            int temp = queue.front();
            queue.push(temp);
            queue.pop();
        }
        std::cout << queue.front() << (i != a - 1 ? ", " : "");
        queue.pop();
    }
    std::cout << ">";
    return 0;
}