// 백준: 나는야 포켓몬 마스터 이다솜
// https://www.acmicpc.net/problem/1620
// 2024-01-03

#include <iostream>
#include <sstream>
#include <string>
#include <unordered_map>

int main() {
    int N, M;
    std::unordered_map<std::string, int> m;
    std::unordered_map<int, std::string> m2;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        std::string name;
        std::cin >> name;
        m.insert({name, i + 1});
        m2.insert({i + 1, name});
    }
    for (int i = 0; i < M; ++i) {
        std::string key;
        int num;
        std::string str;
        std::cin >> key;
        std::istringstream iss(key);
        if (iss >> num && !(iss >> str)) {
            // 정수로만 구성
            std::cout << m2[num] << "\n";
        } else {
            // 정수가 아니면 (문자)
            std::cout << m[key] << "\n";
        }
    }
    return 0;
}