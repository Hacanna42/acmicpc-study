// 백준: 커트라인
// https://www.acmicpc.net/problem/25305
// 2024-01-01

#include <iostream>
#include <utility>  //SWAP을 쓰기 위해서
#include <vector>

int main() {
    int N;
    int k;
    bool swapped;
    std::vector<int> list;
    std::cin >> N >> k;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }

    // 버블 소트
    for (int i = 0; i < N - 1; ++i) {
        swapped = false;
        for (int j = 0; j < N - i - 1; ++j) {
            if (list[j] > list[j + 1]) {
                std::swap(list[j], list[j + 1]);
                swapped = true;
            }
        }
        if (!swapped) break;
    }
    std::cout << list[N - k];
    return 0;
}