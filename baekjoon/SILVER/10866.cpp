// 백준: 덱
// https://www.acmicpc.net/problem/10866
// 2024-04-21

#include <deque>
#include <iostream>
#include <string>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    int N;
    cin >> N;
    deque<int> dq;
    while (N--) {
        string s;
        cin >> s;
        if (s == "push_front") {
            int t;
            cin >> t;
            dq.push_front(t);
        } else if (s == "push_back") {
            int t;
            cin >> t;
            dq.push_back(t);
        } else if (s == "pop_front") {
            if (dq.empty())
                cout << "-1\n";
            else {
                cout << dq.front() << "\n";
                dq.pop_front();
            }
        } else if (s == "pop_back") {
            if (dq.empty())
                cout << "-1\n";
            else {
                cout << dq.back() << "\n";
                dq.pop_back();
            }
        } else if (s == "size") {
            cout << dq.size() << "\n";
        } else if (s == "empty") {
            cout << (dq.empty() ? "1\n" : "0\n");
        } else if (s == "front") {
            if (dq.empty())
                cout << "-1\n";
            else
                cout << dq.front() << "\n";
        } else if (s == "back") {
            if (dq.empty())
                cout << "-1\n";
            else
                cout << dq.back() << "\n";
        }
    }
    return 0;
}