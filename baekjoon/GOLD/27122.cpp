// 백준: 수 나누기 게임
// https://www.acmicpc.net/problem/27172
// 2024-06-13

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    vector<int> cards;
    vector<int> check(1'000'001, 0);
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        cards.push_back(t);
        check[t] = 1; // 누군가가 해당 카드를 가지고 있다고 체크
    }

    vector<int> scores(1'000'001, 0);
    // 각 플레이어의 카드 넘버의 배수를 각각 체크하면서 해당 카드가 있다면, 결투
    for (int i = 0; i < N; ++i) {
        for (int j = cards[i] * 2; j < 1'000'001; j += cards[i]) {
            if (check[j] == 1) {    // 누군가 카드를 가지고 있음
                scores[cards[i]]++; // 이 카드 갖고 있는 사람의 점수 +1
                scores[j]--;        // 나눠진 카드 갖고 있는 사람의 점수 -1
            }
        }
    }

    for (int i = 0; i < N; ++i) {
        cout << scores[cards[i]] << " ";
    }

    return 0;
}