// 백준: 좌표 압축
// https://www.acmicpc.net/problem/18870
// 2024-01-02

#include <algorithm>
#include <iostream>
#include <unordered_map>
#include <vector>

/*
좌표 압축이란 그냥 좌표를 오름차순서대로 0부터 정렬한 값
sort -> unique -> erase 처리하고 map에 key value로 어떤 값이 몇번째 순서인지
저장한다음 원본 vector와 비교하면서 풀면 된다.
*/

int main() {
    int N;
    std::unordered_map<int, int> map;
    std::vector<int> v;
    std::vector<int> v_bak;
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        v.push_back(temp);
        v_bak.push_back(temp);
    }

    std::sort(v.begin(), v.end());
    auto key = std::unique(v.begin(), v.end());
    v.erase(key, v.end());

    for (size_t i = 0; i < v.size(); ++i) {
        map[v[i]] = i;
    }

    for (size_t i = 0; i < N; ++i) {
        std::cout << map[v_bak[i]] << " ";
    }
    return 0;
}