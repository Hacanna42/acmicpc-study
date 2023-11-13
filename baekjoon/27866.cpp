// 백준: 문자와 문자열
// https://www.acmicpc.net/problem/27866
// 2023-11-09

// C 스타일로 해결
// #include <iostream>
// #include <string>
// int main() {
//     char str[1001];
//     int n;
//     std::cin.getline(str, 1001);
//     std::cin >> n;
//     std::cout << str[n - 1];
// }

// std::string 사용해서 해결

#include <iostream>
#include <string>

int main() {
    int n;
    std::string str;
    std::getline(std::cin, str);
    std::cin >> n;
    std::cout << str[n - 1];
}
