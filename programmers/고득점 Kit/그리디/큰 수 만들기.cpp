#include <stack>
#include <string>
#include <vector>

using namespace std;

string solution(string number, int k) {
    stack<int> stack;
    string answer = "";
    stack.push(number[0] - '0');
    for (int i = 1; i < number.size(); ++i) {
        int next_num = number[i] - '0';
        while (!stack.empty() && stack.top() < next_num && k > 0) {
            stack.pop();
            --k;
        }
        stack.push(next_num);
    }

    while (k--) {
        stack.pop();
    }

    vector<int> v;
    while (!stack.empty()) {
        v.push_back(stack.top());
        stack.pop();
    }

    for (int i = v.size() - 1; i >= 0; --i) {
        answer += to_string(v[i]);
    }
    return answer;
}