#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> nge(N);
    stack<int> s;
    vector<int> nums(N);
    for (int i = 0; i < N; ++i) {
        int cur;
        cin >> cur;
        nums[i] = cur;
        while (1) {
            if (s.empty()) {
                s.push(i);
                break;
            }

            int idx = s.top();
            if (cur > nums[idx]) { // 만약 현재가 이전보다 크면
                nge[idx] = cur;
                s.pop();
            } else {
                s.push(i);
                break;
            }
        }
    }

    // 남아있는건 모두 -1
    while (!s.empty()) {
        int idx = s.top();
        nge[idx] = -1;
        s.pop();
    }

    for (auto &n : nge) {
        cout << n << " ";
    }
    return 0;
}