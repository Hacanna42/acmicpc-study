// 백준: 진법 변환 2
// https://www.acmicpc.net/problem/11005
// 2023-12-21

#include <cmath>  // 제곱을 직접 구현하고 싶다면 반복문을 통해 구현하는데, 어떤수의 0제곱은 항상 1이라는 점을 유념해야 함.
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    std::string line;
    std::getline(std::cin, line);
    std::istringstream iss(line);
    std::vector<char> answer;
    int n, b;
    iss >> n >> b;
    while (n != 0) {
        int remainder = n % b;
        if (remainder < 10)
            answer.push_back('0' + remainder);
        else
            answer.push_back('A' + (remainder - 10));
        n = n / b;
    }

    for (int i = answer.size() - 1; i >= 0; i--) {
        std::cout << answer[i];
    }
    return 0;
}