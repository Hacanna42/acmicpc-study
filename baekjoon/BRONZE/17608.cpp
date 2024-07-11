// 백준: 막대기
// https://www.acmicpc.net/problem/17608
// 2024-07-11

#include <iostream>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    vector<int> arr;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int t;
        cin >> t;
        arr.push_back(t);
    }

    int answer = 0;
    int cur = 0;
    for (int i = N - 1; i >= 0; --i) {
        if (arr[i] > cur) {
            answer++;
            cur = arr[i];
        }
    }

    cout << answer;
    return 0;
}