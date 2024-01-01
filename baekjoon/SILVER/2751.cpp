// 백준: 수 정렬하기 2
// https://www.acmicpc.net/problem/2751
// 2024-01-01

#include <algorithm>  // 감사합니다
#include <iostream>
#include <utility>
#include <vector>

int main() {
    int N;
    std::vector<int> list;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        list.push_back(temp);
    }

    // algorithm.h의 sort는 퀵 삽입 힙 정렬 등을 복합적으로 알잘딱하게
    // 사용한다고 한다.
    std::sort(list.begin(), list.end());

    for (int i = 0; i < N; i++) {
        std::cout << list[i] << "\n";
    }
    return 0;
}
