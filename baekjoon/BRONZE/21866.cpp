// 백준: 추첨을 통해 커피를 받자
// https://www.acmicpc.net/problem/21866
// 2024-10-24

#include <iostream>
using namespace std;

int main() {
    int max_scores[] = {100, 100, 200, 200, 300, 300, 400, 400, 500};
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
        int N;
        cin >> N;
        sum += N;
        if (N > max_scores[i]) {
            cout << "hacker";
            return 0;
        }
    }
    cout << (sum >= 100 ? "draw" : "none");
    return 0;
}