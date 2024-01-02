// 백준: 문자열 집합
// https://www.acmicpc.net/problem/14425
// 2024-01-02

#include <iostream>
#include <string>
#include <unordered_map>

int main() {
    int N, M;
    int count = 0;
    std::unordered_map<std::string, int> maps;
    std::cin >> N >> M;
    std::cin.ignore();
    for (int i = 0; i < N; ++i) {
        std::string temp;
        std::getline(std::cin, temp);
        maps[temp] = 1;
    }
    for (int i = 0; i < M; ++i) {
        std::string temp;
        std::getline(std::cin, temp);
        if (maps[temp]) ++count;
    }
    std::cout << count;
    return 0;
}