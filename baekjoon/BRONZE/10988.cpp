// 백준: 팰린드롬인지 확인하기
// https://www.acmicpc.net/problem/10988
// 2023-11-16

#include <iostream>
int main() {
    char str[101];
    int len = 0;
    std::cin.getline(str, 101);
    for (len = 0; str[len] != '\0'; ++len)
        ;
    for (int i = 0; i < len / 2; i++) {
        if (str[i] != str[(len - 1) - i]) {
            std::cout << "0";
            return 0;
        }
    }
    std::cout << "1";
    return 0;
}