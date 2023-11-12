// 백준: 문자열
// https://www.acmicpc.net/problem/9086
// 2023-11-11

#include <iostream>
#include <limits>  // std::numeric_limits를 사용하기 위해 추가
int main() {
    int testCase;
    std::string buffer;
    std::cin >> testCase;
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');

    for (int i = 0; i < testCase; i++) {
        char str[1001];
        std::cin.getline(str, 1001);
        for (int j = 0; j < 1000; j++) {
            if (str[j] == '\0') {
                buffer += str[0];
                buffer += str[j - 1];
                buffer += "\n";
                break;
            }
        }
    }
    std::cout << buffer;
    return 0;
}