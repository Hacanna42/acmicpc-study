// 백준: 아이들과 선물 상자
// https://www.acmicpc.net/problem/23757
// 2024-03-04

#include <algorithm>
#include <functional>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M; // 선물 상자 N, 아이들 수 M
    cin >> N >> M;

    priority_queue<int, vector<int>, less<int>> pq;

    for (int i = 0; i < N; ++i) {
        int present_count;
        cin >> present_count;
        pq.push(present_count);
    }

    for (int i = 0; i < M; ++i) {
        int children_wants;
        cin >> children_wants;

        // 선물 상자가 이미 비어있다면 0 출력 후 종료
        if (pq.empty()) {
            cout << "0";
            return 0;
        }

        int present_left = pq.top();
        pq.pop();

        // 아이가 원하는 양보다 크거나 같은지 확인
        if (present_left > children_wants) {
            pq.push(present_left - children_wants);
        } else if (present_left < children_wants) {
            // 아이가 원하는 양보다 선물의 개수가 작으면 0 출력 후 종료
            cout << "0";
            return 0;
        }
    }

    // 모든 검사가 끝나면
    cout << "1";

    return 0;
}