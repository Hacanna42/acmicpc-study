// 백준: 상수
// https://www.acmicpc.net/problem/2908
// 2023-12-17

#TODO : reverse와 swap stoi 직접 구현해보기

#include <algorithm>
#include <iostream>
#include <string>
int main() {
    std::string a, b;
    std::cin >> a >> b;
    std::reverse(a.begin(), a.end());
    std::reverse(b.begin(), b.end());
    if (std::stoi(a) > std::stoi(b))
        std::cout << a;
    else
        std::cout << b;
    return 0;
}