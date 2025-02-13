// 백준: 과일 탕후루
// https://www.acmicpc.net/problem/30804
// 2025-02-12
// 우테코 7기 파이팅!

#include <iostream>
#include <vector>
using namespace std;

int main() {
    int N;
    cin >> N; // 과일의 개수 N
    vector<int> tanghuru(N);
    for (int i = 0; i < N; ++i) {
        cin >> tanghuru[i];
    }

    return 0;
}