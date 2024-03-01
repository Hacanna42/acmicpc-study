#include <iostream>
#include <stack>
#include <string>
using namespace std;

/*
스택에 길이를 저장하자
*/
int total = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    string s;
    cin >> s;
    stack<int> st;
    for (int i = 0; i < s.size(); ++i) {
        char cur = s[i];
        if (cur == '(') {
            st.push(-1);
        } else if (cur == ')') {
            int len = 0;
            while (st.top() != -1) {
                len += st.top();
                st.pop();
            }
            st.pop(); // '(' 제거
            int temp = st.top();
            st.pop();
            st.push(temp * len);
        } else {
            if (i + 1 < s.size() && s[i + 1] == '(') // 만약 압축에 사용되는 정수라면
                st.push(cur - '0');
            else
                st.push(1);
        }
    }

    while (!st.empty()) {
        total += st.top();
        st.pop();
    }
    cout << total;
    return 0;
}