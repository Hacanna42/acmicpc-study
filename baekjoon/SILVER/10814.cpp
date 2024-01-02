// 백준: 나이순 정렬
// https://www.acmicpc.net/problem/10814
// 2024-01-02

#include <algorithm>
#include <cstddef>
#include <iostream>
#include <string>
#include <vector>

bool compare(const std::pair<int, std::string>& a,
             const std::pair<int, std::string>& b) {
    return a.first < b.first;
}

int main() {
    int N;
    std::vector<std::pair<int, std::string> > v;
    std::cin >> N;
    for (size_t i = 0; i < N; ++i) {
        int age;
        std::string name;
        std::cin >> age;
        std::cin.ignore();
        std::getline(std::cin, name);
        v.push_back(std::make_pair(age, name));
    }
    // 병합 정렬 STL
    std::stable_sort(v.begin(), v.end(), compare);
    for (size_t i = 0; i < N; ++i) {
        std::cout << v[i].first << " " << v[i].second << "\n";
    }
    return 0;
}