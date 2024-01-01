// 백준: 소트인사이드
// https://www.acmicpc.net/problem/1427
// 2024-01-01

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

int main() {
    std::string n_string;
    std::vector<int> list;
    int n;
    std::cin >> n_string;
    for (int i = 0; i < n_string.length(); ++i) {
        list.push_back(n_string[i] - '0');
    }

    std::sort(list.begin(), list.end(), std::greater<int>());
    for (int i = 0; i < list.size(); i++) {
        std::cout << list[i];
    }
    return 0;
}