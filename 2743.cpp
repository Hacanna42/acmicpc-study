// 백준: 단어 길이 재기
// https://www.acmicpc.net/problem/2743
// 2023-11-10

#include <iostream>
#include <string>
int main() {
    char str[101];
    int n;
    std::cin.getline(str, 101);
    for (int i = 0; i < 101; i++) {
        if (str[i] == '\0') {
            std::cout << i;
            return 0;
        }
    }
    return 0;
}