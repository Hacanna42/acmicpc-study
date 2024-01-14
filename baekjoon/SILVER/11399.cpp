// 백준: ATM
// https://www.acmicpc.net/problem/11399
// 2024-01-14

#include <algorithm>
#include <iostream>
#include <vector>
int main() {
    int N;
    std::vector<int> v;
    std::vector<int> prefix;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        v.push_back(temp);
    }

    std::sort(v.begin(), v.end());

    int sum = 0;
    for (const auto& iter : v) {
        sum += iter;
        prefix.push_back(sum);
    }

    sum = 0;
    for (const auto& iter : prefix) {
        sum += iter;
    }

    std::cout << sum;
    return 0;
}