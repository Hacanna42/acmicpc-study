// 백준: 그대로 출력하기
// https://www.acmicpc.net/problem/11718
// 2023-12-20

#include <iostream>
#include <vector>  // 배열의 크기를 알 수 없는 상황
int main() {
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }
    for (int i = 0; i < lines.size(); i++) {
        std::cout << lines[i] << std::endl;
    }
    return 0;
}