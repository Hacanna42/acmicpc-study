// 백준: 최소 힙
// https://www.acmicpc.net/problem/1927.cpp
// 2024-01-17

#include <functional>
#include <iostream>
#include <queue>
using namespace std;
std::priority_queue<int, vector<int>, greater<int>> pq;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        if (temp != 0)
            pq.push(temp);
        else {
            if (pq.empty())
                cout << "0"
                     << "\n";
            else {
                cout << pq.top() << "\n";
                pq.pop();
            }
        }
    }
    return 0;
}