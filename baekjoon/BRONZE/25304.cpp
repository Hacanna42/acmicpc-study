// 백준: 영수증
// https://www.acmicpc.net/problem/25304
// 2023-11-30

#include <iostream>
// 힙을 써야 할 줄 알았는데, 아니었다.
int main() {
    int answer_price, n;
    int current_price = 0;
    std::cin >> answer_price >> n;

    for (int i = 0; i < n; i++) {
        int a, b;
        std::cin >> a >> b;
        current_price += a * b;
    }

    if (answer_price == current_price)
        std::cout << "Yes";
    else
        std::cout << "No";

    return 0;
}