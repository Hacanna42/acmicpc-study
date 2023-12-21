// 백준: 진법 변환
// https://www.acmicpc.net/problem/2745
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
    std::string n;
    int answer = 0;
    int b;
    iss >> n >> b;
    for (int i = 0; i < n.length(); i++) {
        int holder = n.length() - 1 - i;
        if (n[i] >= '0' && n[i] <= '9') {
            answer += (n[i] - '0') * (static_cast<int>(pow(b, holder)));
        } else {
            answer += ((n[i] - 'A') + 10) * (static_cast<int>(pow(b, holder)));
        }
    }
    std::cout << answer;
    return 0;
}