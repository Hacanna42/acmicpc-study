// 백준: 듣보잡
// https://www.acmicpc.net/problem/1764
// 2024-01-03

#include <iostream>
#include <map>
#include <string>
#include <vector>

int main() {
    int N, M;
    std::map<std::string, int> m;
    std::cin >> N >> M;
    for (int i = 0; i < N + M; ++i) {
        std::string name;
        std::cin >> name;
        m[name]++;
    }
    std::vector<std::string> v;
    int count = 0;
    for (const auto& pair : m) {
        if (pair.second >= 2) {
            ++count;
            v.push_back(pair.first);
        }
    }
    std::cout << count << "\n";
    for (const auto& iter : v) {
        std::cout << iter << "\n";
    }
    return 0;
}