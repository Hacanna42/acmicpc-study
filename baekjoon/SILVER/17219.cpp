// 백준: 비밀번호 찾기
// https://www.acmicpc.net/problem/17219
// 2024-01-19

#include <iostream>
#include <map>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::map<std::string, std::string> map;
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        std::string site, pwd;
        std::cin >> site >> pwd;
        map[site] = pwd;
    }
    for (int i = 0; i < M; ++i) {
        std::string site;
        std::cin >> site;
        std::cout << map[site] << "\n";
    }
    return 0;
}