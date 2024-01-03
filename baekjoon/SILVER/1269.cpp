// 백준: 대칭 차집합
// https://www.acmicpc.net/problem/1269
// 2024-01-03

#include <algorithm>
#include <iostream>
#include <iterator>
#include <set>

/*
대칭 차집합 계산을 이중 포문으로 직접 구현할 수도 있지만.
algorithm STL에 비해 효율이 떨어진다.
*/

int main() {
    int N, M;
    std::set<int> s;
    std::set<int> s2;
    std::set<int> diffAB;
    std::set<int> diffBA;

    // 입력
    std::cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        int temp;
        std::cin >> temp;
        s.insert(temp);
    }
    for (int i = 0; i < M; ++i) {
        int temp;
        std::cin >> temp;
        s2.insert(temp);
    }

    // A - B, B - A 계산
    std::set_difference(s.begin(), s.end(), s2.begin(), s2.end(),
                        std::inserter(diffAB, diffAB.begin()));
    std::set_difference(s2.begin(), s2.end(), s.begin(), s.end(),
                        std::inserter(diffBA, diffBA.begin()));

    // 대칭 차집합 계산
    std::set<int> symmetricDiff;
    std::set_union(diffAB.begin(), diffAB.end(), diffBA.begin(), diffBA.end(),
                   std::inserter(symmetricDiff, symmetricDiff.begin()));

    std::cout << symmetricDiff.size();
    return 0;
}