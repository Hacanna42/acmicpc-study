// 백준: 서로 다른 부분 문자열의 개수
// https://www.acmicpc.net/problem/11478
// 2024-01-03

#include <iostream>
#include <string>
#include <unordered_set>

int main() {
    std::string str;
    std::unordered_set<std::string> substrings;
    std::cin >> str;
    for (int i = 0; i < str.length(); ++i) {
        for (int j = 1; i + j <= str.length(); ++j) {
            substrings.insert(str.substr(i, j));
        }
    }

    std::cout << substrings.size();
    return 0;
}