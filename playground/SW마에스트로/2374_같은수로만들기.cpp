#include <algorithm>
#include <iostream>
#include <stack>
using namespace std;
typedef long long ll;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    stack<int> s;
    ll total = 0;
    int max = 0;
    for (int i = 0; i < N; ++i) {
        int temp;
        cin >> temp;
        max = std::max(max, temp);
        if (s.empty()) {
            s.push(temp);
        } else {
            int prev = s.top();
            if (temp > prev) {
                total += temp - prev;
                s.pop();
                s.push(temp);
            } else if (temp < prev) {
                s.pop();
                s.push(temp);
            }
        }
    }

    while (!s.empty()) {
        int num = s.top();
        s.pop();
        total += max - num;
    }

    cout << total;
    return 0;
}