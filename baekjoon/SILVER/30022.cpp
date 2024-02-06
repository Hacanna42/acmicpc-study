// 백준: 행사 준비
// https://www.acmicpc.net/problem/30022
// 2024-02-06

/* 그리디, (가격A - 가격B)의 절댓값을 내림차순 정렬
위에서부터 구매 */

#include <algorithm>
#include <cmath>
#include <iostream>
#include <utility>
#include <vector>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    int N, A, B;
    std::cin >> N >> A >> B;
    std::vector<std::pair<int, int>> prices; // A가격, B가격
    for (int i = 0; i < N; ++i) {
        int t1, t2;
        std::cin >> t1 >> t2;
        prices.push_back({t1, t2});
    }

    std::sort(prices.begin(), prices.end(), [](std::pair<int, int> &a, std::pair<int, int> &b) { return (std::abs(a.first - a.second) > std::abs(b.first - b.second)); });

    long long price = 0;
    for (const auto next : prices) {
        if (next.first == next.second) {
            price += next.first;
            if (A > 0)
                --A;
            else if (B > 0)
                --B;
        } else if (next.first > next.second) {
            // B의 값이 더 쌀 경우
            if (B != 0) {
                price += next.second;
                --B;
            } else {
                price += next.first;
                --A;
            }
        } else if (next.first < next.second) {
            // A의 값이 더  쌀 경우
            if (A != 0) {
                price += next.first;
                --A;
            } else {
                price += next.second;
                --B;
            }
        }
    }

    std::cout << price;

    return 0;
}