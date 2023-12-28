// 백준: 분해합
// https://www.acmicpc.net/problem/2231
// 2023-12-28

#include <iostream>
#include <sstream>
#include <string>

int main() {
    int n;
    int answer;
    bool is_answer_exist;
    std::string temp;
    std::cin >> n;
    for (int i = n / 2; i < n; ++i) {
        answer = 0;
        is_answer_exist = false;
        temp = std::to_string(i);
        int sum = 0;
        for (char c : temp) {
            sum += c - '0';
        }
        if (sum + i == n) {
            is_answer_exist = true;
            answer = i;
            break;
        }
    }
    if (is_answer_exist)
        std::cout << answer;
    else
        std::cout << "0";
    return 0;
}