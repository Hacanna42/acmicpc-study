// 백준: 세로읽기
// https://www.acmicpc.net/problem/10798
// 2023-12-20

// std::cin으로 벡터를 저정하고, 안전하게 접근하면서 출력
#include <iostream>
#include <string>
#include <vector>
int main() {
    std::vector<std::vector<char> >
        matrix;  // 행렬에 대한 크기를 알 수 없으므로 크기를 초기화하지 않음
    std::string line;
    int column = 0;
    while (std::getline(std::cin, line)) {
        matrix.push_back(std::vector<char>());
        for (int i = 0; i < line.length(); i++) {
            matrix[column].push_back(line[i]);
        }
        column++;
    }

    for (int row = 0; row < 15; row++) {  // 최대 15글자
        for (int column = 0; column < matrix.size(); column++) {
            if (matrix[column].size() > row) std::cout << matrix[column][row];
        }
    }

    return 0;
}