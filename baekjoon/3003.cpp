// 백준: 킹, 퀸, 룩, 비숍, 나이트, 폰
// https://www.acmicpc.net/problem/3003

#include <iostream>
int main() {
    int chess_piece_value[6] = {1, 1, 2, 2, 2, 8};
    int input_value[6];
    int answer_value[6] = {0, 0, 0, 0, 0, 0};
    for (int i = 0; i < 6; i++) {
        std::cin >> input_value[i];
        answer_value[i] -= input_value[i] - chess_piece_value[i];
        // 출력 케이스, 맨 마지막 띄어쓰기 제거
        if (i == 5) {
            std::cout << answer_value[i] << std::endl;
            break;
        } else {
            std::cout << answer_value[i] << " ";
        }
    }
    return 0;
}