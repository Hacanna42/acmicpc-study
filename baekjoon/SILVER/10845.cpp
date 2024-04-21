// 백준: 큐
// https://www.acmicpc.net/problem/10845
// 2024-04-21

#include <iostream>
#include <queue>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    queue<int> q;
    int N;
    cin >> N;
    while (N--) {
        string s;
        cin >> s;
        if (s == "push") {
            int t;
            cin >> t;
            q.push(t);
        } else if (s == "pop") {
            if (q.empty())
                cout << "-1\n";
            else {
                cout << q.front() << "\n";
                q.pop();
            }
        } else if (s == "size") {
            cout << q.size() << "\n";
        } else if (s == "empty") {
            cout << (q.empty() ? "1\n" : "0\n");
        } else if (s == "front") {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.front() << "\n";
        } else if (s == "back") {
            if (q.empty())
                cout << "-1\n";
            else
                cout << q.back() << "\n";
        }
    }
    return 0;
}