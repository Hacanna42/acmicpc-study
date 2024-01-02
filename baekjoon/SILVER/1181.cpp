// 백준: 단어 정렬
// https://www.acmicpc.net/problem/1181
// 2024-01-02

#include <algorithm>
#include <iostream>
#include <string>
#include <vector>

bool compare(const std::string& a, const std::string& b) {
    if (a.length() == b.length()) {
        return a < b;
    }
    return a.length() < b.length();
}
int main() {
    int N;
    std::vector<std::string> array;
    std::cin >> N;
    std::cin.ignore();
    for (int i = 0; i < N; ++i) {
        std::string temp;
        std::getline(std::cin, temp);
        array.push_back(temp);
    }

    std::sort(array.begin(), array.end(), compare);
    auto key = std::unique(array.begin(), array.end());
    array.erase(key, array.end());
    for (int i = 0; i < array.size(); ++i) {
        std::cout << array[i] << std::endl;
    }
    return 0;
}