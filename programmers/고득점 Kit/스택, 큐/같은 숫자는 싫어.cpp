#include <algorithm>
#include <iostream>
#include <stack>
#include <vector>

/* 이걸 굳이 스택을 써야할까..? */
using namespace std;

vector<int> solution(vector<int> arr) {
    vector<int> answer;
    stack<int> stack;
    for (int i = 0; i < arr.size(); ++i) {
        if (!stack.empty()) {
            int last = stack.top();
            if (last != arr[i])
                stack.push(arr[i]);
        } else
            stack.push(arr[i]);
    }

    while (!stack.empty()) {
        answer.push_back(stack.top());
        stack.pop();
    }

    std::reverse(answer.begin(), answer.end());

    return answer;
}