// 백준: 수 찾기
// https://www.acmicpc.net/problem/1920
// 2024-01-16

#include <algorithm>
#include <iostream>
#include <vector>

bool binary_search(std::vector<int>& numbers, int low, int high, int target);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::vector<int> numbers;
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        numbers.push_back(temp);
    }

    std::sort(numbers.begin(), numbers.end());

    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int target;
        std::cin >> target;
        // 찾기
        std::cout << (binary_search(numbers, 0, numbers.size() - 1, target)
                          ? "1"
                          : "0")
                  << "\n";
    }
    return 0;
}

bool binary_search(std::vector<int>& numbers, int low, int high, int target) {
    while (low <= high) {
        int mid = (low + high) / 2;
        if (numbers[mid] == target) return true;
        if (numbers[mid] < target)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return false;
}