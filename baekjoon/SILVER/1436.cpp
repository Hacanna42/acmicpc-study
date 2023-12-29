// 백준: 영화감독 숌
// https://www.acmicpc.net/problem/1436
// 2023-12-29

#include <iostream>
#include <string>
int main() {
    int n;
    int i = 666;
    int counter = 0;
    std::cin >> n;
    while (true) {
        if (std::to_string(i).find("666") != std::string::npos) counter++;
        if (n == counter) {
            std::cout << i;
            break;
        }
        ++i;
    }
    return 0;
}