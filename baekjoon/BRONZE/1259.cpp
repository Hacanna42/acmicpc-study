// 백준: 팰린드롬수
// https://www.acmicpc.net/problem/1259
// 2024-01-15

#include <iostream>
int main() {
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    char str[100000];
    while (true) {
        int len = 0;
        std::cin.getline(str, 100000);
        if (str[0] == '0') break;
        for (len = 0; str[len] != '\0'; ++len)
            ;
        bool is = true;
        for (int i = 0; i < len / 2; i++) {
            if (str[i] != str[(len - 1) - i]) {
                is = false;
                break;
            }
        }

        std::cout << (is ? "yes" : "no") << "\n";
    }
    return 0;
}