// 백준: 셀프 넘버
// https://www.acmicpc.net/problem/4673
// 2024-01-30
// 업다운랜디 첫번째 도전

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int d(int n) {
    std::string str = std::to_string(n);

    int sum = 0;
    for (char c : str) {
        int number = c - '0';
        sum += number;
    }
    return n + sum;
}
int main() {
    std::vector<bool> selfNumbers(10001, true);
    for (int i = 1; i <= 10000; ++i) {
        int dn = d(i);
        if (dn <= 10000) selfNumbers[dn] = false;
    }

    for (int i = 1; i <= 10000; ++i) {
        if (selfNumbers[i]) {
            std::cout << i << "\n";
        }
    }
    return 0;
}