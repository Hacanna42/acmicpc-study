// 백준: 회사에 있는 사람
// https://www.acmicpc.net/problem/7785
// 2024-01-03

#include <iostream>
#include <map>
#include <string>

int main() {
    std::map<std::string, std::string> m;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(NULL);
    std::cout.tie(NULL);
    int N;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        std::string name, status;
        std::cin >> name >> status;
        m[name] = status;
    }

    for (auto iter = m.end(); iter != m.begin();) {
        --iter;
        if (iter->second == "enter") std::cout << iter->first << "\n";
    }

    return 0;
}