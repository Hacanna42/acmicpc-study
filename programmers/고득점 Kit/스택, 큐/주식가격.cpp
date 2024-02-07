#include <queue>
#include <stack>
#include <string>
#include <utility>
#include <vector>

using namespace std;

/*
"가격이 떨어지지 않은 기간" 이라길래,
그 이후에 가격이 현재보다 낮았던 기간을 모두 세는 줄 알았는데,
사실은 처음으로 가격이 떨어졌을때까지의 기간이었네요,
그러면 "가격이 처음으로 떨어지지 않은 기간이 몇초인지" 라고 해야하는거 아닌가 ...
*/

vector<int> solution(vector<int> prices) {
    int n = prices.size();
    vector<int> answer(n);
    stack<int> s; // 인덱스를 저장할 스택

    for (int i = 0; i < n; ++i) {
        // 스택이 비어있지 않고, 현재 가격이 스택의 top에 있는 가격보다 낮으면
        while (!s.empty() && prices[s.top()] > prices[i]) {
            int top = s.top();
            s.pop();
            answer[top] = i - top; // 가격이 떨어진 시간 계산
        }
        s.push(i); // 현재 가격의 인덱스를 스택에 저장
    }

    // 스택에 남아 있는 가격들에 대해 처리
    while (!s.empty()) {
        int top = s.top();
        s.pop();
        answer[top] = n - 1 - top; // 가격이 떨어지지 않은 전체 시간 계산
    }
    return answer;
}