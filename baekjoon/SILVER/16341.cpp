// 해결못함
// 번외 - 랜덤 디펜스
// 백준: Horsemeet
// https://www.acmicpc.net/problem/16341
// 2024-01-12

#include <cmath>
#include <iostream>
#include <vector>

// 나이트 이동 설정
const int nx[8] = {2, 2, -2, -2, 1, 1, -1, -1};
const int ny[8] = {1, -1, 1, -1, 2, -2, 2, -2};

// 확률 저장 메모
std::vector<std::vector<std::vector<std::vector<double>>>> memo(
    9,
    std::vector<std::vector<std::vector<double>>>(
        9, std::vector<std::vector<double>>(9, std::vector<double>(9, -1.0))));

double probablity(int x, int y, int to_x, int to_y) {
    // 만약 잡혔다면 확률을 1로 반환
    if (x == to_x && y == to_y) return 1.0;
    // 이미 고려됐다면 고려된 값 그대로 반환
    if (memo[x][y][to_x][to_y] != -1.0) return memo[x][y][to_x][to_y];

    memo[x][y][to_x][to_y] = 0.0;
    for (int i = 0; i < 8; ++i) {
        int knight_x = x + nx[i];
        int knight_y = y + ny[i];
        // 유효한 위치 확인
        if (knight_x <= 8 && knight_x >= 1 && knight_y <= 8 && knight_y >= 1) {
            memo[x][y][to_x][to_y] +=
                probablity(knight_x, knight_y, to_x, to_y) / 8.0;
        }
    }
    return memo[x][y][to_x][to_y];
}

int main() {
    int A, B, C, D;
    std::cin >> A >> B >> C >> D;
    double white = probablity(A, B, C, D);
    double black = probablity(C, D, A, B);

    std::cout << white << black;

    // if (abs(white - black) < 0.000001) {
    //     std::cout << "draw\n";
    // } else {
    //     std::cout << (white > black ? "white\n" : "black\n");
    // }
    return 0;
}