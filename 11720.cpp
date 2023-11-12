// 백준: 숫자의 합
// https://www.acmicpc.net/problem/11720
// 2023-11-12

#include <iostream>
int main() {
    int n;
    int answer = 0;
    std::cin >> n;
    char *str = new char[n + 1];
    std::cin >> str;
    for (int i = 0; i < n; i++) {
        answer += str[i] - '0';
    }

    std::cout << answer << std::endl;
    delete[] str;
    return 0;
}