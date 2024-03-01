#include <algorithm>
#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

int main() {
    int N;
    string s;
    cin >> N >> s;
    stack<char> st;
    int result = 0;

    for (int i = 0; i < N; ++i) {
        if (st.empty()) {
            st.push(s[i]);
        } else {
            if (st.top() == '(' && s[i] == ')') {
                st.pop();
            } else if (st.top() == ')' && s[i] == '(') {
                st.pop();
            } else {
                st.push(s[i]);
            }
        }

        result = max(result, (int)st.size());
    }

    if (st.size() > 0)
        cout << "-1";
    else
        cout << result;
}