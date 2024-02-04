// 백준: 걸그룹 마스터 준석이
// https://www.acmicpc.net/problem/16165
// 2024-02-04

#include <algorithm>
#include <iostream>
#include <string>
#include <utility>
#include <vector>

std::vector<std::pair<std::string, std::string>> v;

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, M;
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        std::string team_name;
        int nums;
        std::cin >> team_name >> nums;
        for (int j = 0; j < nums; ++j) {
            std::string member_name;
            std::cin >> member_name;
            v.push_back({team_name, member_name});
        }
    }

    for (int i = 0; i < M; ++i) {
        std::string question;
        int temp;
        std::cin >> question >> temp;
        if (temp == 0) {
            std::vector<std::string> names;
            for (int i = 0; i < v.size(); ++i) {
                if (v[i].first == question) {
                    names.push_back(v[i].second);
                }
            }
            std::sort(names.begin(), names.end());
            for (int i = 0; i < names.size(); ++i) {
                std::cout << names[i] << "\n";
            }
        } else if (temp == 1) {
            for (int i = 0; i < v.size(); ++i) {
                if (v[i].second == question) {
                    std::cout << v[i].first << "\n";
                    break;
                }
            }
        }
    }
    return 0;
}