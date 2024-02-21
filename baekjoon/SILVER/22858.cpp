// 백준: 원상 복구 (small)
// https://www.acmicpc.net/problem/22858
// 2024-02-21

#include <iostream>
#include <vector>
using namespace std;
int main() {
    int N, K; // 카드 개수 N, 섞은 횟수 K.
    cin >> N >> K;
    vector<int> S(N, 0);
    vector<int> D(N, 0);
    for (int i = 0; i < N; ++i) {
        cin >> S[i];
    }
    for (int i = 0; i < N; ++i) {
        cin >> D[i];
    }

    vector<int> n(N, 0);
    while (K--) {

        for (int i = 0; i < N; ++i) { // D에 대해 순회
            int start_index = D[i] - 1;
            int end_index = i;
            n[start_index] = S[end_index];
        }

        S = n;
    }

    for (int i = 0; i < N; ++i) {
        cout << S[i] << " ";
    }

    return 0;
}