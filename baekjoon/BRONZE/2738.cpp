// 백준: 행렬 덧셈
// https://www.acmicpc.net/problem/2738
// 2023-12-20

// int n, m 입력받고 n*2 만큼 getline()
// for문돌리면서 행렬에 입력
// for문 돌리면서 계산 후 출력

#include <iostream>
#include <sstream>
#include <string>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;
    std::cin.ignore();
    std::vector<std::vector<int> > matrix(n, std::vector<int>(m));
    std::vector<std::vector<int> > matrix2(n, std::vector<int>(m));
    std::vector<std::vector<int> > answer(n, std::vector<int>(m));
    std::vector<std::string> lines;
    std::string line;
    while (std::getline(std::cin, line)) {
        lines.push_back(line);
    }
    // 첫번째 행렬 입력 0 1 2
    for (int i = 0; i < n; i++) {
        std::stringstream ss(lines[i]);
        int value = 0;
        int j = 0;
        while (ss >> value) {
            matrix[i][j] = value;
            j++;
        }
    }
    // 두번째 행렬 입력
    for (int i = n; i < n * 2; i++) {
        std::stringstream ss(lines[i]);
        int value = 0;
        int j = 0;
        while (ss >> value) {
            matrix2[i - n][j] = value;
            j++;
        }
    }

    // 두 행렬 합 계산
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            answer[i][j] = matrix[i][j] + matrix2[i][j];
        }
    }

    // 계산된 행렬의 값 서식에 맞게 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << answer[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}

/* 행렬 입력 과정을 std::getline과 std::stringstream 대신 바로 std::cin으로 입력
받으면 코드를 간소화시킬 수 있었다.
덧셈 결과를 저장하기 위핸 행렬을 새로 선언하지 않고, 바로 출력했다면 메모리를
아낄 수 있었다.


개선 코드
#include <iostream>
#include <vector>

int main() {
    int n, m;
    std::cin >> n >> m;

    std::vector<std::vector<int>> matrix(n, std::vector<int>(m));
    std::vector<std::vector<int>> matrix2(n, std::vector<int>(m));

    // 첫번째 행렬 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix[i][j];
        }
    }

    // 두번째 행렬 입력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cin >> matrix2[i][j];
        }
    }

    // 두 행렬 합 바로 계산 및 출력
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            std::cout << matrix[i][j] + matrix2[i][j] << " ";
        }
        std::cout << std::endl;
    }

    return 0;
}
*/