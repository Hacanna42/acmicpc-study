// 백준: 대표값2
// https://www.acmicpc.net/problem/2587
// 2023-12-31

#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    std::vector<int> list;
    int sum = 0;
    for (int i = 0; i < 5; i++) {
        int temp;
        std::cin >> temp;
        sum += temp;
        list.push_back(temp);
    }

    // 버블 소트
    bool swapped;
    for (size_t i = 0; i < list.size() - 1; i++) {
        swapped = false;
        for (size_t j = 0; j < list.size() - i - 1; j++) {
            if (list[j] > list[j + 1]) {
                // 위치 교환
                std::swap(list[j], list[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }

    std::cout << sum / 5 << std::endl;
    std::cout << list[2] << std::endl;

    return 0;
}