// 백준: 스택 수열
// https://www.acmicpc.net/problem/1874
// 2024-04-24

/*
문제 지문이 불친절하다
*/

#include <iostream>
#include <queue>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    queue<int> goal;  // 목표 수열
    stack<int> st;    // 시뮬레이션 스택
    vector<char> log; // push, pop 기록 로그
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        goal.push(temp);
    }
    int index = 1;
    while (!goal.empty()) {
        // 스택의 맨 윗값이 현재 찾는 값인지 확인
        if (!st.empty() && st.top() == goal.front()) {
            goal.pop();
            st.pop();
            log.push_back('-');
        } else {
            st.push(index);
            log.push_back('+');
            ++index;
            if (index > N + 1) {
                cout << "NO";
                return 0;
            }
        }
    }

    for (const char &next : log) {
        cout << next << "\n";
    }

    return 0;
}