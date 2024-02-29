#include <iostream>
#include <stack>
#include <vector>
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int N;
    cin >> N;
    vector<int> nums(N);
    vector<int> count(1'000'001, 0);
    vector<int> ngf(N, -1);
    stack<int> s;
    for (int i = 0; i < N; ++i) {
        int cur;
        cin >> cur;
        count[cur]++;
        nums[i] = cur;
    }

    for (int i = 0; i < N; ++i) {
        while (!s.empty() && count[nums[s.top()]] < count[nums[i]]) {
            ngf[s.top()] = nums[i];
            s.pop();
        }
        s.push(i);
    }

    for (auto &n : ngf) {
        cout << n << " ";
    }
    return 0;
}