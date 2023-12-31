// 백준: 수 정렬하기
// https://www.acmicpc.net/problem/2750
// 2023-12-31

#include <cstddef>
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int n;
    std::vector<int> list;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int temp;
        std::cin >> temp;
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
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i] << std::endl;
    }
    return 0;
}