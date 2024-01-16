// 백준: 랜선 자르기
// https://www.acmicpc.net/problem/1654
// 2024-01-16

#include <iostream>
#include <vector>

int binary_search(std::vector<int>& wires, long low, long high, int N);

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::vector<int> wires;
    int K, N;
    long max = 0;
    std::cin >> K >> N;
    for (int i = 0; i < K; ++i) {
        int temp;
        std::cin >> temp;
        if (temp > max) max = temp;
        wires.push_back(temp);
    }

    std::cout << binary_search(wires, 1, max, N) << std::endl;
    return 0;
}

int binary_search(std::vector<int>& wires, long low, long high, int target) {
    while (low <= high) {
        long mid = (low + high) / 2;
        int count = 0;
        for (int i = 0; i < wires.size(); ++i) {
            count += wires[i] / mid;
        }
        if (count >= target) low = mid + 1;
        if (count < target) high = mid - 1;
    }
    return high;
}