// 백준: 문자열 반복
// https://www.acmicpc.net/problem/2675
// 2023-12-13

#include <iostream>
#include <string>
int main() {
    int n;
    std::cin >> n;
    for (int i = 0; i < n; i++) {
        int repeat;
        std::string what;
        std::cin >> repeat >> what;
        for (int j = 0; j < what.size(); j++) {
            for (int k = 0; k < repeat; k++) {
                std::cout << what[j];
            }
        }
        std::cout << std::endl;
    }
    return 0;
}