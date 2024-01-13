// 백준: 동전 0
// https://www.acmicpc.net/problem/11047
// 2024-01-13

#include <iostream>
#include <vector>
std::vector<int> value;
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, price;
    std::cin >> N >> price;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        value.push_back(temp);
    }
    int i = value.size() - 1;
    int count = 0;
    while (price != 0) {
        // 나눠지면
        if (price / value[i] > 0) {
            count += price / value[i];
            price = price % value[i];
        } else
            --i;
    }
    std::cout << count;
    return 0;
}