// 백준: 스택
// https://www.acmicpc.net/problem/10828
// 2024-04-18
// C랑 병행

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int main() {
    stack<int> s;
    int N;
    cin >> N;
    for (int i = 0; i < N; ++i) {
        string t;
        cin >> t;
        if (t == "push") {
            int a;
            cin >> a;
            s.push(a);
        } else if (t == "pop") {
            if (!s.empty()) {
                printf("%d\n", s.top());
                s.pop();
            } else {
                printf("-1\n");
            }
        } else if (t == "size") {
            printf("%zu\n", s.size());
        } else if (t == "empty") {
            if (s.empty()) {
                printf("1\n");
            } else
                printf("0\n");
        } else if (t == "top") {
            if (!s.empty()) {
                printf("%d\n", s.top());
            } else {
                printf("-1\n");
            }
        }
    }
    return 0;
}