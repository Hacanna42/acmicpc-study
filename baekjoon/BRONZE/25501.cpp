// 백준: 재귀의 귀재
// https://www.acmicpc.net/problem/25501
// 2024-01-07

#include <stdio.h>
#include <string.h>

#include <iostream>
#include <string>

// code from baekjoon
int recursion(const char *s, int l, int r, int &count) {
    if (l >= r) {
        ++count;
        return 1;
    } else if (s[l] != s[r]) {
        ++count;
        return 0;
    } else {
        ++count;
        return recursion(s, l + 1, r - 1, count);
    }
}

int isPalindrome(const char *s, int &count) {
    return recursion(s, 0, strlen(s) - 1, count);
}

int main() {
    int N;
    std::ios_base::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    std::cin >> N;
    for (int i = 0; i < N; ++i) {
        int count = 0;
        std::string str;
        std::cin >> str;
        std::cout << isPalindrome(str.c_str(), count) << " " << count << "\n";
    }
}