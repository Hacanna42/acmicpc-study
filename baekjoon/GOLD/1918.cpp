// 백준: 후위 표기식
// https://www.acmicpc.net/problem/1918
// 2024-05-21

#include <iostream>
#include <stack>
#include <string>
using namespace std;

int precedence(char op) {
    if (op == '+' || op == '-')
        return 1;
    if (op == '*' || op == '/')
        return 2;
    if (op == '(' || op == ')')
        return 3;
    return 0;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    string infix;
    cin >> infix;
    int SIZE = infix.length();
    string output;
    stack<char> operatorStack;
    for (int i = 0; i < SIZE; ++i) {
        char cur = infix[i];
        int priority = precedence(cur);
        /*
        출력 stack과 연산자 stack 사용
        1. 숫자, 변수 등은 출력 stack으로 바로 이동
        2. 연산자는 연산자 스택의 .top() 보다 우선순위가 클동안 .push. 이외 .top() 반복
        */
        if (priority == 0) { // 연산자 아님
            output.push_back(cur);
        } else {                                  // 연산자
            if (priority == 1 || priority == 2) { // + - * /
                if (operatorStack.empty())
                    operatorStack.push(cur);
                else {
                    while (!operatorStack.empty()) {
                        if (operatorStack.top() == '(')
                            break;
                        if (precedence(operatorStack.top()) < priority)
                            break;
                        output.push_back(operatorStack.top());
                        operatorStack.pop();
                    }
                    operatorStack.push(cur);
                }
            } else if (priority == 3) { // 괄호
                if (cur == '(')
                    operatorStack.push(cur);
                else {
                    while (!operatorStack.empty()) {
                        if (operatorStack.top() == '(') {
                            operatorStack.pop();
                            break;
                        }
                        output.push_back(operatorStack.top());
                        operatorStack.pop();
                    }
                }
            }
        }
    }

    // 스택 정리
    while (!operatorStack.empty()) {
        output.push_back(operatorStack.top());
        operatorStack.pop();
    }
    cout << output;
    return 0;
}