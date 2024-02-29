#include <iostream>
#include <stack>
#include <string>
#include <vector>
using namespace std;

stack<char> st;
int answer = 0;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string s;
    cin >> s;
    for (int i = 0; i < s.size(); ++i) {
        if (s[i] == '(') {
            st.push('(');
        } else {                   // ')' 라면
            if (s[i - 1] == '(') { // 바로 이전이 '(' 면 레이저
                st.pop();
                answer += st.size();
            } else {
                st.pop();
                answer += 1;
            }
        }
    }

    cout << answer;
    return 0;
}