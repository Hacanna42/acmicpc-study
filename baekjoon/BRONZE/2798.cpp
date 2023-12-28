// 백준: 블랙잭
// https://www.acmicpc.net/problem/2798
// 2023-12-28

#include <algorithm>
#include <iostream>
#include <vector>

/*
std::next_permutation() 은 주어진 배열에서 다음 사전 순 배열을 도출하는
함수이다. 구성 요소는 바꾸지 않고 주어진 조합으로 사전순으로 다음 조합을 찾는다.
bool 타입 배열을 하나 선언하고, 제일 뒤 3개를 true로 바꾸면 3개의 요소를
가졌지만 사전 순으로 제일 작은 배열이 된다.
*/

int main() {
    int n, max;
    std::cin >> n >> max;
    std::vector<int> cards(n);
    std::vector<bool> selected_cards(n);
    std::fill(selected_cards.end() - 3, selected_cards.end(), true);
    for (int i = 0; i < n; ++i) {
        std::cin >> cards[i];
    }

    int max_sum = 0;
    do {
        int current_sum = 0;
        for (int i = 0; i < n; ++i) {
            if (selected_cards[i]) {
                current_sum += cards[i];
            }
        }
        if (current_sum <= max) {
            max_sum = std::max(max_sum, current_sum);
        }
    } while (
        std::next_permutation(selected_cards.begin(), selected_cards.end()));

    std::cout << max_sum;
    return 0;
}