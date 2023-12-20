// 백준: A+B - 3
// https://www.acmicpc.net/problem/10950
// 2023-11-20

#include <iostream>
int main() {
    int n = 0;
    int a = 0;
    int b = 0;
    std::string buffer;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        std::cin >> a >> b;
        buffer += std::to_string(a + b);
        buffer += "\n";
    }
    std::cout << buffer;
}