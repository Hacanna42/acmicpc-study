// 백준: 문자열 폭발
// https://www.acmicpc.net/problem/9935
// 2024-01-21

/* 복잡하지만 쉬운 문제, 주요 로직은
방금 입력된 문자가 폭탄의 맨 마지막 문자와 일치하는지만 확인한다
일치하고, 지금까지 입력된 문자가 폭탄의 길이보다 길다면 폭탄 길이만큼
문자열을 제거하고 따로 빼놓는다, 이후 빼놓은 문자열과 폭탄 문자열을 검사한다.
일치한다면 냅두고, 일치하지 않는다면 다시 돌려놓는다.
이 과정에서 stack 특성상 문자열이 뒤집어지니까 std::reverse() 처리가 필요하다.
*/

#include <algorithm>
#include <iostream>
#include <stack>
#include <string>

int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::stack<char> stack;
    std::string str, bomb;
    std::cin >> str >> bomb;

    for (int i = 0; i < str.length(); ++i) {
        stack.push(str[i]);
        if (str[i] == bomb.back() && stack.size() >= bomb.length()) {
            std::string temp;
            for (int j = 0; j < bomb.length(); ++j) {
                temp.push_back(stack.top());
                stack.pop();
            }
            std::reverse(temp.begin(), temp.end());
            if (temp == bomb)
                continue;
            else {
                for (int j = 0; j < temp.length(); ++j) {
                    stack.push(temp[j]);
                }
            }
        }
    }

    std::string answer;
    answer.reserve(1000000);
    while (!stack.empty()) {
        answer.push_back(stack.top());
        stack.pop();
    }
    std::reverse(answer.begin(), answer.end());
    std::cout << (answer.empty() ? "FRULA" : answer);

    return 0;
}