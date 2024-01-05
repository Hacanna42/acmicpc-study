// 백준: 인사성 밝은 곰곰이
// https://www.acmicpc.net/problem/25192
// 2024-01-05

#include <iostream>
#include <set>
#include <string>

int main() {
    int N;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::set<std::string> m;
    std::cin >> N;
    int count = 0;
    for (int i = 0; i < N; ++i) {
        std::string str;
        std::cin >> str;
        if (str == "ENTER") {
            m.clear();
        } else {
            if (m.find(str) == m.end()) {
                ++count;
                m.insert(str);
            }
        }
    }

    std::cout << count;

    return 0;
}